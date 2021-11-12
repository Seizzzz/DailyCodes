import scrapy
from novel.items import NovelItem


class QiumoSpider(scrapy.Spider):
    name = 'qiumo'
    allowed_domains = ['www.1pwx.com']
    start_urls = []

    for i in range(1, 6):
        url = 'https://www.1pwx.com/qiumo/' + str(i)
        start_urls.append(url)

    def parse(self, response):
        item = NovelItem()
        item["content"] = response.xpath('//pre[@id="content"]/text()').extract()[0].replace('\n', '').replace(' ', '')
        item['title'] = response.xpath('//div[@class="page-body"]/h1/text()').extract()[0]
        item["url"] = response.xpath("//@href").extract_first()
        yield item
