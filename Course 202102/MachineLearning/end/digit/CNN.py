import pandas as pd
import numpy as np
from keras.utils.np_utils import to_categorical
from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten, Conv2D, MaxPool2D
from keras.optimizers import RMSprop
from keras.preprocessing.image import ImageDataGenerator
from keras.callbacks import ReduceLROnPlateau
from keras.datasets import mnist

# 参数
epochs = 1
batch_size = 128

# 准备数据
(X_train_data, Y_train_data), (X_test_data, Y_test_data) = mnist.load_data()
X_train_data = X_train_data.astype('float32') / 255.0  # 标准化至区间[0,1]
X_test_data = X_test_data.astype('float32') / 255.0
X_train = np.reshape(X_train_data, (-1, 28, 28, 1))  # 转化为(28, 28, 1)维
X_test = np.reshape(X_test_data, (-1, 28, 28, 1))
Y_train = to_categorical(Y_train_data, num_classes=10)  # 独热编码
Y_test = to_categorical(Y_test_data, num_classes=10)

# 构建网络
# In -> [[Conv2D->relu]*2 -> MaxPool2D -> Dropout]*2 -> Flatten -> Dense -> Dropout -> Out
model = Sequential()

model.add(Conv2D(filters=32, kernel_size=(5, 5), padding='Same',
                 activation='relu', input_shape = (28, 28, 1)))
model.add(Conv2D(filters=32, kernel_size=(5, 5), padding='Same',
                 activation='relu'))
model.add(MaxPool2D(pool_size=(2, 2)))
model.add(Dropout(0.25))

model.add(Conv2D(filters=64, kernel_size=(3, 3), padding='Same',
                 activation='relu'))
model.add(Conv2D(filters=64, kernel_size=(3, 3), padding='Same',
                 activation='relu'))
model.add(MaxPool2D(pool_size=(2, 2), strides=(2, 2)))
model.add(Dropout(0.25))

model.add(Flatten())
model.add(Dense(256, activation="relu"))
model.add(Dropout(0.5))
model.add(Dense(10, activation="softmax"))

# Define the optimizer
optimizer = RMSprop(lr=0.001, rho=0.9, epsilon=1e-08, decay=0.0)

# Compile model
model.compile(optimizer=optimizer, loss="categorical_crossentropy", metrics=["accuracy"])

# Set a learning rate annealer
# learning_rate_reduction = ReduceLROnPlateau(monitor='val_accuracy',
#                                             patience=3,
#                                             verbose=1,
#                                             factor=0.5,
#                                             min_lr=0.00001)
# datagen = ImageDataGenerator(
#     featurewise_center=False,  # set input mean to 0 over the dataset
#     samplewise_center=False,  # set each sample mean to 0
#     featurewise_std_normalization=False,  # divide inputs by std of the dataset
#     samplewise_std_normalization=False,  # divide each input by its std
#     zca_whitening=False,  # apply ZCA whitening
#     rotation_range=10,  # randomly rotate images in the range (degrees, 0 to 180)
#     zoom_range=0.1,  # Randomly zoom image
#     width_shift_range=0.1,  # randomly shift images horizontally (fraction of total width)
#     height_shift_range=0.1,  # randomly shift images vertically (fraction of total height)
#     horizontal_flip=False,  # randomly flip images
#     vertical_flip=False)  # randomly flip images
# datagen.fit(X_train)

# 训练
model.fit(X_train, Y_train, batch_size=batch_size, epochs=epochs)
# model.fit_generator(datagen.flow(X_train, Y_train, batch_size=batch_size),
#                     epochs=epochs, validation_data=(X_test, Y_test),
#                     verbose=2, steps_per_epoch=X_train.shape[0] // batch_size,
#                     callbacks=[learning_rate_reduction])
model.save_weights("CNN_noaug.h5")
# model.load_weights("CNN.h5")

# 预测
results = model.predict(X_test)
results = np.argmax(results, axis=1)
results = pd.Series(results, name="Label")
submission = pd.concat([pd.Series(range(1, 10001), name="ImageId"), results], axis=1)
submission.to_csv("CNN.csv", index=False)
