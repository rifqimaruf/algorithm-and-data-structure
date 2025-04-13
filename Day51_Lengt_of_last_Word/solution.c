#include <stdio.h>
#define ll long long

ll main()
{
   char str[10000];
   int count;
   int a = -1, b=-1;
   scanf("%[^\n]s", &str);
   printf("%s\n", str);

   for(int i=0; str[i]!='\0'; i++)
   {
     if(str[i] == ' ')
     {
	 a = b;
	 b = i;
     }
   }

   printf("ini a %d\n", a);
   printf("ini b %d\n", b);
   count = b-a;
   printf("%d ", count);
   return 0;
}



