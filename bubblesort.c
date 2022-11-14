#include <stdio.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

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

void bubblesort(unsigned long nel, int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j))
{
    if (nel > 1)
    {
        char swapFlag = 1;
        unsigned long end = nel - 1;
        unsigned long start = 0;

        while (swapFlag == 1)
        {
            swapFlag = 0;
            for (unsigned long i = start; i < end; i++)
            {
                if (compare(i, i + 1) == 1)
                {
                    swap(i, i + 1);
                    swapFlag = 1;
                }
            }
            if (swapFlag = 0)
            {
                break;
            }
            swapFlag = 0;
            end--;
            for (unsigned long i = end; i > start; i--)
            {
                if (compare(i, i - 1) == -1)
                {
                    swap(i, i - 1);
                    swapFlag = 1;
                }
            }
            start++;
        }
    }
}

int main(int argc, char **argv)
{
    unsigned long nel;
    scanf("%lu", &nel);

    array = malloc(sizeof(unsigned long) * nel);

    scanArray(array, nel);

    bubblesort(nel, compare, swap);

    for (unsigned long i = 0; i < nel; i++)
    {
        printf("%lu ", array[i]);
    }
    printf(" \n");

    free(array);

    return 0;
}