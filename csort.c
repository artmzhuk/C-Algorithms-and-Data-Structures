#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void csort(char *src, char *dest) {
    int strLength = (int) strlen(src);
    int wordLengths[501] = {0};
    int wordLenMax = 0;
    int wordIndex = 0;
    int wordStart = 0;
    int wordStartId[501] = {0};
    for (int i = 0; i <= strLength; i++) // проходит по строке, начало строки -- индекс 0
    {
        if (src[i] == ' ' || src[i] == '\0' || src[i] == '\n' || i == strLength) {
            if (i - wordStart > wordLenMax) {
                wordLenMax = i - wordStart;
            }
            wordLengths[wordIndex] = i - wordStart;
            wordStartId[wordIndex] = wordStart;
            wordStart = i + 1;
            wordIndex++;
            while (i + 1 < strLength && src[i + 1] == ' ')//пропуск лишних пробелов
            {
                wordStart++;
                i++;
            }

        }
    }

    int *count = calloc(wordIndex, sizeof(int));
    int j = 0;
    while (wordLengths[j] != 0) {
        int i = j + 1;
        while (i < wordIndex) {
            if (wordLengths[i] < wordLengths[j]) {
                count[j] = count[j] + 1;
            } else {
                count[i] = count[i] + 1;
            }
            i++;
        }
        j++;
    }

    int used = 0;
    for (int i = 0; i < wordIndex; i++) {
        int g = 0;
        while (count[g] != i)
            g++;
        memcpy(dest + used, src + wordStartId[g], wordLengths[g]);
        dest[used + wordLengths[g]] = ' ';
        used += wordLengths[g] + 1;
    }
    if (used != 0) {
        dest[used - 1] = '\0';
    }

    free(count);
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