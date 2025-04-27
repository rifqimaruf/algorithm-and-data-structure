#include <stdio.h>
using namespace std;
typedef long long LL;
int main(){
    int t; 
    LL a[30], pow, n;
    scanf("%d", &t);
    pow = 4LL;
    for (int i = 2; i <= 31; i++)
    {
        a[i-1] = (LL)i * pow - 1;
        pow = pow * 2ll;
    }
    while (t--)
    {
        
        scanf("%lld", &n);
        for (int i=1; i <=30; i++)
        {
            if(n < a[i])
            {
                printf("%d\n", i);
                i = 33;}
        }
    }
}