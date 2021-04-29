#define MYERROR
#include <my/debug.info.h>
#define LISTENPORTT 5555
int main()
{
    int lfd;
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in lisaddr;
    lisaddr.sin_family = AF_INET;
    lisaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    lisaddr.sin_port = htons(LISTENPORTT);
    //端口复用
    int op = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEPORT, (void *)&op, sizeof(op));
    bind(lfd, (struct sockaddr *)&lisaddr, sizeof(lisaddr));
    listen(lfd, 128);
    fd_set rset;
    FD_ZERO(&rset);
    FD_SET(lfd, &rset);

    struct timeval t;
    fd_set temp = rset;
    int maxfd = lfd;
    socklen_t llen = sizeof(struct sockaddr);

    while (1)
    {
        int count = select(maxfd + 1, &rset, NULL, NULL, NULL); //最大文件描述符+1
        //struct timeval *
        //           0>  定时
        //           0    轮询
        //          NULL 阻塞
        //返回 满足个数（isset判断）
        //传入传出参数
        if (count > 0)
        {
            if (FD_ISSET(lfd, &rset))
            {
                int cfd = accept(lfd, (struct sockaddr *)&lisaddr, &llen);
                FD_SET(cfd, &temp); //加进temp一起恢复
                //更新maxfd
                if (maxfd < cfd)
                    maxfd = cfd;
                if (count == 1) //只有lfd不循环
                {
                    rset = temp; //恢复监听字
                    continue;
                }
            }
            for (int j = lfd + 1; j < maxfd + 1; j++)
            {
                if (FD_ISSET(j, &rset))
                {  
                    char buf[256];
                wcc:
                    memset(buf, 0, sizeof(char) * 256);
                    int a = read(j, buf, 256);
                    printf("read :%d\n", a);
                    sprintf(buf, "read :%d\n", a);
                    if (a > 0)
                    {
                        write(j, buf, strlen(buf));

                        //goto wcc;
                    }
                    else
                    {
                        close(j);
                        FD_CLR(j, &temp);
                        FD_CLR(j, &rset);
                    }
                }
            }
            rset = temp; //恢复监听字
        }
    }
    close(lfd);
}