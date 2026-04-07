#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct
{
    char label[50];
    clock_t start;
} Timer;

Timer timers[10];
int timer_count = 0;

void console_time(const char *label)
{
    strcpy(timers[timer_count].label, label);
    timers[timer_count].start = clock();
    timer_count++;
}

void console_timeEnd(const char *label)
{
    for (int i = 0; i < timer_count; i++)
    {
        if (strcmp(timers[i].label, label) == 0)
        {
            clock_t end = clock();
            double elapsed = (double)(end - timers[i].start) / CLOCKS_PER_SEC;

            printf("%s: %f seconds\n", label, elapsed);
            
            return;
        }
    }

    printf("Timer '%s' not found\n", label);
}