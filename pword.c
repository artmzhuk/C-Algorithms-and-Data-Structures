#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void prefixFunction(const char* string, size_t length, int* p);
int pword(char **argv);

int main(int argc, char **argv)
{
    if(pword(argv) == 1)
        printf("yes");
    else
        printf("no");
    return 0;
}

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

int pword(char **argv)
{
    size_t lengthS = strlen(argv[1]);
    size_t lengthT = strlen(argv[2]);
    char* stringQ = malloc(lengthS + lengthT + 2);
    int *p = calloc(lengthS + lengthT + 2, sizeof(int));// array for prefix function of string

    strcpy(stringQ, argv[1]);
    strcpy(stringQ + lengthS + 1, argv[2]);

    prefixFunction(stringQ, lengthS + lengthT + 2, p);

    for(int i = 1; i <= lengthT; i++)
    {
        if(p[lengthS + i] == 0)
        {
            free(p);
            free(stringQ);
            return 0;
        }
    }
    free(p);
    free(stringQ);
    return 1;
}