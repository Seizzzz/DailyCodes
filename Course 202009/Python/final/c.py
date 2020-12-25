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

    for idx in range(len(df)):  # 遍历所有国家
        if df['country'][idx] in res.keys():
            res[df['country'][idx]] = res[df['country'][idx]] + df['increase'][idx]
        else:
            res[df['country'][idx]] = df['increase'][idx]

lst = sorted(res.items(), key=lambda x:x[1], reverse=True)  # 按新增人数进行排序
country = []
increase = []
for i in range(10):  # 取出前10的国家
    country.append(lst[i][0])
    increase.append(lst[i][1])

plt.title("20201201~20201215 新冠病毒新增人数国家TOP10")
plt.bar(country, increase, label='increase')
plt.legend()
plt.show()