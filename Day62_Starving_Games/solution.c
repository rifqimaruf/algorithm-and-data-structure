#include <stdio.h>

void sort(int arr[], int n)
{
    for(int i = 0; i < n -1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, X;

    scanf("%d %d", &n, &X);
    int representatives[100];
    int disctrict_count[21] = {0};

    for (int i = 0; i <X; i++)
    {
        scanf("%d", &representatives[i]);
        disctrict_count[representatives[i]]++;
    }

    int max_reps = 0, winning_district = 0;
    for(int i = 1; i <= n; i++)
    {
        if(disctrict_count[i] > max_reps)
        {
            max_reps = disctrict_count[i];
            winning_district = i;
        }
    }

    // sort representative
    sort(representatives, X);

    int middle_idx = (X- 1) / 2;
    int median = representatives[middle_idx];
    printf("%d %d\n", winning_district, median);
    if(winning_district == median)
    {

        printf("Tidak ada yang menang\n");
    }
    else
    {
        printf("Distrik %d menang\n", winning_district);
    }
}