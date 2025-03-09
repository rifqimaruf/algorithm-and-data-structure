#include <stdio.h>
#include <stdlib.h>

char *array_adder(int rows, int cols, 
    const char *matrix, 
    char *string)
{
    int pos = 0;

    for (int i = 0; i < cols; i++) 
    {
        for (int j = 0; j < rows; j++) 
        {
            char current = matrix[j * cols + i]; //akses elemen ke-i dari kolom ke-j
            if (current != '\0') 
            {
                string[pos++] = current; //string kata-kata
            }
        }
        if (i < cols - 1) 
        {
            string[pos++] = ' '; // spasi ditambahkan 
        }
    }

    string[pos] = '\0'; // di c string harus di akhirin ini
    return string;
}
int main()
{
    // Contoh 1
    char matrix1[4][4] = {
        {'J', 'L', 'L', 'M'},
        {'u', 'i', 'i', 'a'},
        {'s', 'v', 'f', 'n'},
        {'t', 'e', 'e', '\0'}
    };
    char result1[50];  // Buffer cukup besar untuk hasil

    array_adder(4, 4, (const char *)matrix1, result1);
    printf("%s\n", result1);  // Output: "Just Live Life Man"

    return 0;
}