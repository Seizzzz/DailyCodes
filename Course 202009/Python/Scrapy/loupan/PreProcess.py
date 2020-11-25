import numpy as np
import pandas as pd

fileNameStr = 'result.csv'
orig_df = pd.read_csv(fileNameStr, encoding='utf-8', dtype=str)
num = len(orig_df)

orig_df['area'] = orig_df['area'].str.strip()
orig_df['evenPrice'] = orig_df['evenPrice'].str.strip()
orig_df['location'] = orig_df['location'].str.strip()
orig_df['name'] = orig_df['name'].str.strip()
orig_df['totalPrice'] = orig_df['totalPrice'].str.strip()
orig_df['type'] = orig_df['type'].str.strip()

for i in range(num):
    orig_df.area[i] = orig_df.area[i].replace("建面 ", "")
    idx = orig_df.area[i].find("-")
    if idx == -1:
        idx = len(orig_df.area[i]) - 1
    orig_df.area[i] = orig_df.area[i][0:idx]

orig_df['area'] = orig_df['area'].astype(np.float).astype(int)
orig_df['evenPrice'] = orig_df['evenPrice'].astype(np.float)
orig_df['totalPrice'] = orig_df['totalPrice'].astype(np.float)
df = orig_df['location'].str.split(',', expand=True)

for i in range(num):
    orig_df.totalPrice[i] = round(orig_df.area[i] * orig_df.evenPrice[i] / 10000, 4)

print("总价最高：", end="")
print(orig_df['totalPrice'].max())
print(orig_df.iloc[orig_df['totalPrice'].idxmax()].values.tolist())
print("总价最低：", end="")
print(orig_df['totalPrice'].min())
print(orig_df.iloc[orig_df['totalPrice'].idxmin()].values.tolist())
print("总价中位数：", end="")
print(orig_df['totalPrice'].median())
print("单价最高：", end="")
print(orig_df['evenPrice'].max())
print(orig_df.iloc[orig_df['evenPrice'].idxmax()].values.tolist())
print("单价最低：", end="")
print(orig_df['evenPrice'].min())
print(orig_df.iloc[orig_df['evenPrice'].idxmin()].values.tolist())
print("单价中位数：", end="")
print(orig_df['evenPrice'].median())

result = pd.concat([orig_df['name'], df, orig_df['type'], orig_df['area'], orig_df['evenPrice'], orig_df['totalPrice']], axis=1, ignore_index=True)
result.columns = ['name', 'location1', 'location2', 'location3', 'location4', 'location5', 'type', 'area', 'evenPrice', 'totalPrice']
result.sort_values(by='evenPrice', ascending=False, inplace=True)

result.to_csv("result-handled.csv", encoding="utf-8")

print(result.describe())