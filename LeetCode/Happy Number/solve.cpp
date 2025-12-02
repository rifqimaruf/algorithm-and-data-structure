#include <iostream>
#include <unordered_set>

using namespace std;

bool is_happy(int n)
{
    int sumOfRoot = 0;
    unordered_set<int> sumOfRoots;

    if (n == 1) return true;

    while (n != 1){
        while (n > 0)
        {
            int digit = n % 10;
            sumOfRoot += digit * digit;
            n /= 10;
        }
        n = sumOfRoot;
        
        if(sumOfRoot == 1)
            return true;
        else if (sumOfRoots.find(sumOfRoot) != sumOfRoots.end())
            return false;
        else
            sumOfRoots.insert(sumOfRoot);
        
        sumOfRoot = 0;
    }
    return false;
}

