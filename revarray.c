#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

void revarray(void *base, size_t nel, size_t width)
{
    char *tmp = NULL;
    tmp = malloc(width);
    size_t n = 0;
    for (size_t n = 0; n < nel / 2; n++)
    {
        memcpy(tmp, base + n*width, width);
        memcpy(base + n*width, base + (nel - 1 - n)*width, width);
        memcpy(base + (nel - 1 - n)*width, tmp, width);
    }
    free(tmp);
}


int main(int argc, char **argv)
{
    // int array[] = {1, 2, 3, 4, 5, 6};
    // revarray(array, 6, sizeof(int));

    // int i;
    // for (i = 0; i < 6; i++) {
    //     printf("%d ", array[i]);
    // }

    return 0;
}