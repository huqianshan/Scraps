# %%
import os
import json
import csv
import io
import glob


"""
this file contains two methods to convert json to csv which are generated by the fio test in zns ssd: 
1.  the first one uses recursive method to convert all items in json to csv,but it cause data incorrect,buggy!!!
2. the second one uses a simple method to manually select the items in json to convert to csv, it works well.
"""
# %%
##
# Convert to string keeping encoding in mind...
##
def to_string(s):
    try:
        return str(s)
    except:
        #Change the encoding type if needed
        return s.encode('utf-8')
    

##
# This function converts an item like 
# {
#   "item_1":"value_11",
#   "item_2":"value_12",
#   "item_3":"value_13",
#   "item_4":["sub_value_14", "sub_value_15"],
#   "item_5":{
#       "sub_item_1":"sub_item_value_11",
#       "sub_item_2":["sub_item_value_12", "sub_item_value_13"]
#   }
# }
# To
# {
#   "node_item_1":"value_11",
#   "node_item_2":"value_12",
#   "node_item_3":"value_13",
#   "node_item_4_0":"sub_value_14", 
#   "node_item_4_1":"sub_value_15",
#   "node_item_5_sub_item_1":"sub_item_value_11",
#   "node_item_5_sub_item_2_0":"sub_item_value_12",
#   "node_item_5_sub_item_2_0":"sub_item_value_13"
# }
##
def reduce_item(key, value):
    global reduced_item
    
    #Reduction Condition 1
    if type(value) is list:
        i=0
        for sub_item in value:
            reduce_item(key+'_'+to_string(i), sub_item)
            i=i+1

    #Reduction Condition 2
    elif type(value) is dict:
        sub_keys = value.keys()
        for sub_key in sub_keys:
            reduce_item(key+'_'+to_string(sub_key), value[sub_key])
    
    #Base Condition
    else:
        reduced_item[to_string(key)] = to_string(value)


def process_file(json_file_path,csv_file_path,node="jobs"):
        #Reading arguments

        with io.open(json_file_path, 'r', encoding='utf-8-sig') as fp:
            print("Reading JSON file: {0}".format(json_file_path))
            json_value = fp.read()
            raw_data = json.loads(json_value)
        
        try:
            data_to_be_processed = raw_data[node]
        except:
            data_to_be_processed = raw_data

        processed_data = []
        header = []
        for item in data_to_be_processed:
            global reduced_item
            reduced_item = {}
            reduce_item(node, item)

            header += reduced_item.keys()

            processed_data.append(reduced_item)

        header = list(set(header))
        header.sort()

        with open(csv_file_path, 'a+') as f:
            writer = csv.DictWriter(f, header, quoting=csv.QUOTE_ALL)
            global flag
            if flag==False:
                writer.writeheader()
                flag=True
            for row in processed_data:
                writer.writerow(row)

        print ("Just completed writing csv file with %d columns" % len(header))

#%% 
"""
old method api iomode_dict
"""
import matplotlib.pyplot as plt
import pandas as pd

io_mode='psync'
# io_mode='libaio'
iomode_dict={'psync':'jobs_job options_numjobs','libaio':'jobs_job options_iodepth'}
# rw_mode='randread'
rw_mode='write'

def get_data(df, x_label,y_label="jobs_write_bw_mean"):
    smode=(df['jobs_job options_ioengine']==io_mode)
    rwmode=(df['jobs_job options_rw']==rw_mode)
    xmode=(df['jobs_job options_bs']==x_label)
    data = df[(smode) & (rwmode) & (xmode)]
    data.loc[:,iomode_dict[io_mode]]=data[iomode_dict[io_mode]].astype(int)
    data.loc[:, y_label] = (data[y_label].astype(float)) /1024
    return data.sort_values(by=iomode_dict[io_mode])

file=f'./data/fio_{filename}.csv'
df = pd.read_csv(file)
x_labels = ['4K', '8K', '16K','32K','64K','128K']#,'256K','512K','1M'
ylabel="jobs_write_bw"
# ylabel="jobs_write_iops"
# ylabel="jobs_read_bw"
# ylabel="jobs_read_iops"
markers = ['o-', 'D-', 'v-', 's-', 'p-', 'h-','o-','D-','v-']
data_dict = {label: get_data(df, label,ylabel) for label in x_labels}

plt.style.use('seaborn-paper')
plt.figure(figsize=(5,3))
for label, marker in zip(x_labels, markers):
    data = data_dict[label]
    # plt.plot(data['jobs_job options_iodepth'].to_list(), data[ylabel].to_list(), marker, label=label)
    plt.plot(data[iomode_dict[io_mode]].to_list(), data[ylabel].to_list(), marker, label=label)

plt.xlabel("concurrency",fontsize=12)
plt.ylabel(ylabel.replace('jobs_',""),fontsize=12)
# filename='nvme2n2'
title=f'{filename} {ylabel.replace("jobs_","")} with {io_mode}'
plt.title(title,fontsize=15)
plt.xticks(data_dict['4K'][iomode_dict[io_mode]].to_list(),fontsize=11)  # 设置x轴的刻度为数据
plt.yticks(fontsize=12)  # 设置y轴的刻度为数据
plt.legend(fontsize=12,ncol=2)
plt.savefig(f"./pics/{title.replace(' ','_')}.png",dpi=300,bbox_inches='tight')
plt.show()

# %%
def process_file_select(file_name,new_file):
    # new_file=file_name.replace(".json",".csv")
    with open(file_name,) as f:
        data = json.load(f)
        # print(type(data))
        # df=pd.read_json(file_name)
        # df.to_csv(new_file)
        with open(new_file,"a+") as final:
            for job in data['jobs']:
                # if Workload!=job["jobname"]:
                    # if Workload!="sad":
                        # final.write(Workload+","+str(MB_s)+","+str(IOPS)+"\n")
                    # MB_s,IOPS,lastjob=0,0,job["jobname"]

                # if job["read"]["runtime"]!=0:
                    # READ_MB+=job["read"]["io_kbytes"]/job["read"]["runtime"]/1.024
                READ_MB=str(job["read"]["bw"])
                READ_IOPS=str(job["read"]["iops"])
                WRITE_MB=str(job["write"]["bw"])
                WRITE_IOPS=str(job["write"]["iops"])
                Workload=job["job options"]["name"]
                Ioengine=job["job options"]["ioengine"]
                Mode=job["job options"]["rw"]
                Bs=job["job options"]["bs"]
                Depth=job["job options"]["iodepth"]
                Jobs=job["job options"]["numjobs"]

                final.write(Workload+","+Ioengine+","+Mode+","+Bs+","+Jobs+","+Depth+","+WRITE_MB+","+WRITE_IOPS+","+READ_MB+","+READ_IOPS+"\n")
                # if job["write"]["runtime"]!=0:
                    # MB_s+=job["write"]["io_kbytes"]/job["write"]["runtime"]/1.024
                # IOPS+=job["write"]["iops"]+job["read"]["iops"]
            
# if __name__ == "__main__":
filename='nvme2n2-3'
def process_directory(directory):
    json_files = glob.glob(os.path.join(directory, '*.json'))
    json_files.sort()

    new_file=os.path.join(directory,f"fio_{filename}.csv")
    
    with open(new_file,"w+") as final:
        # write header
        final.write("Workload,Ioengine,Mode,BlockSize,Numjobs,IODepth,WRITE_BW,WRITE_IOPS,READ_BW,READ_IOPS\n")

    for json_file in json_files:
        process_file_select(json_file,new_file)

reduced_item={}
flag=False
process_directory('./data/')

# %%
import matplotlib.pyplot as plt
import pandas as pd

io_mode='psync'
# io_mode='libaio'
iomode_dict={'psync':'Numjobs','libaio':'IODepth'}
# rw_mode='randread'
rw_mode='write'
filename='nvme2n2-4'
def get_data(df, x_label,y_label="jobs_write_bw_mean"):
    smode=(df['Ioengine']==io_mode)
    rwmode=(df['Mode']==rw_mode)
    xmode=(df['BlockSize']==x_label)
    data = df[(smode) & (rwmode) & (xmode)]
    data.loc[:,iomode_dict[io_mode]]=data[iomode_dict[io_mode]].astype(int)
    data.loc[:, y_label] = (data[y_label].astype(float)) /1024
    return data.sort_values(by=iomode_dict[io_mode])

file=f'./data/fio_{filename}.csv'
df = pd.read_csv(file)
x_labels = ['4K', '8K', '16K','32K','64K','128K']#,'256K','512K','1M']
ylabel="WRITE_BW"
# ylabel="WRITE_IOPS"
# ylabel="READ_BW"
# ylabel="READ_IOPS"
markers = ['o-', 'D-', 'v-', 's-', 'p-', 'h-','o-','D-','v-']
data_dict = {label: get_data(df, label,ylabel) for label in x_labels}

plt.style.use('seaborn-paper')
plt.figure(figsize=(5,3))
for label, marker in zip(x_labels, markers):
    data = data_dict[label]
    # plt.plot(data['jobs_job options_iodepth'].to_list(), data[ylabel].to_list(), marker, label=label)
    plt.plot(data[iomode_dict[io_mode]].to_list(), data[ylabel].to_list(), marker, label=label)

plt.xlabel("concurrency",fontsize=12)
plt.ylabel(ylabel.replace('jobs_',""),fontsize=12)

title=f'{filename} {ylabel} with {io_mode}'
plt.title(title,fontsize=15)
plt.xticks(data_dict['4K'][iomode_dict[io_mode]].to_list(),fontsize=11)  # 设置x轴的刻度为数据
plt.yticks(fontsize=12)  # 设置y轴的刻度为数据
plt.legend(fontsize=12,ncol=2)
plt.savefig(f"./pics/{title.replace(' ','_')}.png",dpi=300,bbox_inches='tight')
plt.show()

# %%
import matplotlib.pyplot as plt

# 数据
labels = ['KVPairs', 'B+TreeIndex', 'FileSystem:Ext4', 'SSD:P4510@2TB']
values = [64, 3912.58, 7715.17, 13887.306]
amplifs = [values[i] / values[0] if i != 0 else 1 for i in range(len(values))]

# 绘制柱状图
plt.figure(figsize=(6, 4))
plt.style.use('seaborn-paper')
hatches = ['/', '//', '///', '////']  # 定义条纹样式
# bars = plt.bar(labels, values,color=['#F9F7C9', '#D5F0C1', '#AAD9BB', '#80BCBD'])
#,color=['#F9F7C9', '#FDE767', '#F3B95F', '#D04848'],hatch='//'
bars = plt.bar(labels, values,color="white",edgecolor="black")

# 在每个柱子上# 在每个柱子上添加文字标签，并在两个柱子之间添加一个符号
# for i, (bar, amplif) in enumerate(zip(bars, amplifs)):
    # yval = bar.get_height()
    # plt.text(bar.get_x() + bar.get_width()/2, yval + 0.05, f"X{amplif:.1f}", ha='center', va='bottom')
    # if i > 0:
        # prev_bar = bars[i - 1]
        # prev_yval = prev_bar.get_height()
        # plt.annotate("", xy=(prev_bar.get_x() + prev_bar.get_width()/2, prev_yval), xytext=(bar.get_x() + bar.get_width()/2, yval), arrowprops=dict(arrowstyle="<-->"))
        # plt.text((prev_bar.get_x() + bar.get_x() + bar.get_width())/2, (prev_yval + yval)/2, f"{yval / prev_yval:.1f}", ha='center', va='center')
for i, (bar, amplif) in enumerate(zip(bars, amplifs)):
    yval = bar.get_height()
    plt.text(bar.get_x() + bar.get_width()/2, yval + 0.05, f"X{amplif:.1f}", ha='center', va='bottom')
    bar.set_hatch(hatches[i])  # 设置条纹样式

# plt.xlabel(fontsize=14)
# plt.xticks(range(len(labels)), labels, fontsize=10)  # 设置x轴的刻度标签和它们的字体大小
plt.ylabel('Write Traffic/MB',fontsize=14)
plt.title('The Write Amplification of B+Tree Index on Traditional SSD',fontsize=16)
plt.show()
# %%
