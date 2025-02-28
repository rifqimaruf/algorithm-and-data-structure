#include <iostream>

using namespace std;

bool isPrime(int n) {
  
    if (n == 1 )
        return false;

    for (int i = 2; i < n; i++) {
      
        if (n % i == 0)
            return false;
    }
  
      return true;
}


int main()
{
    int n, min, max;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> min >> max;
        for (int i = min; i <= max; i++)
        {
            if(isPrime(i))
                cout << i << endl;
        }
    }
    return 0;
}