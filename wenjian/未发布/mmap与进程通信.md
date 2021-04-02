# 前言
利用mmap进行文件操作以及一些进程通信操作是非常nice的,具体可以参考别的内容了解原理,本文只涉及mmap的使用

## 函数原型和要点
```
        #include <sys/mman.h>
               
        void *mmap(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset);
            addr:指针地址,一般NULL系统自动分配返回
            length:文件长度 可以用int len=lseek(fd,0,SEEK_END)
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

## 一种读写文件方式
```c
int main()
{
    int fd;
    char *p = NULL;
    fd = open("cin.in", O_RDWR); //读的话别选O_TRUNC模式
    if (fd == -1)
        PRINTEXIT("open");

    // lseek(fd, 20, SEEK_END);
    // write(fd, '\0', 1);


    ftruncate(fd, 20); //可存20个有效字符再加一个\0
    
    
    
    
    int len = lseek(fd, 0, SEEK_END);
    p = (char *)mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED)
        PRINTEXIT("mmap failed");
    
    close(fd);//mmap映射成功可以关文件
    

    printf("lenp=%ld,p=%s\n", strlen(p), p); 
    
    //重点
    //p指向文件头,原内容尾为\n\0 有换行键

    //cat的话非变成 原str+\n+新str
    strcat(p, "123456789123456789123456789"); //27

    printf("%s", p); //20

    len = munmap(p, len);//解除mmap映射
    
    if (len == -1)//检查出错
        PRINTEXIT("munmap");
    return 0;
}
```

## 匿名映射

宏 MAP_ANONYMOUS (或MAP_ANON)

`int *p = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);`


`(flags | 宏 然后 fd=-1)`

相当于
```
fd = open("/dev/zero", O_RDWR);
p = mmap(NULL, size, PROT_READ|PROT_WRITE, MMAP_SHARED, fd, 0);
```
## 进程间通信实例




