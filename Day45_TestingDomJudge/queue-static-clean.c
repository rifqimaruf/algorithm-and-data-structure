#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int* data;
    int rear;
    int capacity;
} Arr;

Arr* createArr(int capacity)
{
    Arr* array = (Arr*)malloc(sizeof(Arr));
    array->data = (int*)malloc(sizeof(int) * capacity);
    array->rear = -1;
    array->capacity = capacity;
    return array;
}

int isEmpty(Arr* arr)
{
    return arr->rear == -1;
}

int isFull(Arr* arr)
{
    return arr->rear == arr->capacity - 1;
}

void push(Arr* arr, int value)
{
    if (isFull(arr))
    {
        arr->capacity *= 2;
        int* temp = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
        arr->data = temp;
    }
    arr->data[++arr->rear] = value;
}

int Pop(Arr* arr)
{
    if (isEmpty(arr)) 
    {
        return -1;
    }
    int value = arr->data[arr->rear--];
    return value;
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
        else if (strcmp(command, "Pop") == 0)
        {
            Pop(array);
        }
    }
    
    // Cetak sisa elemen array
    if (!isEmpty(array)) {
        for (int i = 0; i <= array->rear; i++) {
            printf("%d", array->data[i]);
            if (i < array->rear) {
                printf(" ");
            }
        }
    }
    
    freeArr(array);
    return 0;
}