#include <stdio.h>

int elementAmount(long set[], long element) // подсчитывает сколько раз элемент встречается в массиве
{
    int n = 0;
    for (int j = 0; j <= 7; j++)
    {
        if (set[j] == element)
        {
            n += 1;
        }
    }
    return n;
}

void scanArray(long set[], int size) //считывает эл-ты массива
{
    for (int i = 0; i <= size - 1; i++)
    {
        scanf("%li", &set[i]);
    }
}

int compare(long set1[], long set2[])
{
    for (int i = 0; i <= 7; i++)
    {
        if (elementAmount(set1, set1[i]) != elementAmount(set2, set1[i]))
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv)
{
    long a[7];
    long b[7];

    printf("input:\n");

    scanArray(a, 8);
    scanArray(b, 8);
    int res = compare(a, b);
    switch (res)
    {
    case 0:
        printf("no");
        break;

    case 1:
        printf("yes");
        break;
    }
}