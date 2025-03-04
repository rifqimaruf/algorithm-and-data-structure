#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

unsigned queue_duration(size_t length, const unsigned* queue, size_t idx)
{
    unsigned* temp_queue = (unsigned*)malloc(length * sizeof(unsigned));
    for (size_t i = 0; i < length; i++) {
        temp_queue[i] = queue[i];
    }

    int time = 0;
    int friendTickets = temp_queue[idx];
    int friendRemaining = friendTickets;

    while (friendRemaining > 0)
    {
        size_t i = 0;
        while (i < length)
        {
            if (temp_queue[i] > 0)
            {
                temp_queue[i]--;
                time++;

                if (i == idx)
                {
                    friendRemaining--;
                    if (friendRemaining == 0)
                    {
                        free(temp_queue);
                        return time;
                    }
                }
            }
            i++;
        }
    }
    free (temp_queue);
    return time;
}

int main()
{
    unsigned tickets[] = {2, 5, 3, 4, 6};
    size_t n= 5;
    size_t friendPos = 2;
    
    int result = queue_duration(n, tickets, friendPos);
    printf("Time for friend: %d minutes\n", result);

    return 0;
}