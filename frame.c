#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    if (argc !=4) 
    {
        printf ("Usage: frame <height> <width> <text>\n");
        return 0;
    }
    int h = atoi(argv[1]);
    int w = atoi(argv[2]);
    size_t len = strlen(argv[3]);
    int condY = h/2;
    int k = 1;
    
    if (h % 2 == 0)
    {
        condY -= 1; 
    }

    if(len > w -2 || h < 3)
    {
        printf("Error");
        return 0;
    }

    for (int i = 0; i < w; i++)
    {
        printf("*");
    }
    printf("\n");

    

    for (int i = 1; (i < h - 2) || h == 3; i++)
    {
        if (i == condY)
        {
            printf("*");
            for (int j = 0; j < (w - 2- len) /2; j++)
            {
                printf(" ");
                k++;
            }
            printf("%s", argv[3]);
            while (k <= w - 2 - len)
            {
                printf(" ");
                k++;
            }
            printf("*\n");
        }
        if(h != 3) {
            printf("*");
            for (int j = 0; (j < w - 2); j++) {
                printf(" ");
            }
            printf("*\n");
        }
        if (h == 3)
            break;
    }

    for (int i = 0; i < w; i++)
    {
        printf("*");
    }

}