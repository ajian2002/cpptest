<ctrl>+a 命令行开头
<ctrl>+e 命令行最后
<ctrl>+u 删除光标前
<ctrl>+k 删除光标后

范例二：提示使用者 30 秒内输入自己的大名，将该输入字符串作为名为 named 的变量内容 
[dmtsai@study ~]$ read -p "Please keyin your name: " -t 30 named 
Please keyin your name: VBird Tsai <==注意看，会有提示字符喔！ 
[dmtsai@study ~]$ echo ${named} 
VBird Tsai      <==输入的数据又变成一个变量的内容了


