#include <stdio.h>
#define ll long long 

void countLastWord(char* s)
{
   int end=-1, start;
   for(int i=0; s[i] != '\0'; i++)
   {
     if(s[i] != ' ')
     {
	end =i;
     }
   }

   if(end == -1)
   {
	   printf("0 ");
      return;
   }
   start = end;
   while(start >= 0 && s[start] != ' ')
   {
	start--;
   }
   printf("%d \n", end-start);
}

ll main()
{
   char str[100000];
   scanf("%[^\n]s", &str);
  // printf("%s", str);
   countLastWord(str);
   return 0;

}
