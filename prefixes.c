#include <stdio.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void prefixFunction(const char* string, size_t length, int* p, int* result)// string - initial string,
// length - its length, p - prefix function result, result -
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
    if(string == NULL)
    {
        printf("failed to malloc\n");
        return 0;
    }
    strcpy(string, argv[1]);

    int *p = calloc(length, sizeof(int));// array for prefix function of string
    int *result = calloc(length + 1, sizeof(int));

    prefixFunction(string, length, p, result);

//    for(int i = 0; i < length; i++) // printing prefix array
//    {
//        printf("%d ", p[i]);
//    }

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

//    int k;
//    p[0] = 0;
//    char *substring1 = malloc(length);
//    char *substring2 = malloc(length);
//    int i = 1;
//    while(i < (int)length)
//    {
//        k = i;
//        substring(string, length, substring1, 0, k - 1);
//        substring(string, length, substring2, i - k + 1, i);
//        while( k > 0 && strcmp(substring1, substring2) != 0)
//        {
//            substring(string, length, substring1, 0, k -1);
//            substring(string, length, substring2, i - k + 1, i);
//            k -= 1;
//        }
//        p[i] = k;
//        i += 1;
//    }

//void substring(char* string, size_t length, char* substring, int i, int j)
//{
//    memset(substring, 0, length);
//    memcpy(substring, string + i, j - i);
//}