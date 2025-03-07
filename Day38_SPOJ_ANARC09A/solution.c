#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fungsi untuk menghitung panjang string
int stringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Fungsi untuk memeriksa apakah string adalah palindrome
bool isPalindrome(char *str) {
    int length = stringLength(str);
    int start = 0;
    int end = length - 1;
    
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Fungsi untuk mendapatkan cerminan karakter
char getMirror(char ch) {
    if (ch == '{') return '}';
    if (ch == '}') return '{';
    return ch; // Untuk karakter lain
}

// Fungsi untuk memeriksa apakah string adalah mirrored string
bool isMirrored(char *str) {
    int length = stringLength(str);
    int start = 0;
    int end = length - 1;
    
    while (start <= end) {
        if (getMirror(str[start]) != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    char str[100];
    
    printf("Masukkan string kurung kurawal: ");
    scanf("%s", str);
    
    bool palindromeResult = isPalindrome(str);
    bool mirroredResult = isMirrored(str);
    
    printf("STRING CRITERIA\n");
    
    if (palindromeResult && mirroredResult) {
        printf("--is a mirrored palindrome.\n");
    } else if (palindromeResult) {
        printf("--is a regular palindrome.\n");
    } else if (mirroredResult) {
        printf("--is a mirrored string.\n");
    } else {
        printf("--is not a palindrome.\n");
    }
    
    return 0;
}