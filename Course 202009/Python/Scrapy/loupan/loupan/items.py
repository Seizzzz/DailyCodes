# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class LoupanItem(scrapy.Item):
    name = scrapy.Field()
    location = scrapy.Field()
    type = scrapy.Field()
    area = scrapy.Field()
    totalPrice = scrapy.Field()
    evenPrice = scrapy.Field()
    pass
