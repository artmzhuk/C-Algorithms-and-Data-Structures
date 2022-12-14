#include <stdio.h>
#include <string.h>

void csort(char *src, char *dest)
{
    int strLength = (int)strlen(src);
    int wordLengths[501] = {0};
    int wordLenMax = 0;
    int wordIndex = 0;
    int wordStart = 0;
    int wordStartId[501] = {0};
    for (int i = 0; i <= strLength;i++) // проходит по строке, начало строки -- индекс 0
    {
        if (src[i] == ' ' || src[i] == '\0' || src[i] == '\n' || i == strLength)
        {
            if(i - wordStart > wordLenMax)
                wordLenMax = i -wordStart;

            wordLengths[wordIndex] = i - wordStart;
            wordStartId[wordIndex] = wordStart;
            wordStart = i + 1;
            wordIndex++;
            while(i + 1 < strLength && src[i+1] == ' ')//пропуск лишних пробелов
            {
                wordStart++;
                i++;
            }

        }
    }
    int used = 0;
    for(int i = 1; i <= wordLenMax; i++)//проверка длины слова
    {
        for(int j = 0; j <= wordIndex; j++)
        {
            if(wordLengths[j] == i)
            {
                memcpy(dest + used, src + wordStartId[j], i);
                dest[used + i] = ' ';
                used += i + 1;
            }
        }
    }
    if (used != 0)
        dest[used - 1] = '\0';
}

int main()
{
    char src[2000] = {0};
    char dest[2000] = {0};
    fgets(src, sizeof(src), stdin);
    csort(src, dest);
    puts(dest);
    return 0;
}