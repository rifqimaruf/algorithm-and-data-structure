#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int data[100];  
    int top;          
} Stack;

void initStack(Stack *s) 
{
    s->top = -1;  
}


int push(Stack *s, int value) 
{
    s->data[++(s->top)] = value;
}

int pop(Stack *s) 
{
    return s->data[(s->top)--];
}

// void freeStack(Stack *s)
// {
//     free(s->data);
//     // s->data = NULL;
//     s->top = -1;
// }


int main() 
{
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    // pop(&stack);

    // printf("push %d \n", (int)push(&stack, 1));
    // printf("push %d \n", (int)push(&stack, 2));
    // printf("push %d \n", (int)push(&stack, 3));

    printf("pop %d \n", pop(&stack));
    printf("pop %d \n", pop(&stack));
    printf("pop %d \n", pop(&stack));

    // free(&stack);

    return 0;
}





