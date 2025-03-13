#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = item;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return s->data[(s->top)--];
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return '\0';
    }
    return s->data[s->top];
}


// Fungsi untuk menghitung panjang string
int stringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Fungsi untuk mendapatkan cerminan karakter
char getMirror(char ch) {
    if (ch == '{') return '}';
    if (ch == '}') return '{';
    return ch;
}

// Fungsi memeriksa palindrome menggunakan stack
bool isPalindrome(char *str) {
    int length = stringLength(str);
    Stack s;
    initStack(&s);
    
    // Push separuh pertama karakter ke stack
    int i;
    for (i = 0; i < length / 2; i++) {
        push(&s, str[i]);
    }
    
    // Jika panjang ganjil, lewati karakter tengah
    if (length % 2 != 0) {
        i++;
    }
    
    // Bandingkan separuh kedua dengan stack
    while (i < length) {
        if (str[i] != pop(&s)) {
            return false;
        }
        i++;
    }
    
    return true;
}

// Fungsi memeriksa mirrored string menggunakan stack
bool isMirrored(char *str) {
    int length = stringLength(str);
    Stack s;
    initStack(&s);
    
    // Push semua karakter ke stack
    for (int i = 0; i < length; i++) {
        push(&s, str[i]);
    }
    
    // Bandingkan setiap karakter dengan cerminan karakter dari stack (LIFO)
    for (int i = 0; i < length; i++) {
        char mirror = getMirror(str[i]);
        if (mirror != pop(&s)) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char str[MAX_SIZE];
    
    printf("Masukkan string kurung kurawal: ");
    scanf("%s", str);
    
    bool palindromeResult = isPalindrome(str);
    bool mirroredResult = isMirrored(str);
    
    printf("\nSTRING CRITERIA\n");
    
    if (palindromeResult && mirroredResult) {
        printf("--is a mirrored palindrome.\n");
    } else if (palindromeResult) {
        printf("--is a regular palindrome.\n");
    } else if (mirroredResult) {
        printf("--is a mirrored string.\n");
    } else {
        printf("--is not a palindrome or mirrored string.\n");
    }
    
    return 0;
}