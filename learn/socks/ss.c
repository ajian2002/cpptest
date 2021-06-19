#define MYERROR
#include "../../include/debug.info.h"
#define MAXLINE 256

int main(int argc, char **argv) {
  struct sockaddr_in severaddr;
  severaddr.sin_family = AF_INET;
  severaddr.sin_port = htons(3000);
  severaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  int so = socket(AF_INET, SOCK_STREAM, 0);
  bind(so, (struct sockaddr *)&severaddr, sizeof(struct sockaddr));
  listen(so, 10);
  int newso;
  struct sockaddr_in clientaddr;
  socklen_t len = sizeof(struct sockaddr_in);
  if ((newso = accept(so, (struct sockaddr *)&clientaddr, &len)) < 0) {
    PRINTEXIT("accept error");
  }
  int cfd = newso;
  fcntl(cfd, F_SETFL, fcntl(cfd, F_GETFL, 0) | O_NONBLOCK);

  sleep(10);
//   char *buf = malloc(4096);
  int re = 0;
  char buf[1000];
  int n = 0;
  while (0 != (re = recv(cfd, buf, sizeof(buf),0))) {
    if (re < 0) {
      printf("%s\n", strerror(errno));
    }
    if (re > 0) continue;
  }
  printf("ret=0,buf:%s\n", buf);
  close(so);
  close(newso);
  return 0;
}
