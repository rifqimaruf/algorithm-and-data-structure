#include <iostream>

using namespace std;

int centuryFromYear(int year) {
    return (year + 99) / 100;
    }

int main()
{
    int year;
    cin >> year;
    cout << centuryFromYear(year) << endl;
    return 0;
}