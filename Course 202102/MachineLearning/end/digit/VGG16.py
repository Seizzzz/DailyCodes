import numpy as np
import pandas as pd
from keras.utils.np_utils import to_categorical
from keras.applications.vgg16 import VGG16
from keras.models import Sequential
from keras.layers import Flatten, Dense, Dropout
from keras.optimizers import SGD
from keras.preprocessing.image import ImageDataGenerator
from keras.callbacks import ReduceLROnPlateau
from keras.datasets import mnist
import cv2

# 参数
epochs = 1
batch_size = 128

# 准备数据
(X_train_data, Y_train_data), (X_test_data, Y_test_data) = mnist.load_data()  # 下载数据
X_train_data = X_train_data.astype('float32') / 255.0
X_test_data = X_test_data.astype('float32') / 255.0
# 转化为(48, 48, 3)维
X_train = []
X_test = []
for i in range(X_train_data.shape[0]):
    X_train.append(cv2.cvtColor(cv2.resize(X_train_data[i], (48, 48)), cv2.COLOR_GRAY2RGB))
for i in range(X_test_data.shape[0]):
    X_test.append(cv2.cvtColor(cv2.resize(X_test_data[i], (48, 48)), cv2.COLOR_GRAY2RGB))
X_train = np.array(X_train)
X_test = np.array(X_test)
# 独热编码
Y_train = to_categorical(Y_train_data, num_classes=10)
Y_test = to_categorical(Y_test_data, num_classes=10)

# 构建网络
vgg16_model = VGG16(weights='imagenet', include_top=False, input_shape=(48, 48, 3))
for layer in vgg16_model.layers:
    layer.trainable = False  # freeze VGG16卷积层的参数

model = Sequential()
model.add(vgg16_model)
model.add(Flatten(input_shape=vgg16_model.output_shape[1:]))
model.add(Dense(512, activation='relu'))
model.add(Dropout(0.4))
model.add(Dense(10, activation='softmax'))
model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['acc'])

# 训练
model.fit(X_train, Y_train, batch_size=batch_size, epochs=epochs)
model.save_weights("VGG16.h5")
# model.load_weights("VGG16.h5")

# 预测
results = model.predict(X_test)
results = np.argmax(results, axis=1)
results = pd.Series(results, name="Label")
submission = pd.concat([pd.Series(range(1, 10001), name="ImageId"), results], axis=1)
submission.to_csv("VGG16.csv", index=False)
