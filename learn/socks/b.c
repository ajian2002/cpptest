#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024
void error_handling(const char *message);

int main(int argc, const char *argv[])
{
    int serv_sock, clnt_sock;
    FILE *readfp;
    FILE *writefp;

    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;
    char buf[BUF_SIZE] = {0};
    if (2 != argc)
    {
        printf("Usage: %s <port> \n", argv[0]);
        exit(1);
    }
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (-1 == serv_sock) error_handling("socket() error");

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family      = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port        = htons(atoi(argv[1]));
    if (-1 == bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)))
        error_handling("bind() error");
    if (-1 == listen(serv_sock, 5)) error_handling("listen() error");
    clnt_adr_sz = sizeof(clnt_adr);
    clnt_sock   = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);
    //通过将描述符转化为读/写模式FILE结构指针，实现I/O分离。通过FILE结构体指针像使用文件一样使用套接字(linux下一切皆是文件)
    readfp  = fdopen(clnt_sock, "r");
    writefp = fdopen(dup(clnt_sock), "w");
    // dup复制文件描述符，通过复制出的文件描述符能访问同一文件或套接字
    //	writefp = fdopen(clnt_sock, "w");
    ////可以注释上一行使用这一行，同样是分离I/O流，不同的是，这样使用的话下面的代码中的fclose(writefp)也该注释起来，因为close()会关闭参数所指文件，也就关闭了writefp指针相关文件描述符，由于这个文件描述符没有被dup，是唯一的，因此套接字也会被关闭，这样的话fclose(writefp)之后的fgets()将不能正常工作

    fputs("FROM SERVER: Hi~ client? \n", writefp);
    fputs("I love all of the world \n", writefp);
    fputs("You are awesome! \n", writefp);
    fflush(writefp);  //将标准I/O缓冲中的内容刷新到writefp所指处

    shutdown(fileno(writefp), SHUT_WR);
    //关闭套接字输出流，并发送EOF(无论复制了多少个描述符，调用shutdown均半关闭且发送EOF)
    fclose(writefp);
    //关闭dup复制出的文件描述符所转换的FILE指针相关的文件描述符，这样只是间接关闭了dup复制出来的文件描述符，由于还存在原来的那个文件描述符(被dup复制的文件描述符)，所以套接字并不会被关闭，下面fgets()正常工作

    fgets(buf, sizeof(buf), readfp);
    fputs(buf, stdout);
    fclose(readfp);
    //关闭readfp相关的文件描述符(剩下的那个唯一的文件描述符)，这样也就关闭了套接字
    //注:1、通过fclose()关闭了套接字后无需再使用close()去关闭，且fclose关闭套接字后套接字的文件描述符已经没有意义
    // 2、shutdown()只能关闭流并发送EOF，并不能让操作系统销毁套接字，所以要关闭套接字是需要使用fclose()或close()直接或间接
    //的关闭唯一的文件描述符
    return 0;
}

void error_handling(const char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
