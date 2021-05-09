#include "../../include/chat.h"
extern int epfd;
extern bool PRINTEXIT;
extern bool DEBUGPRINT;
extern bool WRITE_LOG;

void client_event(int cfd, int event, void *args)
{

    events *ev = (events *)args;
    //IN
    //可能是非阻塞
    int len = 0;

    // while (1)
    if ((len = read(cfd, ev->buf, BUFLEN)) > 0)
    {
        //event_del(ev);

        write(cfd, ev->buf, len);
        // epoll_set(ev, cfd, client_event, ev);
        // epoll_add(EPOLLIN, ev);
    }
    else
    {
        close(cfd);
        DEBUGPRINT("close fd:%d ", cfd);
    }

    // epoll_set(ev, cfd, write1, ev);

    return;
}