
#define MYERROR
#include <my/debug.info.h>
// /*

// /* Structure describing an Internet socket address.  */
// struct sockaddr_in
// {
//     __SOCKADDR_COMMON(sin_);
//     in_port_t sin_port;      /* Port number.  */
//     struct in_addr sin_addr; /* Internet address.  */

//     /* Pad to size of `struct sockaddr'.  */
//     unsigned char sin_zero[sizeof(struct sockaddr) -
//                            __SOCKADDR_COMMON_SIZE -
//                            sizeof(in_port_t) -
//                            sizeof(struct in_addr)];
// };
// */

// /* Structure describing a generic socket address.  */
// struct sockaddr
// {
//     __SOCKADDR_COMMON(sa_); /* Common data: address family and length.  */
//     char sa_data[14];       /* Address data.  */
// };

#define MAXLINE 256
int main(int argc, char **argv)
{
    int sockfd, n, sockfd6;
    char buf[MAXLINE];
    memset(buf, 0, sizeof(char) * MAXLINE);
    if (argc != 3)
        PRINTEXIT("argc not 3");
    struct sockaddr_in addr;
    // struct sockaddr_in6 addr6;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        PRINTEXIT("socket error");
    // socket函数创建一个网际（AF_INET）字节流（SOCK_STREAM）套接字，它是TCP套接字的花哨名字。该函数返回一个小整数描述符，以后的所有函数调用（如随后的connect和read）就用该描述符来标识这个套接字。
    // if ((sockfd6 = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    //     PRINTEXIT("socket error");
    // bzero()
    memset(&addr, 0, sizeof(addr));
    // memset(&addr6, 0, sizeof(addr6));

    //服务器的IP地址和端口号填入一个网际套接字地址结构
    //置地址族为AF_INET
    addr.sin_family = AF_INET;
    // addr.sin_port = 13;
    addr.sin_port = htons(atoi(argv[2]));
    //     htons
    // addr6.sin6_family = AF_INET6;
    // addr6.sin6_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0)
        PRINTEXIT("inet");
    // if (inet_pton(AF_INET6, argv[1], &addr6.sin6_addr) <= 0)
    //     PRINTEXIT("inet");

    //调用库函数htons（“主机到网络短整数”）去转换二进制端口号，又调用库函数inet_pton（“呈现形式到数值”）去把ASCII命令行参数（例如运行本例子所用的206.168.112.96）转换为合适的格式。

    //数组ip -->>struct
    // Internet number in bufferstarting at CP to the binary network format and
    // store result for interface type AF in buffer starting at BUF.

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        // connect函数应用于一个TCP套接字时，将与由它的第二个参数指向的套接字地址结构指定的服务器建立一个TCP连接
        PRINTEXIT("connect error");

    printf("1\n");

    // if (connect(sockfd6, (struct sockaddr *)&addr6, sizeof(addr6)) < 0)
    // connect函数应用于一个TCP套接字时，将与由它的第二个参数指向的套接字地址结构指定的服务器建立一个TCP连接
    // PRINTEXIT("connect error");
    while ((n = read(sockfd, buf, MAXLINE)) > 0)
    {
        buf[n] = 0;
        printf("%s\n", buf);
        if (fputs(buf, stdout) == EOF)
            PRINTEXIT("fputs");
    }
    if (n < 0)
        PRINTEXIT("read");
    // while ((n = read(sockfd6, buf, MAXLINE)) > 0)
    // {
    //     buf[n] = 0;
    //     printf("%s\n", buf);
    //     if (fputs(buf, stdout) == EOF)
    //         PRINTEXIT("fputs");
    // }
    // if (n < 0)
    //     PRINTEXIT("read");
    return 0;
}
