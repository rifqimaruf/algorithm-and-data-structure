#include <stdio.h>

#define ll long long

int main()
{
   ll n;
   ll m[900000];
   ll value = 0;
   ll total = 0;
   scanf("%lld", &n);
   for(ll i=0; i<n-1; i++)
   {
       scanf("%lld", &m[i]);
       value += m[i];
   }
   for(ll j=1; j<=n; j++)
   {
      total += j;
   }
   printf("%lld\n", total-value);
   return 0;
}
