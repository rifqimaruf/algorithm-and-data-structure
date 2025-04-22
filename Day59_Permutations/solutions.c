#include <stdio.h>
#include <stdbool.h>

#define ll long long
int main()
{
    ll n, total_placement = 0;
    ll array[9999999];
    scanf("%lld", &n);
    bool check = true;
    int j=2;
    if(n==1)
        printf("1");
    else{
        for(int i=0; i<n; i++)
        {
            if(i==0)
            {
                array[i] = j;
                total_placement++;
            }
            else if(j <= n)
            {
                array[i] = j;
                total_placement++;
            }
            j += 2;
            if(j > n)
                j = 1;
            
            // printf("%d ", array[i]);
        }
        for(int i=0; i < n; i++)
        {
            if(array[i+1] - array[i] == 1 || array[i] - array[i+1] == 1)
                check = false;
        }
        // printf("%d \n", total_placement);
        // printf("%s \n", check)
        // for(int i=0; i<n; i++)
        // {
        //     printf("%lld ", array[i]);
        // }

        if(check == true || n == 1)
        {
            for(int i=0; i<n; i++)
            {
                printf("%lld ", array[i]);
            }
        }
        else
        {
            printf("NO SOLUTION");
        }
    }

    return 0;
}