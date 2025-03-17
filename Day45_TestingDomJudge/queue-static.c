#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int* data;
    // int top; 
    int rear; // digunakan ketika queue
    int capacity;
} Arr;

Arr* createArr(int capacity)
{
    Arr* array = (Arr*)malloc(sizeof(Arr));
    array->data = (int*)malloc(sizeof(int) * capacity);
    // array->top = -1;
    array->rear = -1; // digunakan ketika queue
    array->capacity = capacity;
    return array;
}

int isEmpty(Arr* arr)
{
    return arr->rear == -1;
}

int isFull(Arr* arr)
{
    return arr->rear == arr->capacity - 1; // digunakan ketika queue
    // return arr->top == arr->capacity - 1; 

}

void push(Arr* arr, int value)
{
    if (isFull(arr))
    {
        arr->capacity *= 2;
        int* temp = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
        arr->data = temp;
        // arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    }
    // if (arr->rear == -1){
    //     arr->rear= 0;
    // }
    arr->data[++arr->rear] = value; // digunakan ketika queue
    // arr->data[++arr->top] = value;
    // printf("Pushed %d, top = %d, rear = %d\n", value, arr->top, arr->rear);
}

int Pop(Arr* arr)
{
    if (isEmpty(arr)) 
    {
        printf("Empty \n");
        return -1;
    }
    int value = arr->data[arr->rear--];
    // if (arr->top > arr->rear)
    // {
    //     arr->top = -1;
    //     arr->rear = -1;
    // }
    return value;
    // return arr->data[arr->top--]; // untuk stack

}

void freeArr(Arr* arr)
{
    free(arr->data);
    free(arr);
}

int main()
{
    Arr* array;
    int n;  
    scanf("%d", &n);
    array = createArr(n);

    char command[5];
    int value;
    
    while(n--)
    {
        scanf("%s", command);
        if(strcmp(command, "push") == 0)
        {
            scanf("%d", &value);
            push(array, value);
        }
        else if (strcmp(command, "pop") == 0)
        {
            Pop(array);
            // int result = Pop(array);
            // if (result != -1)
            // {
            //     printf("%d\n", result);
            // }
        }
    }
    if (!isEmpty(array)) {
        for (int i = 0; i <= array->rear; i++) {
            printf("%d ", array->data[i]);
        }
        printf("\n");
    }
    
    freeArr(array);
    return 0;
}


//      char command[5];
//     int value;
    
//     while(n--)
//     {
//         scanf("%s", command);
//         if(strcmp(command, "push") == 0)
//         {
//             scanf("%d", &value);
//             push(array, value);
//         }
//         else if (strcmp(command, "pop") == 0)
//         {
//             if(pop(array) != -1)
//             {
//                 printf("popped: %d\n", pop(array));
//             }
//         }
//     }