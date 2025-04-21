#include <stdio.h>
#include <stdbool.h>
#define ll long long

int main()
{
    ll n, array[9999999];
    ll increment = 0 ; ll total_increment = 0;
    scanf("%lld", &n);
    
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &array[i]);
    }  

    for(int i = 0; i < n; i++)
    {

        if(i==0)
        {
            continue;
        }

        if(array[i] < array[i-1]) 
        {
            increment = array[i-1] - array[i];
            array[i] += increment;
            total_increment += increment;
        }
    } 
    printf("%lld", total_increment);
    return 0;
}