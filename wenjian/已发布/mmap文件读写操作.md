# 前言

利用 mmap 进行文件操作以及一些进程通信操作是非常 nice 的,具体可以参考别的内容了解原理,本文只涉及 mmap 的使用

# 函数原型和要点

```c
#include <sys/mman.h>
void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);
    addr:指针地址,一般NULL系统自动分配返回
    length:文件长度 可以用`int len=lseek(fd,0,SEEK_END)`
    prot:读写模式 可选 PROT_READ和 PROT_WRITE ,读写则用 | 连接
    flags:修改到文件选MAP_SHARED,不更改文件选MAP_PRIVATE
    fd: 使用mmap需要提前open文件
        mmap需要读权限
        mmap<=open权限
    对于新建文件提前使用 `ftruncate(fd, 20);`等确保文件大小不为0(拓展文件)
    offset:偏移量 4k的整数倍    0 开头不偏移
    return:返回一个指针指向文件流开头 常用char*
int munmap(void *addr, size_t length);
    addr:指向映射开头的指针
    length:与mmap参数中的len相同
    return: -1 出错
```

# 单进程读写实例

## 1.打开文件(大于等于只读权限,不能只写)

```c
    int fd = open("cin.in", O_RDWR); //读的话别选O_TRUNC模式
```

## 2.扩展文件(可选,保证文件大小不为 0)

```c
    ftruncate(fd, 20); //可存20个有效字符再加一个\0
    // lseek(fd, 20, SEEK_END);
    // write(fd, '\0', 1);
    
```

## 3.建立映射(成功可以关文件)

```c
int len = lseek(fd, 0, SEEK_END);//获得文件长度
char*p=NULL;
p = (char *)mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
if (p == MAP_FAILED)
{   
    print("mmap failed");
    exit(-1);
}
else
    close(fd);//mmap映射成功可以关文件
```
## 4.读写文件

### 读文件
```c
printf("%s\n", p);
```

### 写文件(p指向文件，可对p0 p1 赋值)
```c
    //p指向文件头,原内容尾为\n\0 有换行键
    //cat的话非变成 原str+\n+新str
    strcat(p, "123456789123456789123456789"); 
    printf("%s", p); //20
```

## 5.解除映射
```c
    len = munmap(p, len);//解除mmap映射
    if (len == -1)//检查出错
        PRINTEXIT("munmap");
```

# 父子进程通信（匿名映射）

**父子进程通信可以借助匿名映射完成，不需要自己指定文件**
>注意事项：

> 1.匿名通信仅能父子通信，无血缘关系进程不可

> 2.无法区分父子进程对文件的权限，父子进程权限相同共享

> 3.文件映射在fork之前


宏 MAP_ANONYMOUS (或 MAP_ANON)

`p = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);`

>(flags | 宏 然后 fd=-1)

相当于

```c
fd = open("/dev/zero", O_RDWR);
p = mmap(NULL, size, PROT_READ|PROT_WRITE, MMAP_SHARED, fd, 0);
```
`


# 非血缘进程通信
> 必须显式指明文件





