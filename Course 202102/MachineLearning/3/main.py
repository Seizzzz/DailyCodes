import numpy as np
from sklearn.svm import SVC


X = np.array([[-1, -1], [-1, 1], [1, -1], [1, 1]])
y = np.array([-1, 1, 1, -1])

clf = SVC(C=1, kernel='poly', degree=2)
clf.fit(X, y)

print(clf.predict([[-1, -1], [-1, 1], [1, -1], [1, 1]]))