#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int* data;
    int top;
    int capacity;
} Stack;

typedef struct 
{
    int* weights;
    int count;
} DayResult;

Stack* createStack(int capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int isEmpty(Stack* stack)
{
    return stack->top == -1;
}

int isFull(Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, int item)
{
    if(isFull(stack))
    {
        stack->capacity *= 2;
        stack->data = (int*)realloc(stack->data, sizeof(int) * stack->capacity);
    }
    stack->data[++stack->top] = item;
}

int pop(Stack* stack)
{
    if(isEmpty(stack)) return -1;
    return stack->data[stack->top--];
}

int peek(Stack* stack)
{
    if(isEmpty(stack)) return -1;
    return stack->data[stack->top];
}

int symbolToNum(char symbol)
{
    switch(symbol)
    {
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
        default: return -1; // not valid
    }
}

int findAndRemove(Stack* stack, int item)
{
    Stack* tempStack = createStack(stack->capacity);
    int found = 0;

    while (!isEmpty(stack))
    {
        int current = pop(stack);
        if (current == item && !found)
        {
            found = 1;
        } 
        else 
        {
            push(tempStack, current);
        }
    }

    while (!isEmpty(tempStack))
    {
        push(stack, pop(tempStack));
    }

    free(tempStack->data);
    free(tempStack);

    return found;
}

void solveCursedMan(int n, char** encryptedWeights)
{
    int* weights = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        weights[i] = symbolToNum(encryptedWeights[i][0]);
    }

    Stack* unsoldFish = createStack(n);

    DayResult* results = (DayResult*)malloc(sizeof(DayResult) * n);
    for (int i = 0; i < n; i++)
    {
        results[i].weights = (int*)malloc(sizeof(int) * n);
        results[i].count = 0;
    }

    int expected = n;

    for (int day = 0; day < n; day++)
    {
        push(unsoldFish, weights[day]);
        while (expected > 0 && findAndRemove(unsoldFish, expected))
        {
            results[day].weights[results[day].count++] = expected;
            expected--;
        }
    }

    for (int day = 0; day < n; day++)
    {
        for (int i = 0; i <results[day].count; i++)
        {
            printf("%d", results[day].weights[i]);
            if (i < results[day].count - 1)
            {
                printf(" ");
            }
        }
        
        printf("\n");
    }

    // Pembersihan memori
    for (int i = 0; i < n; i ++)
    {
        free(results[i].weights);
    }
    
    free(results);
    free(weights);
    free(unsoldFish->data);
    free(unsoldFish);
}

int main()
{
    int n;
    scanf("%d", &n);

    char** encryptedWeights = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
    {
        encryptedWeights[i] = (char*)malloc(2); // 1 karakter + null terminator
    }

    for (int i = 0; i < n; i ++)
    {
        scanf("%s", encryptedWeights[i]);
    }

    solveCursedMan(n, encryptedWeights);

    for (int i = 0; i < n; i++)
    {
        free(encryptedWeights[i]);
    }
    
    free(encryptedWeights);
    return 0;
}







