#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void prefixFunction(const char* string, size_t length, int* p)// string - initial string,
// length - its length, p - prefix function result, result[i] = j : i =
{
    int k , i;
    for(i = 1; i <(int)length; i++)//creating prefix array
    {
        k = p[i - 1];
        while (k > 0 && string[k] != string[i])
        {
            k = p[k - 1];
        }
        if(string[k] == string[i])
            k += 1;
        p[i] = k;
    }
}

int main(int argc, char **argv)
{
    size_t lengthS = strlen(argv[1]);
    char *stringS = malloc(lengthS + 1);
    strcpy(stringS, argv[1]);

    size_t lengthT = strlen(argv[2]);
    char *stringT = malloc(lengthT + 1);
    strcpy(stringT, argv[2]);

    int *p = calloc(lengthS, sizeof(int));// array for prefix function of string

    prefixFunction(stringS, lengthS, p);

    int *result = calloc(lengthT, sizeof(int));

    int q = 0;
    int k = 0;
    while(k < (int)lengthT)//from lections
    {
        while (q > 0 && stringS[q] != stringT[k])
            q = p[q - 1];
        if (stringS[q] == stringT[k])
            q += 1;
        if (q == lengthS)
        {
            result[k -(int)lengthS + 1] = 1; //break
        }
        k += 1;
    }

    for(int i = 0; i < lengthT; i++)
    {
        if(result[i] == 1)
        {
            printf("%i ", i);
        }
    }

    free(p);
    free(result);
    free(stringS);
    free(stringT);

    return  0;
}
