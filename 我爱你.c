#include<stdio.h>
#include<windows.h>
int main(void)
{ 
      for (printf("\n\n\t\t\tYou love me?\n\n\t\t\tA:YES B:NO"),Sleep(5000);;) 
      {
      	if(GetAsyncKeyState('A'))
      	break; 
      	else printf("\t\t\tI LOVE YOU \n");
      	}
}