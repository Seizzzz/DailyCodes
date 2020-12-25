import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
from pylab import *
mpl.rcParams['font.sans-serif'] = ['SimHei']

res = {}

for i in range(1, 16): # 统计15天的新增人数
    fileNameStr = './202012' + str(i).zfill(2) + '.csv'  # 产生文件名进行读取
    df = pd.read_csv(fileNameStr, encoding='utf-8')

    df['increase'] = df['increase'].astype(np.int)
    df['total'] = df['total'].astype(np.int)

    for idx in range(len(df)):  # 遍历所有国家
        if df['total'][idx] < 10000:
            continue
        if df['country'][idx] in res.keys():
            res[df['country'][idx]] = res[df['country'][idx]] + (df['increase'][idx] / df['total'][idx])
        else:
            res[df['country'][idx]] = df['increase'][idx] / df['total'][idx]

for i in res:
    res[i] = res[i] / 15

lst = sorted(res.items(), key=lambda x:x[1], reverse=False)  # 按比例进行排序
country = []
percent = []
for i in range(10):  # 取出前10的国家
    country.append(lst[i][0])
    percent.append(lst[i][1])

plt.title("20201201~20201215 新冠病毒新增人数/确诊总数国家BOTTOM10")
plt.bar(country, percent, label='increase')
plt.legend()
plt.show()