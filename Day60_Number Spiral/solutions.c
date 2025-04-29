#include <stdio.h>
#define ll long long

int main()
{
    ll n;
    scanf("%d", &n);
    while(n--)
    {
        ll y, x;
        scanf("%d %d", &y, &x);
        ll z = max(y, x);
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
                ans = z2*y;
            }
            else
            {
                ans=z2+2*z-x;
            }
        }
        printf("%d \n", ans);
    }
    return 0;
}