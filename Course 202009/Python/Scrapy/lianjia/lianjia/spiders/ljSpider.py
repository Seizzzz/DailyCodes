import scrapy
from lianjia.items import LianjiaItem

class ljSpider(scrapy.Spider):
    name = "lj"
    allowed_domains = ["lianjia.com/ershoufang"]
    start_urls = []
    for i in range(1, 6):
        url = 'https://bj.lianjia.com/ershoufang/dongcheng/pg' + str(i)
        start_urls.append(url)
        url = 'https://bj.lianjia.com/ershoufang/xicheng/pg' + str(i)
        start_urls.append(url)
        url = 'https://bj.lianjia.com/ershoufang/chaoyang/pg' + str(i)
        start_urls.append(url)
        url = 'https://bj.lianjia.com/ershoufang/haidian/pg' + str(i)
        start_urls.append(url)

    def parse(self, response):
        item = LianjiaItem()
        district = ''
        if 'dongcheng' in response.request.url:
            district = '东城区'
        elif 'xicheng' in response.request.url:
            district = '西城区'
        elif 'chaoyang' in response.request.url:
            district = '朝阳区'
        elif 'haidian' in response.request.url:
            district = '海淀区'

        for each in response.xpath('//div[@class="info clear"]'):
            item['district'] = district
            item['name'] = "".join(each.xpath('div[@class="title"]//a//text()').extract())
            item['pricetotal'] = "".join(each.xpath('div[@class="priceInfo"]//div[@class="totalPrice"]//text()').extract())
            item['priceunit'] = "".join(each.xpath('div[@class="priceInfo"]//div[@class="unitPrice"]//span//text()').extract())[2:]
            item['area'] = "".join(each.xpath('//div[@class="houseInfo"]//text()').extract()).partition('|')[2].partition('|')[0].replace(' ', '')
            if item['name']:
                yield item