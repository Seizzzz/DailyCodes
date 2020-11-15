# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class LianjiaItem(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    district = scrapy.Field()
    name = scrapy.Field()
    pricetotal = scrapy.Field()
    priceunit = scrapy.Field()
    area = scrapy.Field()
    pass
