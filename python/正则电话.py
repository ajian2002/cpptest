import re


pattern = re.compile(r'(?<=\D)1(3\d{9}|4[57]\d{8})(?=\D)')
string = '''重要的事情说8130123456789遍，我的手机号是13512346789这个靓号，
不是14500998765，也是110或119，王大锤的手机号才是14500998765。'''

lis = re.finditer(pattern, string)
for i in 
