import numpy as np
from keras.layers import Input, Dense
from keras.models import Model
import tensorflow as tf

# 生成训练集
dataset_size = 128*3
rdm = np.random.RandomState(1)
X = rdm.rand(dataset_size,2)
Y1 = [[int(x1+x2<1)] for (x1,x2) in X]
Y2 = [[int(x1+x2*x2<0.5)] for (x1,x2) in X]

X_train = X[:-2]
Y_train1 = Y1[:-2]
Y_train2 = Y2[:-2]

X_test = X[-2:dataset_size]
Y_test1 = Y1[-2:dataset_size]
Y_test2 = Y2[-2:dataset_size]

#网络一
input = Input(shape=(2,))
x = Dense(units=16,activation='relu')(input)
output = Dense(units=1,activation='sigmoid',name='output1')(x)

#网络二
input2 = Input(shape=(2,))
x2 = Dense(units=16,activation='relu')(input2)
output2 = Dense(units=1,activation='sigmoid',name='output2')(x2)

#模型合并
model = Model(inputs=[input,input2],outputs=[output,output2])
model.summary()

model.compile(optimizer='rmsprop',loss='binary_crossentropy',loss_weights=[1.0,1.0])
model.fit([X_train,X_train],[Y_train1,Y_train2],batch_size=48,epochs=200)


print('x_test is :\n')
print(X_test)
print('y_test1 is :\n')
print(Y_test1)
print('y_test2 is :\n')
print(Y_test2)

predict = model.predict([X_test,X_test])
print('prediction is : \n')
print(predict[0])
print(predict[1])