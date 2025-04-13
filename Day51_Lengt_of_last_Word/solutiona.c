#include <stdio.h>
#include <stdlib.h>

int main()
{
   char array[12323];
   scanf("%[^\n]s", &array);
   printf("%d", sizeof(array));
   return 0;
 
}
