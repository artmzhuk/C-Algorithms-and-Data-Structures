#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(long k, long l, long m, long* p);
void insertsort(long start, long end, long* a);
void mergesortRec(long low, long high, long* p);
void mergesort(long* p, long n);
void scanArray(long *array, long nel);
void printArray(long *array, long nel);

int main()
{
    long nel;
    scanf("%li", &nel);
    long array[nel];
    scanArray(array, nel);
    mergesort(array, nel);
    printArray(array, nel);
    return 0;
}

void merge(long k, long l, long m, long* p)
{
    long t[m - k + 1];
    long i = k;
    long j = l + 1;
    long h = 0;
    while(h < m - k + 1)
    {
        if (j <= m && (i == l+1 || labs(p[j]) < labs(p[i])))
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
    memcpy(p + k, t, sizeof(long)* h);//?
}

void insertsort(long start, long end, long* a)
{
    long i, elem, loc;
    i = start;
    while (i <= end)
    {
        elem = a[i];
        loc = i - 1;
        while(loc >= 0 && labs(a[loc]) > labs(elem))
        {
            a[loc + 1] = a[loc];
            loc -= 1;
        }
        a[loc + 1] = elem;
        i += 1;
    }
}

void mergesortRec(long low, long high, long* p)
{
    if (low < high)
    {
        long med = (low + high) / 2;
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



void mergesort(long* p, long n)
{
    mergesortRec(0, n - 1, p);
}

void scanArray(long *array, long nel) //считывает эл-ты массива
{
    for (long i = 0; i < nel; i++)
    {
        scanf("%li", &array[i]);
    }
}

void printArray(long *array, long nel)
{
    for(long i = 0; i < nel; i++)
    {
        printf("%li ", array[i]);
    }
}
