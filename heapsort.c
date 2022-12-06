#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
    int counterA = 0;
    int counterB = 0;
    char elementA = *(char*)a;
    char elementB = *(char*)b;
    for(int i = 0; i < 1001 && elementA != '\0'; i++)
    {
        if(elementA == 'a')
            counterA += 1;
        elementA = *(char*)(a + i);
    }
    for(int i = 0; i < 1001 && elementB != '\0'; i++)
    {
        if(elementB == 'a')
            counterB += 1;
        elementB = *(char*)(b + i);
    }
    return counterA - counterB;
}

void swap(void *base, int a, int b, size_t width)
{
    void *swapBuffer = malloc(width);
    memcpy(swapBuffer, base + a * width, width);
    memcpy(base + a * width, base + b * width, width);
    memcpy(base + b * width, swapBuffer, width);
    free(swapBuffer);
}

void heapify(void* base, size_t nel, size_t width, int i){
    while (1 == 1){
        int l = 2 * i + 1;
        int r = l + 1;
        int j = i;
        if (l < nel && (compare(base + i * width, base + l * width) < 0))
            i = l;
        if (r < nel && (compare(base + i * width, base + r * width) < 1))
            i = r;
        if (i == j)
            break;
        swap(base, i, j, width);
    }
}

void buildheap (void* base, size_t nel, size_t width){
    for(int i = ((int)nel / 2) - 1; i >= 0; i--)
        heapify(base, nel, width, i);
}



void hsort(void *base, size_t nel, size_t width,
           int (*compare)(const void *a, const void *b))
{
    buildheap(base, nel, width);
    for(int i = (int)nel - 1; i > 0; i--){
        swap(base, 0, i, width);
        heapify(base, i, width, 0);
    }
}

int main()
{
    //int array[6] = {2, 8, 5, 3, 9, 1};
    int nel;
    scanf("%d", &nel);
    char src[nel][1001];
    for(int i = 0; i < nel; i++)
    {
        scanf("%s", src[i]);

    }
    hsort(src, nel, 1001, compare);
    for(int i = 0; i < nel; ++i)
    {
        printf("%s \n", src[i]);
    }
    printf("\n");
    return 0;
}

/*
void heapify(void *base, int i, size_t nel, size_t width)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;

    // char *leftValue = malloc(width);
    // memcpy(leftValue, base + left * width, width);

    if (left < (int)nel && compare(base + left * width, base + max * width) > 0)
        max = left;

    if (right < (int)nel && compare(base + right * width, base + max * width) > 0)
        max = right;

    if (max != i)
    {
        swap(base, i, max, width);

        heapify(base, max, nel, width);
    }
}

void hsort(void *base, size_t nel, size_t width,
           int (*compare)(const void *a, const void *b))
{
    int n = (int)nel;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(base, i, n, width);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(base, 0, i, width);
        //n =- 1;
        heapify(base, 0, i, width);
    }
}

void swap(void *base, int a, int b, size_t width)
{
    void *swapBuffer = malloc(width);
    memcpy(swapBuffer, base + a * width, width);
    memcpy(base + a * width, base + b * width, width);
    memcpy(base + b * width, swapBuffer, width);
    free(swapBuffer);
}

int compare(const void *a, const void *b)
{
    int counterA = 0;
    int counterB = 0;
    char elementA = *(char*)a;
    char elementB = *(char*)b;
    for(int i = 0; i < 1001 && elementA != '\0'; i++)
    {
        if(elementA == 'a')
            counterA += 1;
        elementA = *(char*)(a + i);
    }
    for(int i = 0; i < 1001 && elementB != '\0'; i++)
    {
        if(elementB == 'a')
            counterB += 1;
        elementB = *(char*)(b + i);
    }
    return counterA - counterB;
}
*/
