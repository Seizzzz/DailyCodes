from settings import MONGODB_HOST, MONGODB_PORT, MONGODB_DBNAME, MONGODB_SHEETNAME
import pymongo
import jieba
from jieba.analyse import ChineseAnalyzer
from whoosh.fields import Schema, ID, TEXT, NUMERIC
from whoosh.index import create_in, open_dir
import os
import logging


class IndexBuilder:
    def __init__(self):
        client = pymongo.MongoClient(
            host=MONGODB_HOST,
            port=MONGODB_PORT
        )
        db = client[MONGODB_DBNAME]
        self.post = db[MONGODB_SHEETNAME]

    def build_index(self):
        jieba.setLogLevel(logging.INFO)
        analyzer = ChineseAnalyzer()
        # build index schema
        schema = Schema(
            id=NUMERIC(stored=True),
            title=TEXT(stored=True, analyzer=analyzer),
            url=ID(stored=True),
            content=TEXT(stored=True, analyzer=analyzer)
        )
        # build index file
        path = os.path.dirname(os.path.abspath(__file__)) + "/index"
        if not os.path.exists(path):
            os.mkdir(path)
            index = create_in(path, schema)
        else:
            index = open_dir(path)
        # add content to index
        writer = index.writer()
        total_row = self.post.count_documents({})
        false_row = self.post.count_documents({'indexed': False})
        indexed_row = total_row - false_row
        while True:
            row = self.post.find_one({'indexed': False})
            if row is None:
                writer.commit()
                break
            else:
                writer.add_document(
                    id=(total_row+1) if (row['id'] == -1) else row['id'],
                    title=row['title'],
                    url=row['url'],
                    content=row['content']
                )
                self.post.update_one(
                    {'title': row['title']},
                    {'$set': {'indexed': True}}
                )
                writer.commit()
                writer = index.writer()
                indexed_row += 1
                print("Indexed: %d/%d" % (indexed_row, total_row))


IndexBuilder().build_index()
