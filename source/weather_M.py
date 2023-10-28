import requests
from bs4 import BeautifulSoup
import time

import requests

cookies = {
    'f_city': '%E6%88%90%E9%83%BD%7C101270101%7C',
    'Hm_lvt_080dabacb001ad3dc8b9b9049b36d43b': '1688458910,1688607038,1688622651,1689213844',
    'Hm_lpvt_080dabacb001ad3dc8b9b9049b36d43b': '1689214274',
}

headers = {
    'Accept': '*/*',
    'Accept-Language': 'zh-CN,zh;q=0.9',
    'Connection': 'keep-alive',
    # 'Cookie': 'f_city=%E6%88%90%E9%83%BD%7C101270101%7C; Hm_lvt_080dabacb001ad3dc8b9b9049b36d43b=1688458910,1688607038,1688622651,1689213844; Hm_lpvt_080dabacb001ad3dc8b9b9049b36d43b=1689214274',
    'Referer': 'http://www.weather.com.cn/',
    'User-Agent': 'Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Mobile Safari/537.36',
}


t = time.time()
millisecond = int(t*1000)


response = requests.get(
    'http://d1.weather.com.cn/dingzhi/101270101.html?_=' + str(millisecond),
    params='',
    cookies=cookies,
    headers=headers,
    verify=False,
)
#///////////////////////////////////////////////



response.encoding='utf-8'
source = response.text
source_Loaded = BeautifulSoup(source,features='lxml')
weather_found = source_Loaded.select('.tem')
fl = open('weather.log.txt','w',encoding='gbk')
fl.write(source)
fl.close()
#fl = open('weather_found.log.txt','w',encoding='utf-8')
#fl.write(str(weather_found).replace('<p class="tem">','').replace('<p class="tem">','').replace('<span>','').replace('</span><em>°C</em>','').replace('</span><em>°C</em>','').replace('<div class="tem">','').replace('[','').strip().replace(']','').replace('</p>, ','').replace('</p>, ','').replace('</div>',''))
#fl.close()

