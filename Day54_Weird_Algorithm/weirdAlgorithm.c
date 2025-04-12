#include <stdio.h>
#define ll long long
void rec(ll n)
{
   printf("%lld ", n);
   if(n == 1)
      return;
   if(n%2 == 0)
       return rec(n/2);
   return rec(3*n +1);
}
int main()
{
   ll n;
   if(scanf("%lld", &n) !=1)
   {
       fprintf(stderr, "gagal membaca input\n");
       return 1;
   }
   rec(n);
   return 0;
}
