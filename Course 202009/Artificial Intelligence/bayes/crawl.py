import re

path = './train.dat'
file = open(path, 'rb').read().decode("utf-8")

patternURL = re.compile(r'<url>(.*?)</url>', re.S)
patternTitle = re.compile(r'<contenttitle>(.*?)</contenttitle>', re.S)
patternContent = re.compile(r'<content>(.*?)</content>', re.S)
patternClass = re.compile(r'http://(.*?)/', re.S)

threh = 30

urls = patternURL.findall(file)
titles = patternTitle.findall(file)
contents = patternContent.findall(file)

for i in range(len(contents)):
    contents[i] = titles[i] + contents[i]  # 拼接标题和内容

for i in range(contents.__len__())[::-1]:
    if len(contents[i]) < threh:  # 文本长度过短
        contents.pop(i)
        urls.pop(i)

for i in range(urls.__len__()):
    classes = patternClass.findall(urls[i])
    urls[i] = classes[0]

for i in range(urls.__len__()):
    file = 'samples/' + urls[i] + '.txt'
    f = open(file, 'a+', encoding='utf-8')
    f.write(contents[i]+'\n')
