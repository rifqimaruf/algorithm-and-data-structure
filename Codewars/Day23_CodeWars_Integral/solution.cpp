#include <iostream>
#include <string>
using namespace std;

string integrate (int coeff, int expp)
{
    string result = to_string(coeff/(expp+1)) + "x^" + to_string(expp+1);
    return result;
}

int main()
{
    int coeff, expp;
    cout <<"Enter the coefficient, and the exponent: "; cin >> coeff >> expp;
    string result = integrate(coeff, expp);
    cout << result << endl;

    return 0;
}