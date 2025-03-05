#include <stdio.h>
#include <stdlib.h>

double find_average(const double array[], unsigned length)
{
    if (length == 0) {
        return 0.0;
    }
  
    double total = 0;
    for(unsigned i = 0; i < length; i++)
    {
        total += array[i];
    }
    double res = total / length;
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    double *array = (double*)malloc(n * sizeof(double));

    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &array[i]);
    }

    double average = find_average(array, n);
    printf("average %.2f", average);
    return 0;
}