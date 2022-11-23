#include <stdio.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void prefixFunction(const char* string, size_t length, int* p, int* result)// string - initial string,
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

    for(int j = 1; j <= i - 1; j++)//finding periodic prefixes
    {
        if(p[j] % (j - p[j] + 1) == 0 && p[j] != 0)
        {
            result[j + 1] = (j + 1) / (j + 1 - p[j]);
        }
    }
}

int main(int argc, char **argv)
{
    size_t length = strlen(argv[1]);
    char *string = malloc(length + 1);
    strcpy(string, argv[1]);

    int *p = calloc(length, sizeof(int));// array for prefix function of string
    int *result = calloc(length + 1, sizeof(int));

    if(string == NULL | p == NULL | result == NULL)
    {
        printf("failed to malloc\n");
        return 0;
    }

    prefixFunction(string, length, p, result);

    for(int i = 0; i <= length; i++)
    {
        if(result[i] != 0)
            printf("%d %d \n", i, result[i]);
    }

    free(p);
    free(string);
    free(result);
    return  0;
}