#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

// for debugging
// void printVector(const vector<int> primes)
// {
//     cout << "Primes: ";
//     for (int i = 0; i < primes.size(); ++i) 
//     {
//         cout << primes[i] << (i == primes.size() - 1 ? "" : ", "); 
//     }
//     cout << endl;
// }

int main()
{
    vector<int> primes;
    primes.push_back(2);

    for (int i=3; i <= 32000; i+=2)
    {
        bool isprime = true;
        int cap = sqrt(i) + 1;

        for (int p = 0; p < primes.size(); p++)
        {
            if(primes[p] >= cap) break;
            if(i % primes[p] == 0)
            {
                isprime = false;
                break;
            }
        }
        if (isprime) primes.push_back(i);
    }
    // printVector(primes);

    int T, N, M;
    cin >> T;

    while(T--)
    {
        cin >> M >> N;

        int cap = sqrt(N) + 1;

        set<int> notprime;
        
        for(int p = 0; p < primes.size(); p++)
        {
            if(primes[p] >= cap) break;
            int start;
            
            if(primes[p] >= M) start = (primes[p]) * 2;
            else start = M + ((primes[p] - M % primes[p]) % primes[p]);

            for (int j = start; j <= N; j += primes[p])
            {
                notprime.insert(j);
            }
        }

        for (int i = M; i <= N; i++) {
            if (notprime.count(i) == 0 && i != 1) {
                cout << i << endl;
            }
        }
        cout << endl;
    }
    return 0;
}