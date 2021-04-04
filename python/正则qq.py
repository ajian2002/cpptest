import re


def ttry(name):

    try:
        print(name)
    except:
        print("error"+name)
        exit(1)


s = input()

# ^和$的意义就变成了匹配行的开始处和结束处。
# 全匹配
username = re.match(r'^[0-9a-zA-Z]{6,20}$', s)
ttry(username)
s = input()
# 匹配每个单词
qqnumber = re.match(r'[0-9]{4,11}', s)
ttry(qqnumber)
