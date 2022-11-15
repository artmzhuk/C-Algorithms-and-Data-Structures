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
    unsigned long fib[95];
    unsigned long maxF = 2;
    int j = 2;

    fib[0] = 1;
    fib[1] = 1;
    while (maxF <= nel)
    {
        fib[j] = fib[j - 1] + fib[j - 2];
        maxF = fib[j];
        j++;
    }
    unsigned long d = fib[j-2];
    //unsigned long d = 1;
    while(d >= 1)
    {
        for(unsigned long i = d; i < nel; i++)
        {
            for(unsigned long k = i; k > 0 && compare(k, k - d) == -1; k-= d)
            {
                swap(k, k - d);
            }
        }
        j--;
        d = fib[j-2];
        //d--;
    }

//     unsigned long i = 1;
//     while (i < nel)
//     {
//         long long loc = i - 1;
//         while (loc >= 0 && compare(loc + 1, loc) == -1)
//         {
//             swap(loc + 1, loc);
//             loc--;
//         }
//         i++;
//     }
}

int main(int argc, char **argv)
{
    unsigned long nel;
    scanf("%lu", &nel);

    array = malloc(sizeof(unsigned long) * (nel + 1));

    scanArray(array, nel);

    shellsort(nel, compare, swap);

    for (unsigned long i = 0; i < nel +1; i++)
    {
        printf("%lu ", array[i]);
    }
    printf(" \n");

    free(array);
    return 0;
}