import requests
from lxml import etree
import sqlite3
import random

def main():
    baseurl = "http://xxxy2016.jnu.edu.cn/Category_37/Index"
    datalist = getData(baseurl)
    print(datalist)
    saveData('data.db', datalist)

def get_user_agent():
    '''
    功能: 随机获取UA
    :return: 返回一个随机UA
    '''
    user_agents=[
        "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; AcooBrowser; .NET CLR 1.1.4322; .NET CLR 2.0.50727)",
        "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0; Acoo Browser; SLCC1; .NET CLR 2.0.50727; Media Center PC 5.0; .NET CLR 3.0.04506)",
        "Mozilla/4.0 (compatible; MSIE 7.0; AOL 9.5; AOLBuild 4337.35; Windows NT 5.1; .NET CLR 1.1.4322; .NET CLR 2.0.50727)",
        "Mozilla/5.0 (Windows; U; MSIE 9.0; Windows NT 9.0; en-US)",
        "Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; Win64; x64; Trident/5.0; .NET CLR 3.5.30729; .NET CLR 3.0.30729; .NET CLR 2.0.50727; Media Center PC 6.0)",
        "Mozilla/5.0 (compatible; MSIE 8.0; Windows NT 6.0; Trident/4.0; WOW64; Trident/4.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; .NET CLR 1.0.3705; .NET CLR 1.1.4322)",
        "Mozilla/4.0 (compatible; MSIE 7.0b; Windows NT 5.2; .NET CLR 1.1.4322; .NET CLR 2.0.50727; InfoPath.2; .NET CLR 3.0.04506.30)",
        "Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN) AppleWebKit/523.15 (KHTML, like Gecko, Safari/419.3) Arora/0.3 (Change: 287 c9dfb30)",
        "Mozilla/5.0 (X11; U; Linux; en-US) AppleWebKit/527+ (KHTML, like Gecko, Safari/419.3) Arora/0.6",
        "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.2pre) Gecko/20070215 K-Ninja/2.1.1",
        "Mozilla/5.0 (Windows; U; Windows NT 5.1; zh-CN; rv:1.9) Gecko/20080705 Firefox/3.0 Kapiko/3.0",
        "Mozilla/5.0 (X11; Linux i686; U;) Gecko/20070322 Kazehakase/0.4.5",
        "Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.8) Gecko Fedora/1.9.0.8-1.fc10 Kazehakase/0.5.6",
        "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11",
        "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7_3) AppleWebKit/535.20 (KHTML, like Gecko) Chrome/19.0.1036.7 Safari/535.20",
        "Opera/9.80 (Macintosh; Intel Mac OS X 10.6.8; U; fr) Presto/2.9.168 Version/11.52",
        "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/536.11 (KHTML, like Gecko) Chrome/20.0.1132.11 TaoBrowser/2.0 Safari/536.11",
        "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/21.0.1180.71 Safari/537.1 LBBROWSER",
        "Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; WOW64; Trident/5.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; Media Center PC 6.0; .NET4.0C; .NET4.0E; LBBROWSER)",
        "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; QQDownload 732; .NET4.0C; .NET4.0E; LBBROWSER)",
        "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.84 Safari/535.11 LBBROWSER",
        "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.1; WOW64; Trident/5.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; Media Center PC 6.0; .NET4.0C; .NET4.0E)",
        "Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; WOW64; Trident/5.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; Media Center PC 6.0; .NET4.0C; .NET4.0E; QQBrowser/7.0.3698.400)",
        "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; QQDownload 732; .NET4.0C; .NET4.0E)",
        "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; Trident/4.0; SV1; QQDownload 732; .NET4.0C; .NET4.0E; 360SE)",
        "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; QQDownload 732; .NET4.0C; .NET4.0E)",
        "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.1; WOW64; Trident/5.0; SLCC2; .NET CLR 2.0.50727; .NET CLR 3.5.30729; .NET CLR 3.0.30729; Media Center PC 6.0; .NET4.0C; .NET4.0E)",
        "Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/21.0.1180.89 Safari/537.1",
        "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.1 (KHTML, like Gecko) Chrome/21.0.1180.89 Safari/537.1",
        "Mozilla/5.0 (iPad; U; CPU OS 4_2_1 like Mac OS X; zh-cn) AppleWebKit/533.17.9 (KHTML, like Gecko) Version/5.0.2 Mobile/8C148 Safari/6533.18.5",
        "Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:2.0b13pre) Gecko/20110307 Firefox/4.0b13pre",
        "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:16.0) Gecko/20100101 Firefox/16.0",
        "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11",
        "Mozilla/5.0 (X11; U; Linux x86_64; zh-CN; rv:1.9.2.10) Gecko/20100922 Ubuntu/10.10 (maverick) Firefox/3.6.10"
    ]
    user_agent = random.choice(user_agents)
    return user_agent

def getData(baseurl):
    linklist = []
    datalist = []
    for i in range(1, 24):  # [1,24]
        url = baseurl + '_' + str(i) + ".aspx"
        res = askURL(url)
        html = etree.HTML(res)
        lis = html.xpath('/html/body/div/div[4]/div[2]/div[2]/ul/li')
        for li in lis:
            #  标题
            title = li.xpath('./a/text()')
            if title == []:
                continue
            # print(title)

            #  链接
            link = li.xpath('./a/@href')
            if not link:
                continue
            if '讲座' not in title[0]:
                continue
            link[0] = 'http://xxxy2016.jnu.edu.cn'+link[0]
            # print(link)
            linklist.append(link[0])

    for report_link in linklist:
        res = askURL(report_link)
        html = etree.HTML(res)
        article = html.xpath('//*[@id="fontzoom"]')
        for ar in article:
            # 报告题目
            report_title = ar.xpath('./p/strong[contains(text(),"题")]/parent::p/text()')
            if not report_title:
                report_title = ar.xpath('./p/span[contains(text(),"题目")]/text()')
            if not report_title:
                if not ar.xpath('./p/span/text()'):
                    report_title = ar.xpath('./p[contains(text(),"Title:")]/text()')
                else:
                    report_title = ar.xpath('./p/span/text()')[0]
            if not report_title:
                report_title = ar.xpath('./p/span/span/strong[contains(text(),"题")]/parent::span/text()')
            if not report_title:
                report_title = ar.xpath('./div[1]/text()')
            if not report_title:
                report_title = ar.xpath('/html/body/div[1]/div[4]/div[2]/div[2]/div/h2/text()')
            if type(report_title) != list:
                report_title = ar.xpath('./p/span/strong[contains(text(),"题")]/parent::span/text()')
            if not report_title:
                report_title = ar.xpath('./p/span/strong/span[contains(text(),"题 目")]/../../span/text()')
            if not report_title:
                continue
            if '\xa0' in report_title[0]:
                report_title[0] = report_title[0].replace('\xa0', ' ')
                if report_title[0] == ' ':
                    report_title.remove(report_title[0])
            datalist.append(report_title)
            print(report_title)

            # 报告人
            report_reporter = ar.xpath('./p/strong[contains(text(),"报告人：")]/parent::p/text()')
            if not report_reporter:
                report_reporter = ar.xpath('./p/span[contains(text(),"报告人：")]/text()')
            if not report_reporter:
                report_reporter = ar.xpath('./div[contains(text(),"报告人：")]/text()')
            if not report_reporter:
                report_reporter = ar.xpath('./p/span/strong/span[contains(text(),"报告人：")]/../../span/text()')
            if not report_reporter:
                report_reporter = ar.xpath('./p/span/strong[contains(text(),"报告人：")]/parent::span/text()')
            if not report_reporter:
                report_reporter = ar.xpath('./p/span/span/strong[contains(text(),"报告人")]/parent::span/text()')
            for reporter_index in range(len(report_reporter)):
                report_reporter[reporter_index] = report_reporter[reporter_index].replace('\xa0', '').replace('：', '')
            print(report_reporter)
            datalist.append(report_reporter)

            # 报告时间
            report_date = ar.xpath('./p/strong[contains(text(),"时 \xa0间：") or contains(text(),"时\xa0 间：") or contains(text(),"时间：") or contains(text(),"时\xa0") or contains(text(), "时 \xa0\xa0间：") or contains(text(), "时 \xa0 间：") or contains(text(),"时 间：")]/parent::p/text()')
            if not report_date:
                report_date = ar.xpath('./p/b[2][text()="间："]/parent::p/text()')
            if not report_date:
                report_date = ar.xpath('./p/span[contains(text(),"时间：") or contains(text(),"时 间：")]/text()')
            if not report_date:
                report_date = ar.xpath('./p/span/strong[contains(text(),"时 \xa0间：") or contains(text(),"时\xa0 间：") or contains(text(),"时间：")]/parent::span/text()')
            if not report_date:
                report_date = ar.xpath('./p/span/span/strong[contains(text(),"时 间")]/parent::span/text()')
            if not report_date:
                report_date = ar.xpath('./div[contains(text(),"时 \xa0间")]/text()')
            if not report_date:
                report_date = ar.xpath('./p/span/strong/span[contains(text(),"时 间：")]/../../span/text()')
            if report_date[0][0] < '0' or report_date[0][0] > '9':
                report_date = ar.xpath('./p/strong[contains(text(),"时\xa0 间：")]/parent::p//text()')
            for date_index in range(len(report_date)):
                report_date[date_index] = report_date[date_index].replace('\xa0', ' ').replace('：', '')
            if '时' not in report_date[0]:
                report_date.remove(report_date[0])
            print(report_date)
            datalist.append(report_date)

            # 报告地点
            report_place = ar.xpath('./p/strong[contains(text(),"地 \xa0点：") or contains(text(),"地\xa0 点：") or contains(text(),"地\xa0 \xa0点：") or contains(text(),"地\xa0\xa0 点：") or contains(text(),"地 点：") or contains(text(),"地\xa0") or contains(text(),"地点：")]/parent::p/text()')
            if not report_place:
                report_place = ar.xpath('./p/b[2][text()="点："]/parent::p/text()')
            if not report_place:
                report_place = ar.xpath('./p/span[contains(text(),"地点：") or contains(text(),"地 点：")]/text()')
            if not report_place:
                report_place = ar.xpath('./p/span/span/strong[contains(text(),"地 点")]/parent::span/text()')
            if not report_place:
                report_place = ar.xpath('./div[contains(text(),"地 \xa0点")]/text()')
            if not report_place:
                report_place = ar.xpath('./p/span/strong/span[contains(text(),"地 点：")]/../../span/text()')
            if not report_place:
                report_place = ar.xpath('./p/span/strong[contains(text(),"地\xa0 点：")]/parent::span/text()')
            if not report_place:
                report_place = ar.xpath('./p/b[contains(text(),"地\xa0 点：")]/parent::p/text()')
            if not report_place:
                report_place = ar.xpath('./p/strong/span[contains(text(),"地\xa0 点：")]/../../span/text()')
            for place_index in range(len(report_place)):
                report_place[place_index] = report_place[place_index].replace('\xa0', '').replace('：', '')
            print(report_place)
            datalist.append(report_place)
            university = []
            link_list = []
            university.append('暨南大学')
            link_list.append(report_link)
            datalist.append(university)
            datalist.append(link_list)

    return datalist


def askURL(url):
    # head = {
    #     "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) "
    #                   "Chrome/90.0.4430.212 Safari/537.36"}
    head = {"User-Agent": get_user_agent()}
    # request = urllib.request.Request(url, headers=head)
    # html = ""
    # try:
    #     response = urllib.request.urlopen(request)
    #     html = response.read().decode("utf-8")
    # except urllib.error.URLError as e:
    #     if hasattr(e, "code"):
    #         print(e.code)
    #     if hasattr(e, "reason"):
    #         print(e.reason)
    html = requests.get(url=url, headers=head, proxies={'http': 'http://124.94.251.187:9999'}).text

    return html

def saveData(dbpath, datalist):
    # 创表
    db = sqlite3.connect(dbpath)
    c = db.cursor()
    sql = '''
        create table scutjnu(
        title char(100),
        reporter char(100),
        date char(100),
        place char(100),
        university char(20),
        link char(100));
    '''
    c.execute(sql)
    db.commit()
    db.close()

    conn = sqlite3.connect(dbpath)
    cur = conn.cursor()

    for index in range(0, len(datalist), 6):
        data = []
        for j in range(6):
            datalist[index+j] = str(datalist[index+j]).replace("'", '').replace('[', "'").replace(']', "'")
            data.append(datalist[index+j])

        sql = '''
            insert into scutjnu values(%s);
        ''' % ",".join(data)
        print(sql)
        cur.execute(sql)
        conn.commit()
    cur.close()
    conn.close()

if __name__ == '__main__':
    main()
