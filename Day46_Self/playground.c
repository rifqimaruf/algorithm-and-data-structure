#include <stdio.h>
#include <string.h>

#define MAX_LEN 100001

void decrypt(char *str, int shift)
{
    shift %= 26;
    if(shift < 0) shift += 26;

    for (int i = 0; str[i]; i++)
    {
        unsigned char c = str[i];
        if (c >= 'a' && c <= 'z'){ //lowercase
            str[i] = 'a' + (c - 'a' - shift + 26) % 26;
        } else if (c >= 'A' && c <= 'Z'){ //uppercase
            str[i] = 'A' + (c - 'A' - shift + 26) % 26;
        }
    }
}
int main()
{
    char str[MAX_LEN];
    int shift;

    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = '\0';
    scanf("%d", &shift);

    decrypt(str, shift);
    printf("%s", str);

    return 0;
}