#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (stack->top + 1 == stack->capacity) {
        stack->capacity *= 2;
        stack->data = (int*)realloc(stack->data, sizeof(int) * stack->capacity);
    }
    stack->data[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->data[stack->top--];
}

int symbolToNum(char symbol) {
    switch (symbol) {
        case ')': return 0;
        case '!': return 1;
        case '@': return 2;
        case '#': return 3;
        case '$': return 4;
        case '%': return 5;
        case '^': return 6;
        case '&': return 7;
        case '*': return 8;
        case '(': return 9;
        default: return -1;
    }
}

int findAndRemove(Stack* stack, int item) {
    Stack* temp = createStack(stack->capacity);
    int found = 0;
    while (!isEmpty(stack)) {
        int curr = pop(stack);
        if (curr == item && !found) {
            found = 1; // Hapus hanya kemunculan pertama
        } else {
            push(temp, curr);
        }
    }
    while (!isEmpty(temp)) {
        push(stack, pop(temp));
    }
    free(temp->data);
    free(temp);
    return found;
}

void solveFisherman(int n, char* symbols) {
    Stack* stack = createStack(n);
    int expected = 9; // Mulai dari berat terbesar

    for (int day = 0; day < n; day++) {
        int weight = symbolToNum(symbols[day]);
        push(stack, weight);

        int sold[10], soldCount = 0; // Array untuk menyimpan ikan yang dijual
        while (expected >= 0 && findAndRemove(stack, expected)) {
            sold[soldCount++] = expected;
            expected--; // Turunkan ekspektasi setelah penjualan
        }

        // Cetak ikan yang dijual di hari ini
        if (soldCount == 0) {
            printf("\n"); // Baris kosong jika tidak ada yang dijual
        } else {
            for (int i = 0; i < soldCount; i++) {
                printf("%d", sold[i]);
                if (i < soldCount - 1) printf(" ");
            }
            printf("\n");
        }
    }

    free(stack->data);
    free(stack);
}

int main() {
    int n;
    scanf("%d", &n);
    char* symbols = (char*)malloc(n + 1);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i]); // Spasi sebelum %c untuk skip whitespace
    }
    symbols[n] = '\0';

    solveFisherman(n, symbols);

    free(symbols);
    return 0;
}