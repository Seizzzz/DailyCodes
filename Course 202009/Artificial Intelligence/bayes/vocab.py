from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import CountVectorizer
import os

files = os.listdir(r'./train/')
labels = ['女性', '汽车', '药品', '求医', 'IT', '时事', '娱乐', '电子产品', '体育', '财经']
labelChoice = 0

for filename in files:
    with open('./train/' + filename, 'r', encoding='utf8') as f:
        sentences = []
        lines = f.readlines()
        label = labels[labelChoice]
        for line in lines:
            splits = line.split(' ')
            feat = splits[:splits.__len__() - 1]
            sentences.append((" ".join(feat), label.strip()))

        X, y = zip(*sentences)
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.001, random_state=1234)
        # print('X_train len=',len(X_train))
        # print('X_test len=',len(X_test))
        # print(X_train[:2])
        # print(y_train[:2])

        vec = CountVectorizer(
            analyzer='word',
            max_features=4000,  # 通过词袋模型 字典长度最大max_features
            min_df=100,  # 词频最小数min_df 才进行统计
        )
        vec.fit(X_train)

        def get_features(x):
            return vec.transform(x)

        # print(vec.get_feature_names()[:20])  # 获得上面稀疏矩阵的列索引，即特征的名字（就是特征词－词典）
        # print('X_train=', X_train[:2])
        # print('y_train=', y_train[:2])
        words_vec = vec.transform(X_train)  # sparse matrix, [n_samples, n_features]
        # print(words_vec[:10].toarray())  # 得到分词的系数矩阵-稠密向量矩阵表示

        word = vec.get_feature_names() # 字典中的word
        # print(word[-10:-1])

        freq = words_vec.toarray().sum(axis=0)
        # print(freq[:10])

        # <word,count>
        word_freqs = dict(zip(word, freq))
        # dict 进行排序
        word_freqs = sorted(word_freqs.items(), key=lambda d:d[1], reverse=True)
        # print('word_freqs size = ',len(word_freqs))
        # print(word_freqs[:10])

        vocab_dict = dict(vec.vocabulary_)
        vocab_dict_results = sorted(vocab_dict.items(), key=lambda d: d[1], reverse=True)
        # print(vocab_dict_results[:5])

        with open('./vocab/' + filename + '_vocab.txt', 'w+') as f:
            for vocab in vocab_dict_results:
                text = "{}|{}".format(vocab[0], vocab[1])
                f.write(text+"\n")

    labelChoice = labelChoice + 1