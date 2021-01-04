import jieba
import os

stopfile = open(r'./stop_words.txt', encoding='utf-8')
stop = []
while True:
    line = stopfile.readline()
    if not line:
        break
    line = line.strip()
    stop.append(line)
stopfile.close()

files = os.listdir(r'./test')

for filename in files:
    infile = open('./test/' + filename, encoding='utf-8')
    outfile = open('./test/' + filename + '_div', 'a+', encoding='utf-8')
    while True:
        line = infile.readline()
        if not line:
            break
        line = line.replace(u'\ue40c', u'')
        line = line.replace(u'\u3000', u'')
        line = line.strip()
        result = jieba.cut(line, cut_all=False)
        newline = ''
        for word in result:
            if word not in stop:
                newline = newline + word + ' '
        outfile.write(newline + '\n')
    infile.close()
    outfile.close()