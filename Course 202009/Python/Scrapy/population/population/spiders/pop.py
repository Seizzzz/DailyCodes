import scrapy
from population.items import PopulationItem


class PopSpider(scrapy.Spider):
    name = 'pop'
    allowed_domains = ['kylc.com']
    start_urls = ['https://www.kylc.com/stats/global/yearly_overview/g_population_total.html']

    def parse(self, response):
        item = PopulationItem()
        for each in response.xpath("//table[@class='table']/tbody/tr"):
            item['country'] = each.xpath("td[2]/text()").extract()
            if item['country']:
                num = each.xpath("td[5]/text()").extract()[0]
                item['population'] = num[num.find('(') + 1:num.find(')')].replace(',', '')
                yield item
        pass
