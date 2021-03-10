# encoding:utf-8
import requests
import time
import os
# import json

# 这里把wozaixiaoyuan_token的内容换为你自己的token，具体看https://violetwsh.com/2021/01/10/wozaixiaoyuan/#more

# wozaixiaoyuan_token = '98f4fd24-bb86-410d-8cb8-941c72dc78cc'
path = os.path.dirname(__file__)
with open(path+"/wexin_token.txt",'r') as fp1:
    wozaixiaoyuan_token = fp1.read().rstrip()
with open(path+"/qmsg_token.txt",'r') as fp2:
    qmsg_token = fp2.read().rstrip()
# print(wozaixiaoyuan_token,qmsg_token,sep='\n')
# exit(1)
# 在qmsg网站中可以找到 https://qmsg.zendee.cn/
# qmsg_token = '6da3dd0a320fbef5ed2b3db0092c679c'

def qmsg_post(content):
    url = 'https://qmsg.zendee.cn/send/'
    url += qmsg_token
    data = {
        'msg': content
    }
    # body=json.dumps(data).encode(encoding='utf-8')
    requests.post(url, data=data)

def HealthCheckIn(time):
    headers = {
        'content-length': '324',
        'cookie': 'SESSION=NGY4ZGYwNGMtZTQ3ZC00ZDRmLTg2MmEtNDRhMDYyOTZlYTAw;path=/;HttpOnly',
        'user-agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.143 Safari/537.36 MicroMessenger/7.0.9.501 NetType/WIFI MiniProgramEnv/Windows WindowsWechat',
        'content-type': 'application/x-www-form-urlencoded',
        'token': wozaixiaoyuan_token,
        'refer': 'https://servicewechat.com/wxce6d08f781975d91/143/page-frame.html',
        'accept-encoding': 'gzip, deflate, br'
    }
    postdata = {
        'answers': '["0","1","36.5"]',
        'latitude': '34.154229',
        'longitude': '108.905732',
        'country': '中国',
        'city': '西安市',
        'township': '韦曲街道',
        'street': '西长安街',
        'district': '长安区',
        'province': '陕西省',
        'areacode': '610116'
    }
    url = 'https://student.wozaixiaoyuan.com/health/save.json'
    s = requests.session()
    r = s.post(url, data=postdata, headers=headers)
    t = r.text
    # 经过测试，t返回的字典里会有一个状态码，登陆成功为0，不成功为-10，对应的就是第8个字符。
    if t[8] == '0':
        qmsg_post("每日"+"打卡成功"+time)
    else:
        qmsg_post("每日"+"打卡失败，可能是token失效，请尽快重新输入"+time)

if __name__ == "__main__":
    while True:
        time_now = time.strftime("%H:%M:%S", time.localtime())
        # 刷新
        if time_now == "00:02:50" or time_now == "00:22:51": 
            # 不知道是奇数还是偶数
            time_send = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
            
            HealthCheckIn(time_send)
            # 健康打卡
            print("finished health\n\n\n\n")
            time.sleep(10)
        else:
            # print("sleep 2 seconds")
            print(time_now+" is running")
            time.sleep(2)  # 停两秒
        
        if time_now == "00:30:05" or time_now == "00:30:06":
            qmsg_post("每日打卡--请检查上条消息是否送达")
            print("program will exit")
            exit(0)
        