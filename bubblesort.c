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
    for (int i = 0; i <= nel - 1; i++)
    {
        scanf("%lu", &array[i]);
    }
}

void swap(unsigned long i, unsigned long j)
{
    unsigned long tmp = *(array + i);
    *(array+ i) = *(array + j);
    *(array + j) = tmp;
}

int compare(unsigned long i, unsigned long j)
{
	if (*(array + i) < *(array + j)) return -1;
	else if (*(array + i) == *(array + j)) return 0;
	else return 1;
}

// void bubblesort(unsigned long nel,int (*compare)(unsigned long i, unsigned long j),
// void (*swap)(unsigned long i, unsigned long j))
// {
//         unsigned long t = nel - 1;// t -- граница несортированной части
//         unsigned long bound, i; // bound -- просто граница
//         while(t > 0)
//         {
//             bound = t;
//             t = 0;
//             i = 0;
//             while(i < bound)
//             {
//                 if(compare(i+1, i) == -1)
//                 {
//                     swap(i+1, i);
//                     t = i;
//                 }
//                 i++;
//             }
//         }
// }


void bubblesort(unsigned long nel,int (*compare)(unsigned long i, unsigned long j),
void (*swap)(unsigned long i, unsigned long j))
{
    char swapFlag = 1;
    
    while(swapFlag == 1)
    {
        for (unsigned long i = 0; i <= nel - 2; i++)// or <=
        {
            if(compare(i, i + 1) == 1)
            {
                swap(i, i + 1);
                swapFlag = 1;
            }
        }
        if (swapFlag != 1)
        {
            break;
        }
        swapFlag = 0;
        for(unsigned long i = nel - 2; i >= 0; i--)
        {
            if(compare(i, i + 1) == 1)
            {
                swap(i, i + 1);
                swapFlag = 1;
            }
        }
    }
}

int main(int argc, char **argv)
{
    unsigned long nel;
    scanf("%lu", &nel);

    array = malloc(sizeof(unsigned long) * nel);
    
    scanArray(array, nel);

    //printf("%i \n", compare(0,1));

    //printf("%lu", array[2]);

    //swap(0, 1);


    bubblesort(nel, compare, swap);

    for (int i = 0; i < nel; i++)
    {
        printf("%lu ", array[i]);
    }

    return 0;
}