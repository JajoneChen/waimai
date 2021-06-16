import requests
from lxml import etree
import sqlite3
import re
import time
import random
import urllib.request

def main():
    baseurl = "http://www2.scut.edu.cn/sse/xshd/list"
    datalist = getData(baseurl)
    print(datalist)
    saveData('data.db', datalist)

report_title = re.compile(r'报告题目：(.*?)[\xa0|报|<]')#报告题目
report_date = re.compile('\d{4}[年|-]\d{1,2}[月|-]\d{1,2}日*')#报告时间
report_reporter = re.compile(r'报 *告 *人[：|:] *\xa0*(.*?)[主|\xa0|报告时间|地]')#报告人
report_reporter2 = re.compile(r'汇报人：(.*?)汇')
report_place = re.compile('[报告]*地[ |\xa0]*点[：|:](.*?)[\xa0|摘要$|题目|时间|欢迎|会议|内容|讲]')#报告地点

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
    datalist = []
    report_datalist = []
    Link = []
    for i in range(1, 17):  # [1,17]
        if i <= 10:
            url = baseurl + str(i) + '.htm'
        else:
            url = baseurl + str(i) + '.psp'
        res = askURL(url)
        html = etree.HTML(res)
        lis = html.xpath('/html/body/div[1]/div[3]/div[2]/div/div[1]/div[3]/div[1]/div[1]/ul/li')
        for li in lis:
            #  链接
            link = li.xpath('./span[1]/a/@href')
            if link[0] == 'null':
                continue
            if 'page' not in link[0]:
                continue
            if 'http' not in link[0]:
                link[0] = 'http://www2.scut.edu.cn'+link[0]
            Link.append(link[0])

    for l in Link:
        res = askURL(l)
        html = etree.HTML(res)
        article = ""
        divs = html.xpath('//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/div[2]/div/div//text()')
        n_time = html.xpath('//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/p/span[1]/text()')[0]
        article = article.join(divs)
        if ('信息安全' not in article) and ('密码' not in article) and ('information security' not in article) and ('密码学' not in article) and ('cryptography' not in article) and ('cryptology' not in article):
            continue
        # article = "".join(article.split())
        re_place = []
        re_date = []
        re_title = []
        re_reporter = []
        re_link = []
        notice_time = []
        re_link.append(l)

        # 报告题目
        title = re.findall(report_title, article)
        if not title:
            title = html.xpath('//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/div[2]/div/div/p[2]/span/span[contains(text(),"题目")]/text()|'
                               '//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/div[2]/div/div/p[4]/font[contains(text(),"题目")]/text()|'
                               '//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/div[2]/div/div/p[3]/span[contains(text(),"题目")]/parent::p/span[2]/text()|'
                               '//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/div[2]/div/div/p[2]/span/span/span/span/span[1]/span[contains(text(),"题")]/parent::span/parent::span/span[2]/strong/text()|'
                               '//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/div[2]/div/div/p[8]/span/span[contains(text(),"题")]/text()')
        if not title:
            continue
        if title[0] == '':
            title = html.xpath('//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/div[2]/div/div/p[1]/span[2]/text()|'
                               '//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/div[2]/div/div/p[2]/span/span[contains(text(),"题目")]/text()')
        if '并行程序路径覆盖测试' in title[0]:
            title = html.xpath('//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/div[2]/div/div/p[5]/span/span/strong/text()')
            b = html.xpath('//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/div[2]/div/div/p[9]/span/span/strong/text()')
            c = html.xpath('//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/p/span[1]/text()')
            d = html.xpath('//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/div[2]/div/div/p[2]/span[3]/strong/text()')
            e = html.xpath('//*[@id="page-content-wrapper"]/div[2]/div/div/div[2]/div/div/div/div[2]/div/div/p[3]/span/span/strong//text()')
            f = ['华南理工大学软件学院']
            re_title.append(str(title[0]).replace('会议主题：', ''))
            re_reporter.append(b[0].replace('主持人 ：', ''))
            c1 = [str(c[0]).replace('发布时间：', '')]
            notice_time = c1
            d[0] = '2020' + d[0].replace('.', '-')
            if d[0][6] == '-':  # xxxx-xx-xx
                d[0] = d[0][:5] + '0' + d[0][5:]
            if len(d[0]) < 10:
                d[0] = d[0][:8] + '0' + d[0][8:]
            re_date.append(str(d[0]))
            re_place.append(str(e[0]).replace('\xa0', ''))
            report_datalist.append(re_title)
            report_datalist.append(re_reporter)
            report_datalist.append(notice_time)
            report_datalist.append(re_date)
            report_datalist.append(re_place)
            report_datalist.append(['华南理工大学软件学院'])
            report_datalist.append(re_link)
            continue

        for i in range(len(title)):
            re_title.append(str(title[i]))
        report_datalist.append(re_title)

        # 报告人
        reporter = re.findall(report_reporter, article)
        if not reporter:
            reporter = re.findall(report_reporter2, article)
        for i in range(len(reporter)):
            re_reporter.append(str(reporter[i]))
        report_datalist.append(re_reporter)

        # 通知时间
        n_time = n_time.replace('发布时间：', '')
        if n_time[6] == '-': # xxxx-xx-xx   xxxx-xx-x
            n_time = n_time[:5]+'0'+n_time[5:]
        if len(n_time) < 10:
            n_time = n_time[:8]+'0'+n_time[8:]
        notice_time.append(n_time)
        report_datalist.append(notice_time)

        # 报告时间
        date = re.findall(report_date, article)
        for i in range(len(date)):
            date[i] = date[i].replace('\xa0', ' ').replace('年', '-').replace('月', '-').replace('日', '')
            if date[i][6] == '-':  # xxxx-xx-xx
                date[i] = date[i][:5] + '0' + date[i][5:]
            if len(date[i]) < 10:
                date[i] = date[i][:8] + '0' + date[i][8:]
            re_date.append(str(date[i]))
            break
        report_datalist.append(re_date)

        # 地点
        place = re.findall(report_place, article)
        for i in range(len(place)):
            if place[i][-1] == '告':
                place[i] = place[i].replace('报告', "")
            if place[i][-1] == '始':
                place[i] = place[i].replace('开始', '')
            re_place.append(str(place[i]))
        report_datalist.append(re_place)

        report_datalist.append(['华南理工大学软件学院'])

        report_datalist.append(re_link)
    return report_datalist


def askURL(url):
    # head = {
    #     "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
    #     "Accept-Encoding": "gzip, deflate",
    #     "Accept-Language": "zh-CN,zh;q=0.9",
    #     "Connection": "keep-alive",
    #     "Cookie": "clwz_blc_pst_WAFx2dwww2x2dzq=3804309194.20480; JSESSIONID=3523CDDC95E437352C333A19AD36AF7D",
    #     "Host": "www2.scut.edu.cn",
    #     "Upgrade-Insecure-Requests": "1",
    #     "User-Agent": "User-Agent:Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36"}
    head = {"User-Agent": get_user_agent()}
    request = urllib.request.Request(url, headers=head)
    html = ""
    try:
        response = urllib.request.urlopen(request)
        html = response.read().decode("utf-8")
    except urllib.error.URLError as e:
        if hasattr(e, "code"):
            print(e.code)
        if hasattr(e, "reason"):
            print(e.reason)
    return html


def saveData(dbpath, datalist):
    # 创表
    db = sqlite3.connect(dbpath)
    c = db.cursor()
    sql = '''
        create table scut(
        report_title char(100),
        report_reporter char(100),
        notice_time char(100),
        report_date char(100),
        report_place char(100),
        university char(20),
        link char(100));
    '''
    c.execute(sql)
    db.commit()
    db.close()

    conn = sqlite3.connect(dbpath)
    cur = conn.cursor()

    for index in range(0, len(datalist), 7):
        data = []
        for x in range(7):
            if not datalist[index+x]:
                data.append(str(datalist[index+x]).replace('[', "").replace(']', 'null'))
            else:
                data.append(str(datalist[index+x]).replace("'", '').replace('[', "'").replace(']', "'"))

        sql = '''
            insert into scut values(%s);
        ''' % ",".join(data)
        print(sql)
        cur.execute(sql)
        conn.commit()
    cur.close()
    conn.close()


if __name__ == "__main__":
    main()
