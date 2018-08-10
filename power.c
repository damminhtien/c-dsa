#include <stdio.h>
#include <conio.h>

double power(double x, int n)
{
   int tmp = 1;
   
   if(n>0){
      tmp = power(x,n/2);
      if(n%2==0) 
        tmp = tmp*tmp;
      else
        tmp = tmp*tmp*x;
   }   
   return tmp;
}

int main()
{
    printf("power(2,5)=%5.2f",power(2,5));
    getch();
    return 0;
}
