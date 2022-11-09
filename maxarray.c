#include <stdio.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <wchar.h>

//проверить перед отправкой (убрать scanarray, функцию comparee)


int maxarray(void *base, size_t nel, size_t width, 
int (*compare)(void *a, void *b))
{
    void *maxElement = malloc(width);
    memcpy(maxElement, base, width);
    int index = 0;
    for(size_t n = 1; n < nel; n++)
    {
        if(compare ((base + n*width), maxElement) > 0 )
        {
            memcpy(maxElement, base + n * width, width);
            index = (int)n; 
        }
    }
    free(maxElement);
    return index;
}

void scanArray(long set[], long size) //считывает эл-ты массива
{
    for (long i = 0; i <= size - 1; i++)
    {
        scanf("%li", &set[i]);
    }
}

int comparee(void *a, void *b)
{
    long va = *(long*)a;
    long vb = *(long*)b;
    if (va == vb) return 0;
    return va < vb ? -1 : 1;
}

int main(int argc, char **argv)
{
    long array[5];
    scanArray(array, 5);
    printf("%d\n", maxarray(array, 5, sizeof(long), comparee));
    return 0;
}
