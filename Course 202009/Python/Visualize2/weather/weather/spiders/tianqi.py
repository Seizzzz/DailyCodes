import scrapy
from weather.items import WeatherItem

class TianqiSpider(scrapy.Spider):
    name = 'tianqi'
    allowed_domains = ['tianqi.com']
    start_urls = ['https://www.tianqi.com/shenzhen/15']

    def parse(self, response):
        item = WeatherItem()
        data = response.xpath('//ul[@class="weaul"]/li')
        for each in data:
            item['date'] = each.xpath('a/div[1]/span[1]/text()').extract()
            low = each.xpath('a/div[4]/span[1]/text()').extract()[0]
            high = each.xpath('a/div[4]/span[2]/text()').extract()[0]
            item['temperature'] = str((int(low) + int(high)) / 2)
            yield item
        pass
