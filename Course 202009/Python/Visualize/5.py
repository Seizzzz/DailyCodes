import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

orig_df = pd.read_csv("./BeijingPM20100101_20151231.csv", encoding='utf-8', dtype=str)
orig_df = pd.DataFrame(orig_df, columns=['year', 'month', 'PM_US Post'])
df = orig_df.dropna(0, how='any')
df['month'] = df['month'].astype(int)
df['year'] = df['year'].astype(int)
df['PM_US Post'] = df['PM_US Post'].astype(int)
df.reset_index(drop=True, inplace=True)
num = len(df)

section = np.arange(1, 13)
record = 0
fig, ax = plt.subplots()
plt.style.use('classic')
plt.title("2010-2015 Beijing average PM2.5(from PM_US Post) per month")

for nowyear in range(2010, 2016):
    i = record
    result = [0 for i in range(13)]
    nowsum = 0
    cntday = 0
    nowmonth = 1
    while i < num:
        if df['month'][i] == nowmonth:
            cntday = cntday + 1
            nowsum = nowsum + df['PM_US Post'][i]
        else:
            if df['year'][i] != nowyear:
                record = i
                result[nowmonth] = nowsum / cntday
                break
            result[nowmonth] = nowsum / cntday
            cntday = 1
            nowsum = df['PM_US Post'][i]
            nowmonth = df['month'][i]
        i = i + 1

    result = result[1:]

    #
    x = np.array(range(1, 13))

    plt.plot(x, result, linestyle='-', label=str(nowyear))

plt.legend()
plt.show()