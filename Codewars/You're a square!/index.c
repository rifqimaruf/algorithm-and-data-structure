// -1  =>  false
//  0  =>  true
//  3  =>  false
//  4  =>  true
// 25  =>  true
// 26  =>  false

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int is_square(int n);

int is_square(int n) {
    if (n < 0) {
        return 0;
    } else {
        int root = (int)sqrt((double)n);
        return root * root == n ? 1 : 0;
    }
}

int main(){
    printf("-1 ==> %s\n", is_square(-1) ? "true" : "false"); // false
    printf("0 ==> %s\n", is_square(0) ? "true" : "false");   // true
    printf("3 ==> %s\n", is_square(3) ? "true" : "false");   // false
    printf("4 ==> %s\n", is_square(4) ? "true" : "false");   // true
}


