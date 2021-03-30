# %%
import matplotlib.cm as cm
import pandas as pd
import seaborn as sns
import numpy as np
import matplotlib.pyplot as plt


# %%
def myplot(data, name):
    time = data[:, 0]
    snd_cwd = data[:, 1]
    ssthresh = data[:, 2]
    plt.figure(figsize=(24, 4))
    plt.plot(time, snd_cwd, 'b-', label='snd_cwnd')
    plt.plot(time, ssthresh, 'g-', label='ssthresh')
    plt.ylabel('some numbers')
    plt.legend(loc='upper center', shadow=True, fontsize='x-large')
    plt.title(name)
    plt.xticks(np.arange(0, 10, step=0.5))
    fullname = write_dir+"\\"+name
    print(fullname)
    fullname = fullname.replace("txt", "png")
    plt.savefig(fullname, dpi=400)
    plt.show()


# %%
# make up some fake data
pos_mut_pcts = np.array([20, 10, 5, 7.5, 30, 50])
pos_cna_pcts = np.array([10, 0, 0, 7.5, 10, 0])
pos_both_pcts = np.array([10, 0, 0, 0, 0, 0])
neg_mut_pcts = np.array([10, 30, 5, 0, 10, 25])
neg_cna_pcts = np.array([5, 0, 7.5, 0, 0, 10])
neg_both_pcts = np.array([0, 0, 0, 0, 0, 10])


genes = ['PIK3CA', 'PTEN', 'CDKN2A', 'FBXW7', 'KRAS', 'TP53']

with sns.axes_style("white"):
    sns.set_style("ticks")
    sns.set_context("talk")

    # plot details
    bar_width = 0.35
    epsilon = .015
    line_width = 1
    opacity = 0.7
    pos_bar_positions = np.arange(len(pos_mut_pcts))
    # neg_bar_positions = pos_bar_positions + bar_width
    neg_bar_positions = pos_bar_positions

    # make bar plots
    hpv_pos_mut_bar = plt.bar(pos_bar_positions, pos_mut_pcts, bar_width,
                              color='#ED0020',
                              label='HPV+ Mutations')
    hpv_pos_cna_bar = plt.bar(pos_bar_positions, pos_cna_pcts, bar_width-epsilon,
                              bottom=pos_mut_pcts,
                              alpha=opacity,
                              color='white',
                              edgecolor='#ED0020',
                              linewidth=line_width,
                              hatch='//',
                              label='HPV+ CNA')
    hpv_pos_both_bar = plt.bar(pos_bar_positions, pos_both_pcts, bar_width-epsilon,
                               bottom=pos_cna_pcts+pos_mut_pcts,
                               alpha=opacity,
                               color='white',
                               edgecolor='#ED0020',
                               linewidth=line_width,
                               hatch='0',
                               label='HPV+ Both')
    hpv_neg_mut_bar = plt.bar(neg_bar_positions, neg_mut_pcts, bar_width,
                              color='#0000DD',
                              label='HPV- Mutations')
    hpv_neg_cna_bar = plt.bar(neg_bar_positions, neg_cna_pcts, bar_width-epsilon,
                              bottom=neg_mut_pcts,
                              color="white",
                              hatch='//',
                              edgecolor='#0000DD',
                              ecolor="#0000DD",
                              linewidth=line_width,
                              label='HPV- CNA')
    hpv_neg_both_bar = plt.bar(neg_bar_positions, neg_both_pcts, bar_width-epsilon,
                               bottom=neg_cna_pcts+neg_mut_pcts,
                               color="white",
                               hatch='0',
                               edgecolor='#0000DD',
                               ecolor="#0000DD",
                               linewidth=line_width,
                               label='HPV- Both')

    neg_bar_positions = pos_bar_positions + bar_width
    pos_mut_pcts = np.array([2, 1, 35, 15, 20, 10])
    pos_cna_pcts = np.array([10, 0, 0, 7.5, 10, 0])
    pos_both_pcts = np.array([10, 0, 0, 0, 0, 0])
    neg_mut_pcts = np.array([10, 30, 5, 0, 10, 25])
    neg_cna_pcts = np.array([5, 0, 7.5, 0, 0, 10])
    neg_both_pcts = np.array([0, 0, 0, 0, 0, 10])
    hpv_pos_mut_bar = plt.bar(pos_bar_positions, pos_mut_pcts, bar_width,
                              color='#ED0020',
                              label='HPV+ Mutations')
    hpv_pos_cna_bar = plt.bar(pos_bar_positions, pos_cna_pcts, bar_width-epsilon,
                              bottom=pos_mut_pcts,
                              alpha=opacity,
                              color='white',
                              edgecolor='#ED0020',
                              linewidth=line_width,
                              hatch='//',
                              label='HPV+ CNA')
    hpv_pos_both_bar = plt.bar(pos_bar_positions, pos_both_pcts, bar_width-epsilon,
                               bottom=pos_cna_pcts+pos_mut_pcts,
                               alpha=opacity,
                               color='white',
                               edgecolor='#ED0020',
                               linewidth=line_width,
                               hatch='0',
                               label='HPV+ Both')
    hpv_neg_mut_bar = plt.bar(neg_bar_positions, neg_mut_pcts, bar_width,
                              color='#0000DD',
                              label='HPV- Mutations')
    hpv_neg_cna_bar = plt.bar(neg_bar_positions, neg_cna_pcts, bar_width-epsilon,
                              bottom=neg_mut_pcts,
                              color="white",
                              hatch='//',
                              edgecolor='#0000DD',
                              ecolor="#0000DD",
                              linewidth=line_width,
                              label='HPV- CNA')
    hpv_neg_both_bar = plt.bar(neg_bar_positions, neg_both_pcts, bar_width-epsilon,
                               bottom=neg_cna_pcts+neg_mut_pcts,
                               color="white",
                               hatch='0',
                               edgecolor='#0000DD',
                               ecolor="#0000DD",
                               linewidth=line_width,
                               label='HPV- Both')

    plt.xticks(neg_bar_positions, genes, rotation=45)
    plt.ylabel('Percentage of Samples')
    plt.legend(loc='best')
    sns.despine()

# %%


def plot_clustered_stacked(dfall, labels=None, title="multiple stacked bar plot",  H="/", **kwargs):
    """Given a list of dataframes, with identical columns and index, create a clustered stacked bar plot. 
labels is a list of the names of the dataframe, used for the legend
title is a string for the title of the plot
H is the hatch used for identification of the different dataframe"""

    n_df = len(dfall)
    n_col = len(dfall[0].columns)-1
    n_ind = len(dfall[0].index)
    plt.rcParams['font.family'] = 'sans-serif'
    plt.rcParams['font.sans-serif'] = 'NSimSun,Times New Roman'
    plt.figure(figsize=(32, 18))
    axe = plt.subplot(111)

    j = 0
    for df in dfall:  # for each data frame
        axe = df.plot(kind="bar",
                      linewidth=1,
                      stacked=True,
                      ax=axe,
                      legend=False,
                      color="w",
                      #   cmap=plt.get_cmap('Pastel2'),
                      edgecolor='k',
                      #   alpha=0.5,
                      #   grid=False,
                      **kwargs)  # make bar plots
        j += 1

    h, l = axe.get_legend_handles_labels()  # get the handles we want to modify
    # gray_color = plt.get_cmap("Pastel2",lut=n_col* n_df).colors
    for i in range(0, n_df * n_col, n_col):  # len(h) = n_col * n_df
        for j, pa in enumerate(h[i:i+n_col]):
            for rect in pa.patches:  # for each index
                rect.set_x(rect.get_x() + 1 / float(n_df + 1)
                           * i / float(n_col))
                # rect.set_hatch(H * int(i / n_col))  # edited part
                # rect.set_facecolor(color[int(i / n_col)])
                rect.set_hatch(hatches[j])
                rect.set_width(1 / float(n_df + 1))

    axe.set_xticks((np.arange(0, 2 * n_ind, 2) + 1 / float(n_df + 1)) / 2.)
    axe.set_xticklabels([""+str(i)
                         for i in df['loadmodel']], fontsize=32, rotation=360)
    plt.yticks(fontsize=32)
    # axe.set_title(title)

    # # Add invisible data to add another legend
    # n = []
    # for i in range(n_df):
    #     n.append(axe.bar(0, 0, fill=False, edgecolor="w"))

    l1 = axe.legend(h[:n_col], l[:n_col], loc=[1.03, 0.4], fontsize=32)
    # if labels is not None:
    #     l2 = plt.legend(n, labels, loc=[1.05, 0.05])
    textstr = "\n从左至右:\n   Write Back\n   Hades\n   Hades plus\n"
    csfont = {'fontname': 'simsun'}
    # plt.title('title', **csfont)
    props = dict(boxstyle='round', facecolor='w',
                 edgecolor='gray', alpha=0.5, linewidth=0.8,)
    axe.text(1.04, 0.295, textstr, transform=axe.transAxes, fontsize=32,
             verticalalignment='top', bbox=props, **csfont)
    axe.add_artist(l1)
    plt.savefig("test.png", dpi=160, bbox_inches='tight')
    plt.show()
    return axe


# %%
""" create fake dataframes
df1 = pd.DataFrame(np.random.rand(4, 5),
                   index=["A", "B", "C", "D"],
                   columns=["I", "J", "K", "L", "M"])
df2 = pd.DataFrame(np.random.rand(4, 5),
                   index=["A", "B", "C", "D"],
                   columns=["I", "J", "K", "L", "M"])
df3 = pd.DataFrame(np.random.rand(4, 5),
                   index=["A", "B", "C", "D"],
                   columns=["I", "J", "K", "L", "M"]) """
color = ["#f7f7f7",  "#d8daeb", "#b2abd2", "#2d004b", "#8073ac", "#542788", ]
data = "data"
idx = "bwaves lbm leslie3d libquantum milc sjeng wrf zeusmp".split()
col = "loadmodel data1 update-l1	update-l2	update-l3	update-l4&up	evictl1	evictl2	evictl3	evictl4&up".split()
df1 = pd.read_excel(data+"1"+".xlsx", index=idx, columns=col)
df2 = pd.read_excel(data+"2"+".xlsx", index=idx, columns=col)
df3 = pd.read_excel(data+"3"+".xlsx", index=idx, columns=col)


hatches = ['\\\\', '//||', "\\o", '//.',
           '..\\', "xX", '//', '.+', ".o", '++']
# Then, just call :
axe = plot_clustered_stacked([df1, df2, df3], [
                             "WriteBack pattern", "Hades", "Hades Plus"])


# %%
