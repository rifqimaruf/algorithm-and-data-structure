#include <stdio.h>

int factorial(int n) {
    if (n == 1) {  // Base case
        return 1;
    } else {       // Recursive case
        return n * factorial(n - 1);
    }
}

int main() {
    int result = factorial(5);
    printf("Factorial of 5 is %d\n", result);  
    return 0;
}