#include <iostream>

using namespace std;

int odd_count(int n)
{
    return n / 2;
}

int main() 
{
    int input; bool loop = 1; char choice;
    while (loop == 1)
    {
        cout << "Enter a number: "; cin >> input;
        cout << "There is " << odd_count(input) << " odd number below " << input << endl;
        cout << "You want try again (y/n)? "; cin >> choice;
        if (choice == 'n') loop = 0;
    }

    return 0;
}