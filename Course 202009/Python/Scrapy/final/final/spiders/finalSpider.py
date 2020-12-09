import scrapy
import datetime
from final.items import FinalItem

class FinalspiderSpider(scrapy.Spider):
    name = 'final'
    allowed_domains = ['voice.baidu.com']
    start_urls = ['https://voice.baidu.com/act/newpneumonia/newpneumonia/']

    def parse(self, response):
        item = FinalItem()
        table = response.xpath('//div[@id="foreignTable"]')

        infotime = datetime.datetime.now()
        datatime = "%d.%d.%d" % (infotime.year, infotime.month, infotime.day)

        native = response.xpath('//div[@id="ptab-0"]')
        item['country'] = "中国"
        item['date'] = datatime
        item['increase'] = "".join(native.xpath('div[1]/div[2]/div[1]/div[3]/span/text()').extract()[0][1:])
        item['exist'] = "".join(native.xpath('div[1]/div[2]/div[1]/div[2]/text()').extract())
        item['total'] = "".join(native.xpath('div[1]/div[3]/div[1]/div[2]/text()').extract())
        item['cured'] = "".join(native.xpath('div[1]/div[3]/div[3]/div[2]/text()').extract())
        item['death'] = "".join(native.xpath('div[1]/div[3]/div[4]/div[2]/text()').extract())
        yield item

        for each in table.xpath('table/tbody/tr/td/table/tbody/tr'):
            item['country'] = "".join(each.xpath('td[1]/a/div[1]/text()').extract())
            if not item['country']:
                item['country'] = "".join(each.xpath('td[1]/div[1]/text()').extract())
            item['date'] = datatime
            item['increase'] = "".join(each.xpath('td[2]/text()').extract())
            item['exist'] = "".join(each.xpath('td[3]/text()').extract())
            item['total'] = "".join(each.xpath('td[4]/text()').extract())
            item['cured'] = "".join(each.xpath('td[5]/text()').extract())
            item['death'] = "".join(each.xpath('td[6]/text()').extract())
            yield item
        pass
