#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

char *concat(char **s, int n)
{
    size_t lengths[n];
    size_t currentlen;
    size_t len = 0;
    for(int i = 0; i < n; i++){
        currentlen = strlen(s[i]);
        lengths[i] = currentlen;
        len += currentlen;
    }

    char* res = calloc(len + 1, sizeof(char));
    len = 0;

    for(int i = 0; i < n; i++){
        memcpy(res + len, s[i], lengths[i]);
        len += lengths[i];
    }
    res[len] = '\0';
    return res;
}


int main(){
    int n;
    char* res;
    scanf("%d", &n);
    char** strings = malloc(n * sizeof(char*));
    char string[1001];

    for(int i = 0; i < n; i++){
        scanf("%s", string);
        strings[i] = malloc(strlen(string) + 1);
        strcpy(strings[i], string);
    }

    res = concat(strings, n);
    puts(res);

    for(int i = 0; i < n; i++)
        free(strings[i]);
    free(strings);
    free(res);
    return 0;
}