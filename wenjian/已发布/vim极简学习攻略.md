
# 前言

笔者使用 vim 很久了,但是一直以来对于 vim 的各种配置、快捷键、插件等的接触都避讳莫深。原因很简单--麻烦。

但是 vim/vi 作为任何一个 linux 系统存在的文本编辑软件,学会使用对于我们来说是非常必要的。

借此机会我会整理一波最快的记忆最少的 vim 使用方法。

# 学习

## 打开

命令行直接使用

```
vim + 文件名 (不存在则新建,存在则打开)
```

## 模式介绍

直接打开默认进入 [`一般模式`](command mode)

`一般模式` 下按下 `a i o` 任意一个进入[`编辑模式`](insert mode)

`一般模式` 下输入 `: / ?` 任意一个进入[`命令行模式`](command-line mode)

被别的模式下按下 `esc` 返回 `一般模式`

## 1.键位(常用)

-   ### 在一般模式下
    -   直接输入 `2↓` 、`10↑` 等移动 其中 `3<enter>` 相当于 `3↓`
    -   `home`、`end` 移动当前列最前面、最后面
    -   大写 `G` 移动到最后,还有 `nG`
    -   `gg` 移动到最前
    -   `dd` 删除一整行,还有 `ndd`
    -   `/word` 当前文件中往光标下搜 word  
        `n` 继续搜 、`N` 反向搜
    -   `x` 相当于 `del`、 `X` 相当于 `backspace`  
        所以 `3x` 、 `10X`
    -   `yy` 复制本行,还有 `nyy`
    -   `dG` 删除直到最后一行所有
    -   `dnG`, `d1G` 删除知道第 n 行所有
    -   本行中 `d0` 删除光标之前 `d$` 删除光标之后
    -   `ynG` 类似复制 `y1G` ,`yG` 复制到文件末,`y0`,`y$` 本行复制
    -   `p` 粘贴到下一列
    -   `u` 撤销 `<ctrl>+r`前进
    -   `.` 重复上个动作
    -   `<ctrl>+v` 视图模式
    -   `:wq`保存退出
    -   `:w filename` 另存为
    -   `:e!` 还原成初始状态
-   ### **_多文件_**

    -   `:e filename` 再打开一个文件
    -   `:files` 查看已打开文件
    -   `:bn` `:bp` 切换文件 (`:bN`也行)
    -   `:sp` 垂直分割 `:vs` 水平分割
    -   `<ctrl>+w+w`切换焦点窗口

-   ### 不太常用(难记)
    -   **`:1,$s/word1/word2/gc`** 解释  
        第一行 到 最后一行 之间 找 word1 替换成 word2  
        参数 c 询问用户

## 2.配置文件.vimrc

.vimrc 文件放置于~/目录下,没有则新建

在这里贴上我的,其他功能可以自己根据需要自行添加,更改后保存重启 vim 生效

```
" 显示中文帮助
if version >= 603
	    set helplang=cn
	        set encoding=utf-8
	endif
" 设置鼠标可用
set mouse=a
" 显示行号
set number
" Tab 键的宽度
set tabstop=4
" 统一缩进为 4
set softtabstop=4
set shiftwidth=4
" 不要使用 vi 的键盘模式，而是 vim 自己的
set nocompatible
" 语法高亮
"set syntax=on
 "Ctrl-A 选中所有内容
map <silent>  <C-A>  gg v G
"按TAB键时命令行自动补齐"
set wildmenu
"开启文件类型检查
filetype indent on

set showmatch
"光标遇到圆括号、方括号、大括号时，自动高亮对应的另一个圆括号、方括号和大括号
set spell spelllang=en_us
"打开英语单词的拼写检查
set history=1000
"Vim 需要记住多少次历史操作
set autoread
"打开文件监视。如果在编辑过程中文件发生外部改变（比如被别的编辑器编辑了），就会发出提示

colorscheme elflord
"设置vim主题配色

```

## 3.插件配置与语法补全

### [vim-plug](https://github.com/junegunn/vim-plug)

```
优点
1. 易于设置：单个文件。无需样板代码。
2. 易于使用：简洁直观的语法
3. 超高速并行安装/更新（与任何的+job，+python，+python3，+ruby，或Neovim）
4. 创建浅克隆，以最大程度地减少磁盘空间使用和下载时间
5. 按需加载可加快启动时间
6. 可以查看和回滚更新
7. 分支/标签/提交支持
8. 更新后挂钩
9. 支持外部管理的插件
```

### 安装 vim-plug

```
mkdir ~/.vim/autoload/
cd ~/.vim/autoload/
wget https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
```

或者直接

```
curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
    https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
```

日常使用时,在`~/.vimrc`文件增加一段

```
call plug#begin('~/.vim/plugged')
--------------
"插件名称


--------------
plug#end()
```

### 语法补全

**_特别(c/c++)_**
在命令行安装 ccls
例如 ubuntu : `sudo apt-get install ccls`

1. 添加插件在配置文件 `~/.vimrc` 的`call plug#begin` 与 `plug#end() `中间

```
Plug 'neoclide/coc.nvim', {'branch': 'release'}
```

2. 命令行直接 vim 进入界面 ,输入`:PlugInstall` 等待安装完成

3. 打开[Language servers](https://github.com/neoclide/coc.nvim/wiki/Language-servers#ccobjective-c)找到自己需要的语法补全配置(c/c++ 直接复制 ccls 的配置文件),复制到剪贴板

4. 输入`:CocConfig` ,按 i 进入编辑模式 ,粘贴刚才复制得到的配置,多种语言配置文件以逗号隔开,最外层补上一对大括号,保存退出

5. 测试补全效果,一般不会报错,报错自己寻找解决办法

# 尾言

至此,常用的 vim 使用方法已经摸索清楚了, 笔者还遇到了不同文件间的复制粘贴等问题,并且顺利找到了解决方法,希望感兴趣的读者自行摸索。
