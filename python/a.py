import os
path=os.path.dirname(__file__)
with open(path+'/'+'1.txt','r') as fp:
    wx=fp.read().rstrip()
print(wx)