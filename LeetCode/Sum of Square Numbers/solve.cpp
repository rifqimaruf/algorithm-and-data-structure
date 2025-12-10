#include <iostream>
#include <cmath>

using namespace std;

bool judgeSquareSum(int c)
{
    int a, b = 0;
    for (a = 0; a <= sqrt(c); a++)
    {
        b = sqrt(c - a * a);
        if (a * a + b * b == c)
            return true;
    }
    for (b = 0; b <= sqrt(c); b++)
    {
        a = sqrt(c - b * b);
        if (a * a + b * b == c)
            return true;
    }
    return false;
}

int main()
{
    int c;
    cin >> c;
    if (judgeSquareSum(c))
        cout << "true\n";
    else
        cout << "false\n";  
    return 0;
}