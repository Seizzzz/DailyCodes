import scrapy
from xuetang.items import XuetangItem

class xtzxSpider(scrapy.Spider):
    name = "xtzx"
    allowed_domains = ["xuetangx.com/search"]
    start_urls = []
    for i in range(1, 38):
        url = 'https://www.xuetangx.com/search?query=&org=&classify=1&type=&status=&page=' + str(i)
        start_urls.append(url)

    def parse(self, response):
        item = XuetangItem()

        for each in response.xpath('//div[@class="resultListCon"]'):
            item['course'] = "".join(each.xpath('div[2]//p[1]//span//text()').extract())
            item['teacher'] = "".join(each.xpath('div[2]//p[2]//span[1]//span[1]//text()').extract())
            item['university'] = "".join(each.xpath('div[2]//p[2]//span[2]//span[1]//text()').extract())
            item['num_stu'] = each.xpath('div[2]//p[2]//span[3]//text()').extract()[-1].replace(' ', '').replace('\n', '')
            if item['course']:
                yield item
