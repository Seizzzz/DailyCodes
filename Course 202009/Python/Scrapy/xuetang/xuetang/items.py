# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class XuetangItem(scrapy.Item):
    # define the fields for your item here like:
    course = scrapy.Field()
    teacher = scrapy.Field()
    university = scrapy.Field()
    num_stu = scrapy.Field()
    pass
