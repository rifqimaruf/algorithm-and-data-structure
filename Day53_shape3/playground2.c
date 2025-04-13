#include <stdio.h>

int main()
{
   int n;
   scanf("%d", &n);
   if(n==1)
	printf("*\n");
   else
  {
   for(int i=n; i>=1; i--)
   {
	for(int j=0; j<n-1; j++)
	{
           printf(" ");
	}

	for(int m=0; m<2*i-1; m++)
	{
	   printf("* ");
	}
	printf("\n");
   }
  }
   return 0;
}
