// there is 
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int K, remainder = 0, length = 1; 
    scanf("%d", &K);
    while (length <= K)
    {
        remainder = (remainder * 10 + 1) % K;
        if (remainder == 0)
        {
            printf("%d\n", length);
            return 0;
        }
        length++;
    }
    printf("-2\n");
    return 0;
    
}

// brute force idea
// int main()
// {
//     int K;
//     scanf("%d", &K);
//     long long curr = 1;
//     int length = 1;
//     // brute force search 
//     while (length <= K)
//     {
//         if ((curr % K) == 0)
//           //return lenght of k
//             return printf("%d\n", length);
//         curr = curr * 10 + 1;
//         length++;

        
//     }
//     printf("-2\n");
//     return 0;
// }