#include <stdio.h>

int main()
{
   int n, point;
   scanf("%d", &n);
   point=0;
   for(int i=0; i<n; i++)
   {
       point=i;
       for(int j=n; j>0; j--)
       {
	if(point){
           printf(" ");
  	   point--;
           continue;
	}
	else
           printf("*");
       }
       point +=1;
       printf("\n");
   }
   return 0;
}
