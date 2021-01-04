from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB
import os
import pickle

sentences = []
testfiles = os.listdir(r'./test/')
labels = ['女性', '汽车', '药品', '求医', 'IT', '时事', '娱乐', '电子产品', '体育', '财经']

labelChoice = 0
for filename in testfiles:
    with open('./test/' + filename, 'r', encoding='utf8') as f:
        lines = f.readlines()
        label = labels[labelChoice]
        for line in lines:
            splits = line.split(' ')
            feat = splits[:splits.__len__() - 1]
            sentences.append((" ".join(feat), label.strip()))
    labelChoice = labelChoice + 1

X, y = zip(*sentences)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.9999, random_state=1234)

vec = CountVectorizer(
    analyzer='word',
    max_features=4000,  # 通过词袋模型 字典长度最大max_features
    min_df=100,  # 词频最小数min_df 才进行统计
)
vec.fit(X_test)

savefile = open('./model/bayes.pkl', 'rb')
clf = pickle.load(savefile)
accuracy = clf.score(vec.transform(X_test), y_test)
print('accuracy = ', accuracy)