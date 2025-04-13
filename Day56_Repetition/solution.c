#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max = 1;
    int maxLength = 1;
    char currentChar[9000000];
    char DNA[9000000];
    scanf("%s", &DNA);
    // printf("%s\n", DNA);
    for(int i=0; DNA[i] != '\0' && DNA[i+1] != '\0'; i++)
    {
        int j = i;
        if(DNA[i] == DNA[j+1])
        {
            maxLength++;
            // printf("indeks %d %c | ", i, DNA[i]);
            // printf("maxlength %d ", maxLength);
            // printf("max %d\n", max);
        }
        else 
            maxLength = 1;
        if (max < maxLength)
            max = maxLength;
    }
    printf("%d\n ", max);

    return 0;
}