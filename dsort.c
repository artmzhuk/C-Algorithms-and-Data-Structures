#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void dsort(long n, const char *s, char *d) {
    int k;
    int m = 27;
    long j = 0;
    long i = 1;
    int *count = calloc(m, sizeof(int));
    if (count == NULL)
        printf("failed to malloc");

    while (j < n) {
        k = (int) s[j] - 97;
        count[k] = count[k] + 1;
        j += 1;
    }
    while (i < m) {
        count[i] = count[i] + count[i - 1];
        i += 1;
    }
    j = n - 1;

    for (int g; j >= 0; j--) {
        if (s[j] != '\n') {
            k = (int) s[j] - 97;
            g = count[k] - 1;
            count[k] = g;
            d[g] = s[j];
        }
    }
    d[n - 1] = '\0';
    free(count);
}

int main() {
    char string[1000001];
    fgets(string, 1000000, stdin);
    long nel = (long) strlen(string);
    char result[nel];
    dsort(nel, string, result);//n -- without \0
    puts(result);
    return 0;
}