#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int i;
    int a[11];
    int min, max;
    srand((unsigned)time(NULL));
    a[0] = rand() % 100;
    min = max = a[0];
    printf("%d\n", a[0]);
    for (i = 1; i < 11; i++)
    {
        a[i] = rand() % 100;
        printf("%d\n", a[i]);
        if (a[i] > max)
        {
            max = a[i];
        }
        else if (a[i] < min)
        {
            min = a[i];
        }
    }
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    getch();
}