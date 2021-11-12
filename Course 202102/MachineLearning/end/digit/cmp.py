import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from keras.datasets import mnist

epochs = 1
test_total = 10000

df_CNN = pd.read_csv("./epochs%d/CNN.csv" % epochs)
df_VGG16 = pd.read_csv("./epochs%d/VGG16.csv" % epochs)

(X_train_data, Y_train_data), (X_test_data, Y_test_data) = mnist.load_data()
X_test_data = X_test_data.astype('float32') / 255.0
X_test = np.reshape(X_test_data, (-1, 28, 28, 1))
Y_test = Y_test_data

err_CNN = 0
err_VGG16 = 0

for i in range(test_total):
    res_CNN = df_CNN["Label"][i]
    res_VGG16 = df_VGG16["Label"][i]
    if res_CNN != res_VGG16:
        res_correct = Y_test[i]
        if res_CNN != res_correct:
            err_CNN = err_CNN + 1
        if res_VGG16 != res_correct:
            err_VGG16 = err_VGG16 + 1
        # plt.imshow(X_test[i][:, :, 0])
        # plt.savefig("./epochs%d/%d_%d_%d_%d.jpg" % (epochs, i, Y_test[i], res_CNN, res_VGG16))


print(err_CNN, err_VGG16)