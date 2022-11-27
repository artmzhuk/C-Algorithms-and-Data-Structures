#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(int k, int l, int m, int* p);
void insertsort(int start, int end, int* a);
void mergesortRec(int low, int high, int* p);
void mergesort(int* p, int n);
void scanArray(int *array, int nel);
void printArray(int *array, int nel);

int main()
{
    int nel;
    scanf("%d", &nel);
    int array[nel];
    scanArray(array, nel);
    mergesort(array, nel);
    printArray(array, nel);
    return 0;
}

void merge(int k, int l, int m, int* p)
{
    int t[m - k + 1];
    int i = k;
    int j = l + 1;
    int h = 0;
    while(h < m - k + 1)
    {
        if (j <= m && (i == l+1 || abs(p[j]) < abs(p[i])))
        {
            t[h] = p[j];
            j += 1;
        }
        else
        {
            t[h] = p[i];
            i += 1;
        }
        h += 1;
    }
    memcpy(p + k, t, sizeof(int)* h);//?
}

void insertsort(int start, int end, int* a)
{
    int i, elem, loc;
    i = start;
    while (i <= end)
    {
        elem = a[i];
        loc = i - 1;
        while(loc >= 0 && abs(a[loc]) > abs(elem))
        {
            a[loc + 1] = a[loc];
            loc -= 1;
        }
        a[loc + 1] = elem;
        i += 1;
    }
}

void mergesortRec(int low, int high, int* p)
{
    if (low < high)
    {
        int med = (low + high) / 2;
        if(med - low >= 4 && high - med - 1  >= 4)
        {
            mergesortRec(low, med, p);
            mergesortRec(med + 1, high, p);
            merge(low, med, high, p);
        }
        else
        {
            insertsort(low, med, p);
            insertsort(med + 1, high, p);
        }
    }
}



void mergesort(int* p, int n)
{
    mergesortRec(0, n - 1, p);
}

void scanArray(int *array, int nel) //считывает эл-ты массива
{
    for (int i = 0; i < nel; i++)
    {
        scanf("%d", &array[i]);
    }
}

void printArray(int *array, int nel)
{
    for(int i = 0; i < nel; i++)
    {
        printf("%d ", array[i]);
    }
}
