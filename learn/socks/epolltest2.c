#define PRINTEXIT
#include <my/debug.info.h>
#include <sys/epoll.h>
#define PORT 5678
int epfd;
/*
端口复用epolltest2(epfd,多线程（各自events,lfd））
//???
//
//1   2   3   4
//a      
//b    
//c
*/
void *doa(void *a)
{
    char *black = (char *)a;
    black = "";
    //创建监听套接字
    int lfd;
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    //启用端口复用
    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt));
    //填充地址结构体
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    //绑定 ，listen
    socklen_t socklen = sizeof(addr);
    bind(lfd, (struct sockaddr *)&addr, socklen);
    listen(lfd, 128);
    //创建epoll描述符

    //lfs的epoll结构体
    struct epoll_event event;
    event.events = EPOLLIN;                      //EPOLLOUT  EPOLLERR
    event.data.fd = lfd;                         //传出的fd
    epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &event); //挂节点，操作lfd->epfd
    //lfd挂到根节点epfd，带着event结构，事件
    printf("lfd added\n");
    struct epoll_event outevents[1024];
    int cfd;

    while (1)
    {

        int number = epoll_wait(epfd, outevents, 1024, -1); //（）监听
        //-1 阻塞 0 不阻塞 +毫秒
        //return 个数 ，循环上限
        if (number < 0)
            PRINTEXIT("epollwait");
        //printf("%s wakeup %ld\n", black, pthread_self() % 1000);
        //有事件
        for (int i = 0; i < number; i++)
        {
            //outevents[i]
            if (outevents[i].data.fd == lfd) //lfd
            {
                cfd = accept(lfd, (struct sockaddr *)&addr, &socklen); //传入传出
                printf("%s accept %ld \n", black, pthread_self() % 1000);
                //设置cfd不阻塞
                // int flag = fcntl(cfd, F_GETFL);
                // flag |= O_NONBLOCK;
                // fcntl(cfd, F_SETFL, flag);

                //挂到epfd
                //event.events = EPOLLIN | EPOLLET; //ET模式
                event.events = EPOLLIN; //LT模式
                event.data.fd = cfd;    //可以void*
                epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &event);

                continue;
            }
            else if (outevents[i].events & EPOLLIN) //EPOLLIN
            {
                char buf[50];
                cfd = outevents[i].data.fd;
                printf("%sIN  %ld\n", black, pthread_self() % 1000);
                int len = read(cfd, buf, 50);

                if (len == 0)
                {
                    epoll_ctl(epfd, EPOLL_CTL_DEL, cfd, NULL);
                    close(cfd);
                }
                else if (len < 0)
                {
                    perror("read failed");
                    epoll_ctl(epfd, EPOLL_CTL_DEL, cfd, NULL);
                    close(cfd);
                }
                else
                {
                    write(cfd, buf, len);
                }

                continue;
            }
            else //out error
            {
                continue;
            }
        }
    }
    close(lfd);
}
int main()
{
    epfd = epoll_create(100);
    pthread_t thread[4];

    for (int i = 0; i < 4; i++)
    {

        pthread_create(&thread[i], NULL, doa, NULL);
        printf("tread%d[%d]\n", i, thread[i] % 1000);
        sleep(3);
    }

    while (1)
        ;

    close(epfd);
    return 0;
}
