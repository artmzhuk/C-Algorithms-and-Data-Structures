#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

struct Date {
    int Day, Month, Year;
};

void scanStruct(struct Date *dest, int nel) {
    for (int i = 0; i < nel; i++) {
        scanf("%04d %02d %02d", &dest[i].Year, &dest[i].Month, &dest[i].Day);
    }
}

void printStruct(struct Date *dest, int nel) {
    for (int i = 0; i < nel; i++) {
        printf("%04d %02d %02d \n", dest[i].Year, dest[i].Month, dest[i].Day);
    }
}

void dsort(struct Date *keys, struct Date *dest, int n, int m) { //n-nel, m - number of keys
    int k;
    int j = 0;
    int i = 1;
    int *count = calloc(m, sizeof(int));
    if (count == NULL)
        printf("failed to malloc");

    while (j < n) {
        k = (int) source[j].Day;
        count[k] = count[k] + 1;
        j += 1;
    }
    while (i < m) {
        count[i] = count[i] + count[i - 1];
        i += 1;
    }
    j = n - 1;

    for (int g; j >= 0; j--) {
        k = (int) source[j].Day;
        g = count[k] - 1;
        count[k] = g;
        dest[g].Day = source[j].Day;
    }
    free(count);
}

void radixSort(struct Date *source, struct Date *dest, int q, int n, int m){
    memcpy(dest, source, n * 12);
    for(int i = q - 1; i >= 0; i--){
        dsort(dest, dest, n, m);
    }

}

int main() {
    int nel;
    scanf("%d", &nel);

    struct Date dateSource[nel];
    struct Date dateDest[nel];
    scanStruct(dateSource, nel);
    dsort(dateSource, dateDest, nel, 31);
    printStruct(dateDest, nel);


    return 0;
}
