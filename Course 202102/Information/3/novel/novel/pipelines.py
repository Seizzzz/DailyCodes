# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


# useful for handling different item types with a single interface
from itemadapter import ItemAdapter
import os
import pymongo
from novel.settings import MONGODB_HOST, MONGODB_PORT, MONGODB_DBNAME, MONGODB_SHEETNAME


def to_digit(str):
    if (str[0] == '第'):
        NUMSTR = ['零','一','二','三','四','五','六','七','八','九']
        HEXSTR = ['十','百','千']
        HEX = [10, 100, 1000]
        indexStr = str.split(' ')[0][1:-1]
        index, i = 0, 0
        isdigit = False
        for s in indexStr:
            if s in NUMSTR:
                i = NUMSTR.index(s)
                isdigit = True
            elif s == '两':
                i = 2
                isdigit = True
            elif s in HEXSTR and isdigit:
                index += i * HEX[HEXSTR.index(s)]
                isdigit = False
            elif s == '十' and not isdigit:
                index += 10
        if isdigit:
            index += i
        return index
    else:
        return -1


class NovelPipeline:
    count = 0

    def __init__(self):
        client = pymongo.MongoClient(
            host=MONGODB_HOST,
            port=MONGODB_PORT
        )
        db = client[MONGODB_DBNAME]
        self.post = db[MONGODB_SHEETNAME]

    def process_item(self, item, spider):
        db_item = dict()
        db_item['id'] = to_digit(item['title'])
        db_item['title'] = item['title']
        db_item['url'] = item['url']
        db_item['contentLen'] = len(item['content'])
        db_item['content'] = item['content']
        db_item['indexed'] = False
        self.post.insert_one(db_item)
        # 写入文件内容
        content = item['content']
        path = os.path.dirname(os.path.abspath(__file__)) + '/out'
        if not os.path.exists(path):
            os.mkdir(path)
        with open(path + "/" + db_item['title'] + ".txt", 'w+') as f:
            f.write(content)
        return item
