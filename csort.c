#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

void csort(char *src, char *dest)
{
    int strLength = strlen(src);
    int wordLengths[501] = {0};
    int wordLenMax = 0;
    int wordIndex = 0;
    int wordStart = 0;
    int wordStartId[501] = {0};
    for (int i = 0; i <= strLength;i++) // проходит по строке, начало строки -- индекс 0
    {
        if (src[i] == ' ' || src[i] == '\0')
        {
            if(i - wordStart > wordLenMax)
            wordLenMax = i -wordStart;

            wordLengths[wordIndex] = i - wordStart;
            wordStartId[wordIndex] = wordStart;
            wordStart = i + 1;
            wordIndex++;
            while(src[i+1] == ' ')//пропуск лишних пробелов
            {
                wordStart++;
                i++;
            }
            
        }
    }
    printf("\ncounted letters in words\n");
    for (int j = 0; j < wordIndex; j++)
    {
        printf("%i ", wordLengths[j]);
    }
    printf("\nstart id's of words\n");
    for (int j = 0; j < wordIndex; j++)
    {
        printf("%i ", wordStartId[j]);
    }
    printf("\n");

    int used = 0;
    char *end = dest;
    for(int i = 1; i <= wordLenMax; i++)//проверка длины слова
    {
        for(int j = 0; j < wordIndex; j++)
        {
            if(wordLengths[j] == i)
            {
                memcpy(dest + used, src + wordStartId[j], i);
                dest[used + i] = ' ';
                used += i + 1; 
            }
        }         
    }
    dest[used - 1] = '\0';
}

int main(int argc, char **argv)
{
    char src[1001] = "qqq  www  t  aa rrr  bb  x y zz IIIIII pppp lgkgkkg 55555555555555555555555555 7";
    char dest[1001];
    //fgets(src, sizeof(src), stdin);
    csort(src, dest);
    printf("sorted array is\n");
    puts(dest);
    printf("\n");
    return 0;
}