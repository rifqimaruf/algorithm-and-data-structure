#include <stdio.h>
#include <stdbool.h>

#define ll long long

int main()
{
   ll n;
   scanf("%lld", &n);
   ll m[1000000];
   for(ll i = 0; i < n-1; i++)
   {
      scanf("%lld", &m[i]);
      //printf("%lld", m[i]);
   }
   for(ll p = 1; p <= n; p++)
   {
      bool found = false;
      for(ll j = 0; j < n - 1; j++)
      {
         if(m[j] == p)
          {
            found = true;
//            printf("%d ", found);
            break;
          }
      }
      if(!found)
      {
          printf("%lld\n", p);
          return 0;
          }
    }
}
