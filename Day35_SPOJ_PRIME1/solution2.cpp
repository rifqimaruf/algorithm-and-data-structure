#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieve(int max_limit) {
    vector<bool> is_prime(max_limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= max_limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    int n, min, max;
    const int MAX_LIMIT = 1000000000; 
    vector<bool> is_prime = sieve(MAX_LIMIT);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> min >> max;
        if (max > MAX_LIMIT) {
            cout << "Error: Input exceeds maximum limit of " << MAX_LIMIT << endl;
            continue;
        }
        
        for (int j = min; j <= max; j++) {
            if (j <= MAX_LIMIT && is_prime[j]) {
                cout << j << endl;
            }
        }
        cout << endl; 
    }
    return 0;
}