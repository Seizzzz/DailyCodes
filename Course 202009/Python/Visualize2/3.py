from pyecharts import options as opts
from pyecharts.charts import Map
import numpy as np
import pandas as pd
import random

df = pd.read_csv("./中国大学数量.csv", encoding='utf-8', dtype=np.str)
df = pd.DataFrame(df, columns=['省/市', '公办本科大学数量'])
df['省/市'] = df['省/市'].astype(np.str)
df['公办本科大学数量'] = df['公办本科大学数量'].astype(np.int)

class Data:
    @staticmethod
    def province() -> list:
        res = []
        for i in range(len(df)):
            res.append(str(df['省/市'][i]))
        return res

    @staticmethod
    def values() -> list:
        res = []
        for i in range(len(df)):
            res.append(int(df['公办本科大学数量'][i]))
        return res


def map2() -> Map:
    c = (
        Map()
            .add("数量", [list(z) for z in zip(Data.province(), Data.values())], "china").set_global_opts(
            title_opts=opts.TitleOpts(title="各省公办本科大学数量"),
            visualmap_opts=opts.VisualMapOpts(min_=int(df['公办本科大学数量'].min()), max_=int(df['公办本科大学数量'].max())))
            .set_series_opts(label_opts=opts.LabelOpts(is_show=True))
    )
    return c


map2().render("map2.html")
