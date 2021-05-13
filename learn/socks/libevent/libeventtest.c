#include <my/debug.info.h>
#include <event.h>
#include <event2/bufferevent.h>
#define PORT 5678
void lfdaccept(int a, short b, void *c)
{
    return;
}
int main()
{
    struct event_base *base = event_base_new();

    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    {
    int lfd; //lfd
    {
        lfd = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htons(INADDR_ANY);
        addr.sin_port = htons(PORT);
        bind(lfd, (struct sockaddr *)&addr, sizeof(addr));
        listen(lfd, 128);
    }
    bufferevent_socket_new(base, lfd, BEV_OPT_CLOSE_ON_FREE);
    

    //创建事件
    struct event *lfdevent = event_new(base, lfd, EV_PERSIST, lfdaccept, NULL);
    // struct event *lfdevent =bufferevent_socket_new(base, lfd, BEV_OPT_CLOSE_ON_FREE);
}