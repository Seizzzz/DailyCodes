import numpy as np
import pandas as pd

fileNameStr = './Beijing.csv'
df = pd.read_csv(fileNameStr, encoding='utf-8', dtype=str)
num = len(df)

# sum = 0
# cnt = 0
# nowyear = 2010
# for i in range(num):
#     if int(df['year'][i]) == nowyear:
#         if not df['PM_US Post'][i] is np.nan:
#             sum = sum + int(df['PM_US Post'][i])
#             cnt = cnt + 1
#     else:
#         print("%d: %.3f" % (nowyear, sum/cnt))
#         sum = 0
#         cnt = 0
#         nowyear = int(df['year'][i])
#
# print("%d: %.3f" % (nowyear, sum/cnt))

sumpm = 0
sumtemp = 0
cnt = 0
nowyear = 2010
nowmonth = 1
for i in range(num):
    if int(df['year'][i]) == nowyear and float(df['month'][i]) == nowmonth:
        if (not df['PM_US Post'][i] is np.nan) and (not df['TEMP'][i] is np.nan):
            sumpm = sumpm + int(df['PM_US Post'][i])
            sumtemp = sumtemp + float(df['TEMP'][i])
            cnt = cnt + 1
    else:
        print("%d.%d: pm=%.3f, temp=%.3f" % (nowyear, nowmonth, sumpm/cnt, sumtemp/cnt))
        sumpm = 0
        sumtemp = 0
        cnt = 0
        nowyear = int(df['year'][i])
        nowmonth = int(df['month'][i])

print("%d.%d: pm=%.3f, temp=%.3f" % (nowyear, nowmonth, sumpm/cnt, sumtemp/cnt))
