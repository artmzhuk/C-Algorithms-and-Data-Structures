#include <stdio.h>

unsigned long scanSet(int size)
{
    unsigned long result = 0;
    int element;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &element);
        result = (result | (1 << element));
    }
    return result;
}

unsigned long intersectSets(unsigned long a, unsigned long b)
{
    unsigned long result = a & b;
    return result;
}

void printSet(unsigned long set)
{
    for (int i = 0; i <= 31; i++)
    {
        if ((set | (1 << i)) == set)
        {
            printf("%d ", i);
        }
    }
}

int main(int argc, char **argv)
{
    int sizeA, sizeB;
    unsigned long A, B, result;

    scanf("%d", &sizeA);
    A = scanSet(sizeA);

    scanf("%d", &sizeB);
    B = scanSet(sizeB);
    if(sizeA != 0 &&sizeB != 0)
        printSet(intersectSets(A, B));
    else
        printf(" ");

    return 0;
}