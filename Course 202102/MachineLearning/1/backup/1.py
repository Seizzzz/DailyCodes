import math
import random

# 训练集同测试集
x1_array = [0, 0, 1, 1]
x2_array = [0, 1, 0, 1]
y1_array = [0, 1, 1, 0]


# sigmoid
def sigmoid(x):
    return 1 / (1 + math.exp(-x))


# 阈值函数，最终输出结果取整
def judge(x):
    if x < 0.5:
        return 0
    return 1


# 初始值
eta = 1
v11 = 1
v12 = -1
v21 = -1
v22 = 1
w11 = 1
w21 = 1
k1 = 0
k2 = 0
theta1 = 0.5
gamma1 = 0.5
gamma2 = 0.5


# 检测当前参数是否能输出正确结果
def test():
    record = [0, 0, 0, 0]
    for t in range(4):
        x1 = x1_array[t % 4]
        x2 = x2_array[t % 4]
        y1 = y1_array[t % 4]

        beta1 = v11 * x1 + v21 * x2 + k1
        beta2 = v12 * x1 + v22 * x2 + k1

        b1 = sigmoid(beta1 - gamma1)
        b2 = sigmoid(beta2 - gamma2)
        alpha1 = w11 * b1 + w21 * b2 + k2
        haty1 = sigmoid(alpha1 - theta1)
        record[t] = haty1

        if judge(haty1) != y1:
            return False
    print(record)
    return True


i = 0
while True:
    if test():
        break
    # 读取训练集样本
    x1 = x1_array[i % 4]
    x2 = x2_array[i % 4]
    y1 = y1_array[i % 4]

    # 计算各节点输入输出
    beta1 = v11 * x1 + v21 * x2 + k1
    beta2 = v12 * x1 + v22 * x2 + k1
    b1 = sigmoid(beta1 - gamma1)
    b2 = sigmoid(beta2 - gamma2)
    alpha1 = w11 * b1 + w21 * b2 + k2

    # 当前感知机输出结果
    haty1 = sigmoid(alpha1 - theta1)

    # 计算改变量
    g1 = haty1*(1.0-haty1)*(y1-haty1)
    e1 = b1*(1-b1)*w11*g1
    e2 = b2*(1-b2)*w21*g1

    dk1 = eta*g1*(w11+w21)*b1*(1-b1)
    dk2 = eta*g1
    dw11 = eta*b1*g1
    dw21 = eta*b2*g1
    dtheta1 = -eta*g1
    dv11 = eta*e1*x1
    dv12 = eta*e2*x1
    dv21 = eta*e1*x2
    dv22 = eta*e2*x2
    dgamma1 = -eta*e1
    dgamma2 = -eta*e2

    # 按该变量更新当前参数
    k1 = k1+dk1
    k2 = k2+dk2
    v11 = v11+dv11
    v12 = v12+dv12
    v21 = v21+dv21
    v22 = v22+dv22
    w11 = w11+dw11
    w21 = w21+dw21
    theta1 = theta1+dtheta1
    gamma1 = gamma1+dgamma1
    gamma2 = gamma2+dgamma2

    i = i + 1

print(i, " times")
print(k1)
print(k2)
print(v11)
print(v12)
print(v21)
print(v22)
print(w11)
print(w21)
print(theta1)
print(gamma1)
print(gamma2)