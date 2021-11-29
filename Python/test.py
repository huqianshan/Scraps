# %%
from time import time
from sklearn.ensemble import RandomForestRegressor
from sklearn.model_selection import train_test_split
import pandas as pd

 
# %%
path = r'E:\华为杯数学建模\325 个样本原始数据.xlsx'
data = pd.read_excel(path, header=1)  # 原始数据，包含表头
s = data[0]
RON = data[1]  # 辛烷值
factors = data.drop(columns={0, 1, 2})  # 其它因素
factors = factors.dropna(axis=1)


t0 = time()
forest = RandomForestRegressor(n_estimators=500, random_state=0,
                               max_features=100,  n_jobs=2)
X_train, X_test, y_train, y_test = train_test_split(
    factors, RON, test_size=0.3, shuffle=True, random_state=0)
t1 = time()

print(f"done in {t1-to}fs")
importances = forest.feature_importances_
print(importances)
print(sorted(importances, reverse=True))


# %%
