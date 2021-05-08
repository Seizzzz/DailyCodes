import numpy as np
import pandas as pd
from sklearn.datasets import load_iris

iris = load_iris()

data = pd.DataFrame(iris['data'])
data[4] = iris['target']

data: pd.DataFrame = data.sample(frac=1.0)
split = int(150 * 0.75)

data_train: pd.DataFrame = data.iloc[0: split, :]
data_train = data_train.reset_index(drop=True)
data_test: pd.DataFrame = data.iloc[split: 150, :]
data_test = data_test.reset_index(drop=True)

# data_train.to_csv('train.csv')
# data_test.to_csv('test.csv')