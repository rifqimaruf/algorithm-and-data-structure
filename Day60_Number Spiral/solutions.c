#include <stdio.h>

#define ll long long

int main()
{
    ll n;
    scanf("%lld", &n);
    while(n--)
    {
        ll y, x;
        scanf("%lld %lld", &y, &x);
        ll z = (y > x ? y : x);
        ll z2 = (z-1) * (z-1), ans;
        if(z%2)
        {
            if(y==z)
            {
                ans = z2 + x;
            } 
            else
            {
                ans = z2+2*z-y;
            }
        }
        else
        {
            if(x==z)
            {
                ans = z2 + y;
            }
            else
            {
                ans=z2+2*z-x;
            }
        }
        printf("%lld \n", ans);
    }
    return 0;
}