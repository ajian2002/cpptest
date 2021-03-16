

import requests

from pprint import pprint


apikey = '73770043dcfb322a2dead650635ced94'
url = ('http://api.tianapi.com/txapi/hotreview/index'+'?key='+apikey)
pprint(url)
res = requests.get(url)

if res.status_code == 200:
    data = res.json()
    pprint(data)
d = {'key': apikey, 'num': 10}
pprint(d)
resp = requests.get('http://api.tianapi.com/guonei/', params=d)
if resp.status_code == 200:
    data_model = resp.json()
    # pprint(data_model)
    for news in data_model['newslist']:
        print(news['title'])
        print(news['url'])
        print('-' * 60)
