import math
import random


def sigmoid(x):
    return 1 / (1 + math.exp(-x))


def judge(x):
    if x < 0.5:
        return 0
    return 1


def gethat():
    for i in range(4):
        x1 = x1_array[i % 4]
        x2 = x2_array[i % 4]
        y1 = y1_array[i % 4]

        beta1 = v11 * x1 + v21 * x2
        beta2 = v12 * x1 + v22 * x2
        b1 = sigmoid(beta1 - gamma1)
        b2 = sigmoid(beta2 - gamma2)

        alpha1 = w11 * b1 + w21 * b2
        haty1 = sigmoid(alpha1 - theta1)
        print("Train set #", i, haty1)


x1_array = [0, 0, 1, 1]
x2_array = [0, 1, 0, 1]
y1_array = [0, 1, 1, 0]

# eta = 0.8
# v11 = random.random()
# v12 = random.random()
# v21 = random.random()
# v22 = random.random()
# w11 = random.random()
# w21 = random.random()
# theta1 = random.random()
# gamma1 = random.random()
# gamma2 = random.random()

eta = 1
v11 = 1
v12 = -1
v21 = -1
v22 = 1
w11 = 1
w21 = 1
theta1 = 0.5
gamma1 = 0.5
gamma2 = 0.5

print(v11)
print(v12)
print(v21)
print(v22)
print(w11)
print(w21)
print(theta1)
print(gamma1)
print(gamma2)

correct = 0
i = 0

while True:
    x1 = x1_array[i % 4]
    x2 = x2_array[i % 4]
    y1 = y1_array[i % 4]

    beta1 = v11*x1+v21*x2
    beta2 = v12*x1+v22*x2
    b1 = sigmoid(beta1-gamma1)
    b2 = sigmoid(beta2-gamma2)

    alpha1 = w11*b1+w21*b2
    haty1 = sigmoid(alpha1-theta1)

    if judge(haty1) == y1:
        correct = correct + 1
    else:
        correct = 0

    if correct >= 4:
        break;

    g1 = haty1*(1.0-haty1)*(y1-haty1)

    e1 = b1*(1-b1)*w11*g1
    e2 = b2*(1-b2)*w21*g1

    dw11 = eta*b1*g1
    dw21 = eta*b2*g1
    dtheta1 = -eta*g1
    dv11 = eta*e1*x1
    dv12 = eta*e2*x1
    dv21 = eta*e1*x2
    dv22 = eta*e2*x2
    dgamma1 = -eta*e1
    dgamma2 = -eta*e2

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
print(v11)
print(v12)
print(v21)
print(v22)
print(w11)
print(w21)
print(theta1)
print(gamma1)
print(gamma2)

gethat()