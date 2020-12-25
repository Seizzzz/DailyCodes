from pyecharts import options as opts
from pyecharts.charts import Geo
from pyecharts.globals import ChartType
from pyecharts.render import make_snapshot
from snapshot_phantomjs import snapshot
import pandas as pd
import numpy as np

df = pd.read_csv("./weather.csv", encoding='utf-8', dtype=np.str)
df = pd.DataFrame(df, columns=['temperature'])
df['temperature'] = df['temperature'].astype(np.float)
day = 0

class Data:
    guangdong_city = ["深圳市"]

    @staticmethod
    def values() -> list:
        res = []
        for i in range(len(df)):
            res.append(float(df['temperature'][i]))
        return res

def geo_guangdong(title) -> Geo:
    c = (
        Geo()
        .add_schema(maptype="广东")
        .add(
            title,
            [list(z) for z in zip(Data.guangdong_city, [Data.values()[day]])],
            type_=ChartType.HEATMAP,
        )
        .set_global_opts(
            visualmap_opts=opts.VisualMapOpts(min_=0, max_=int(df['temperature'].max())),#is_piecewise=True),
            title_opts=opts.TitleOpts(title="广东省深圳市12月13-27日温度变化情况"),
        )
    )
    return c

for i in range(10):
    day = i
    str_date="12月" + str(i+13) + "日"
    make_snapshot(snapshot, geo_guangdong(str_date).render(),
                  str(i+1)+".png", pixel_ratio=1)
