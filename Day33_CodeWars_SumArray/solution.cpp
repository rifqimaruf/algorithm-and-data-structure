#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumOfDifferences(const vector<int>& arr)
{
    if (arr.size() <= 1) return 0;
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end(), greater<int>());
    
    int res = 0;
    for (int i = 0; i < sorted_arr.size() - 1; i++)
    {
        res += sorted_arr[i] - sorted_arr[i + 1];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << "sum of diff by this array is: "<< sumOfDifferences(v);

    return 0;
}