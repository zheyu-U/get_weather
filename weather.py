import requests
import time
from bs4 import BeautifulSoup


import requests

t = time.time()
millisecond = int(t*1000)

fl = open('log.log','a',encoding='utf-8')
fl.write("[INFO]" + str(t) + ":Step two:Start!\n")
fl.close()


cookies = {
    'f_city': '%E6%88%90%E9%83%BD%7C101270101%7C',
    'Hm_lvt_080dabacb001ad3dc8b9b9049b36d43b': '1688458910,1688607038',
    'Hm_lpvt_080dabacb001ad3dc8b9b9049b36d43b': '1688616503',
}

headers = {
    'Accept': '*/*',
    'Accept-Language': 'zh-CN,zh;q=0.9',
    'Connection': 'keep-alive',
    # 'Cookie': 'f_city=%E6%88%90%E9%83%BD%7C101270101%7C; Hm_lvt_080dabacb001ad3dc8b9b9049b36d43b=1688458910,1688607038; Hm_lpvt_080dabacb001ad3dc8b9b9049b36d43b=1688616503',
    'Referer': 'http://www.weather.com.cn/',
    'User-Agent': 'Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Mobile Safari/537.36',
}

t = time.time()
millisecond = int(t*1000)


#http://d1.weather.com.cn/sk_2d/101270101.html?_=1688622843932
res = requests.get(
    'http://d1.weather.com.cn/sk_2d/101270101.html?_='+ str(millisecond),
    params='',
    cookies=cookies,
    headers=headers,
    verify=False,
)


#通过http://www.weather.com.cn/weather1d/101270101.shtml
# https://e.weather.com.cn/mweather/101270101.shtml 无法爬到当前天气
#爬到的代码 比 浏览器显示的代码 正好缺失了 当前天气 这一部分

res.encoding='UTF-8'
Htext = res.text
#print(Htext)



fl = open('weathersource.log.txt','w',encoding='gbk')
fl.write(Htext.replace('var dataSK=','').replace('"tempf"',''))
fl.close()

t = time.time()
millisecond = int(t*1000)

fl = open('log.log','a',encoding='utf-8')
fl.write("[INFO]" + str(t) + ":Step two:Done!\n")
fl.close()
print("Step two:Done!")

