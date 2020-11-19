#include <stdio.h>
#include <string.h>
int main()
{
  /*
  int a[2][2] = {1, 3, 5, 7};

  for (int i = 0; i < 2; i++)
  {
    for (int ii = 0; ii < 2; ii++)
    {
      printf("%d ", a[i][ii]);
    }
    printf("\n");
  }
  printf("%d %d %d %d", **a + 1, *(*(a + 1) + 1), **a, **(a + 1));
*/
  /*char B = 'A';
  char *b = &B;
  int C = -10;
  int *c = &C;
  printf("%p\n%p\n", b, c);
  printf("%d\n%d\n", *(int *)b, *(char *)c);
  */
  //printf("%d", *c); //   (int *)b为b十进制地址
  //1644105793
  //-10
  // printf("%d\n", printf("XiyouLinux\n"));
  // printf("%d\n", printf("Xiyou\0Linux\n"));
  int a[2][2];
  printf("%p %p %p\n", &a, &a[0], &a[0][0]);
  printf("%p %p %p\n", &a + 1, &a[0] + 1, &a[0][0] + 1);
  char x[] = "LinuxGroup\t\106F\bamily";
  printf("%s", x);
  printf("%zu %d", sizeof(x), strlen(x));
}