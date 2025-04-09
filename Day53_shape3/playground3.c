#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n == 1) 
    {
        printf("*\n");
    }
    else 
    {
        for(int i = 1; i <= n; i++) 
        {
            for(int j = 0; j < i; j++) 
            {
                printf("*");
                if(j < i-1) 
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        for(int i = n-1; i >= 1; i--) 
        {
            for(int j = 0; j < i; j++) 
            {
                printf("*");
                if(j < i-1) 
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}
