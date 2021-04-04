```python
pattern = re.compile(r'(?<=\D)1(3\d{9}|4[57]\d{8})(?=\D)')

string = '''重要的事情说8130123456789遍，我的手机号是13512346789这个\，
不是14500998765，也不是110或119 没有人是14500998765。'''

lis = re.findall(pattern, string)
print(lis)
# ['3512346789', '4500998765', '4500998765']
```

此时对于14500998765只匹配4500998765
原因在于
```
带有1个括号，其输出的内容就是括号匹配到的内容，而不是整个表达式所匹配到的结果。

不带有括号,其输出的内容就是整个表达式所匹配到的内容。

带有2个括号的，会输出几个元组,显示捕获组匹配到的内容
```
# 解决方案

1.尽量不要使用(多重)括号

2.替换findall函数为finditer函数
原因为


### Python对正则表达式的支持

Python提供了`re`模块来支持正则表达式相关操作，下面是`re`模块中的核心函数。

| 函数                                         | 说明                                                         |
| -------------------------------------------- | ------------------------------------------------------------ |
| compile(pattern, flags=0)                    | 编译正则表达式返回正则表达式对象                             |
| match(pattern, string, flags=0)              | 用正则表达式匹配字符串 成功返回匹配对象 否则返回None         |
| search(pattern, string, flags=0)             | 搜索字符串中第一次出现正则表达式的模式 成功返回匹配对象 否则返回None |
| split(pattern, string, maxsplit=0, flags=0)  | 用正则表达式指定的模式分隔符拆分字符串 返回列表              |
| sub(pattern, repl, string, count=0, flags=0) | 用指定的字符串替换原字符串中与正则表达式匹配的模式 可以用count指定替换的次数 |
| fullmatch(pattern, string, flags=0)          | match函数的完全匹配（从字符串开头到结尾）版本                |
| `findall`(pattern, string, flags=0)            | 查找字符串所有与正则表达式匹配的模式 `返回字符串的列表`        |
| `finditer`(pattern, string, flags=0)           | 查找字符串所有与正则表达式匹配的模式 `返回一个迭代器`          |
| purge()                                      | 清除隐式编译的正则表达式的缓存                               |
| re.I / re.IGNORECASE                         | 忽略大小写匹配标记                                           |
| re.M / re.MULTILINE                          | 多行匹配标记                                                 |

语法替换为
```python
lis = re.finditer(pattern, string)
for i in lis:
    print(i.group())
```
即可正确匹配内容


