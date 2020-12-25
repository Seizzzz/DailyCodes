import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
from pylab import *
mpl.rcParams['font.sans-serif'] = ['SimHei']

total = []  # 记录确诊变化总数
date = [i for i in range(1, 16)]  # 记录日期序号

for i in range(1, 16):
    fileNameStr = './202012' + str(i).zfill(2) + '.csv'  # 产生文件名进行读取
    df = pd.read_csv(fileNameStr, encoding='utf-8')

    df['total'] = df['total'].astype(np.int)
    total.append(df['total'].sum())  # 计算所有国家的确诊总数

plt.title("20201201~20201215 新冠病毒世界确诊人数总和变化")
plt.xticks(date)
plt.plot(date, total, linestyle='-', label='total')
plt.legend()
plt.show()