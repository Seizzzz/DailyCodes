import scrapy
from loupan.items import LoupanItem

class lpSpider(scrapy.Spider):
    name = "lp"
    allowed_domains = ["lianjia.com/loupan"]
    start_urls = []
    for i in range(1, 8):
        url = 'https://bj.fang.lianjia.com/loupan/pg' + str(i)
        start_urls.append(url)

    def parse(self, response):
        item = LoupanItem()

        for each in response.xpath('//div[@class="resblock-desc-wrapper"]'):
            item['name'] = each.xpath('div[1]/a/text()').extract()
            item['location'] = each.xpath('div[2]/span[1]/text()').extract() + each.xpath('div[2]/span[2]/text()').extract() + each.xpath('div[2]/a/text()').extract()
            item['type'] = each.xpath('a[1]/span[1]/text()').extract()
            item['area'] = each.xpath('div[3]/span[1]/text()').extract()
            #item['totalPrice'] = each.xpath('div[6]/div[2]/text()').extract()
            item['totalPrice'] = ""
            item['evenPrice'] = each.xpath('div[6]/div[1]/span[1]/text()').extract()
            if item['name'] and item['area']:
                yield item