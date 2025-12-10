#include <stdio.h>
#include <stdlib.h>

unsigned long long square_digits(unsigned n) {
    if (n == 0) {
        return 0;
    }

    int arr[10]; 
    int digits = 0;
    unsigned temp = n;

    while (temp > 0) {
        arr[digits] = temp % 10;
        temp /= 10;
        digits++;
    }

    unsigned long long result = 0;
    for (int i = digits - 1; i >= 0; i--) {
        int squared = arr[i] * arr[i];
        if (squared >= 10) {
            result *= 100;
        } else {
            result *= 10;
        }
        result += squared;
    }

    return result;
}



int main()
{
    int number = 9119;
    unsigned long long result = square_digits(number);
    printf("Result: %llu\n", result);
    return 0;
}