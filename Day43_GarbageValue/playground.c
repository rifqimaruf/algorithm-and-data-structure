#include <stdio.h>

int main()
{
    int a, b, c;
    printf("The adress of variable A: %p\n", (void*)&a);
    printf("The adress of variable A: %p\n", (void*)&b);
    printf("The adress of variable A: %p\n", (void*)&c);
    printf("%d, %d, %d \n", a, b, b);


    // cek variable position relative with the variabel
    printf("a to b: %ld bytes \n", (char*)&a - (char*)&b);
    printf("b to c: %ld bytes \n", (char*)&b - (char*)&c);

    return 0;
}