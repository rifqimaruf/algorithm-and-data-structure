#include <string.h>
#include <stdio.h>

char *get_middle(char outp[3], const char *inp)
{
    size_t len = strlen(inp);
    if (len % 2 == 0) {
        outp[0] = inp[len / 2 - 1];
        outp[1] = inp[len / 2];
        outp[2] = '\0';
    } else {
        outp[0] = inp[len / 2];
        outp[1] = '\0';
    }
    return outp;
}

int main()
{
    char output[3];
    const char *input1 = "test";
    const char *input2 = "testing";
    printf("Middle of '%s': '%s'\n", input1, get_middle(output, input1)); 
    printf("Middle of '%s': '%s'\n", input2, get_middle(output, input2)); 
    return 0;

}