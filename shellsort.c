#include <stdio.h>
#include <stdlib.h>

unsigned long *array;

void scanArray(unsigned long *array, unsigned long nel) //считывает эл-ты массива
{
    for (unsigned long i = 0; i <= nel - 1; i++)
    {
        scanf("%lu", &array[i]);
    }
}

void swap(unsigned long i, unsigned long j)
{
    unsigned long tmp = *(array + i);
    *(array + i) = *(array + j);
    *(array + j) = tmp;
}

int compare(unsigned long i, unsigned long j)
{
    if (*(array + i) < *(array + j))
        return -1;
    else if (*(array + i) == *(array + j))
        return 0;
    else
        return 1;
}

void shellsort(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j))
{
    unsigned long fib[nel];
    unsigned long fibIndex = 1;
    fib[0] = 1;
    fib[1] = 1;
    for (; fib[fibIndex] <= nel; fibIndex++)
    {
        fib[fibIndex + 1] = fib[fibIndex] + fib[fibIndex - 1];
    }
    fibIndex--;
    unsigned long delta = fib[fibIndex];

    while (fibIndex >= 1)
    {
        printf("sorting gap is: (%lu) ", fib[fibIndex]);
        for (unsigned long i = delta; i < nel; i++)
        {
            for (long long j = i - delta; j >= 0 && compare(j, j + delta) == 1; j -= delta)
            {
                printf("\n swapping %lu (%lli) and %lu (%lli) \n", array[j], j, array[j+delta], j+delta);
                swap(j, j + delta);
            }
        }

        for(unsigned long h = 0; h < nel; h++)
        {
            printf("%lu ", array[h]);
        }
        printf("\n");
        fibIndex--;
        delta = fib[fibIndex];
    }
}

int main(int argc, char **argv)
{
    unsigned long nel;
    scanf("%lu", &nel);
    array = malloc(sizeof(unsigned long) * nel);

    scanArray(array, nel);

    shellsort(nel, compare, swap);

    for (unsigned long i = 0; i < nel; i++)
    {
        printf("%lu ", array[i]);
    }
    printf(" \n");

    free(array);
    return 0;
}