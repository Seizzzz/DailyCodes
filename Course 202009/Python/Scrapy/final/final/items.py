# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class FinalItem(scrapy.Item):
    # define the fields for your item here like:
    country = scrapy.Field()
    date = scrapy.Field()
    increase = scrapy.Field()
    exist = scrapy.Field()
    total = scrapy.Field()
    cured = scrapy.Field()
    death = scrapy.Field()
    pass
