import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
from pylab import *
mpl.rcParams['font.sans-serif'] = ['SimHei']

country = ['美国', '巴西', '印度', '土耳其', '俄罗斯', '德国', '意大利', '英国', '乌克兰', '法国']
date = [i for i in range(1, 16)]  # 记录日期序号

fig, ax = plt.subplots()
sub = 0

for name in country:
    sub = sub + 1
    increase = []
    for i in range(1, 16):
        fileNameStr = './202012' + str(i).zfill(2) + '.csv'  # 产生文件名进行读取
        df = pd.read_csv(fileNameStr, encoding='utf-8')
        df['increase'] = df['increase'].astype(np.int)

        val = df[df['country'].isin([name])]['increase']
        val = val.reset_index(drop=True)
        increase.append(val[0])

    plt.subplot(3, 4, sub)
    plt.xticks(date)
    plt.title(name + '新增确诊人数变化')
    plt.plot(date, increase, linestyle='-')

plt.subplots_adjust(left=None, bottom=None, right=None, top=None, wspace=0.5, hspace=1)
plt.show()