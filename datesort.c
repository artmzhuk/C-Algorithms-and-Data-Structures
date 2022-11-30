#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int Day, Month, Year;
};

void scanStruct(struct Date *dest, int nel);
void printStruct(struct Date *dest, int nel);
void dsort(const int *key, int radix, struct Date *source, int n, struct Date *dest);
void generateKeys(struct Date *source, int *keys, int n, int id, int *radix);
void radixSort(struct Date *source, struct Date *dest, int q, int n);

int main() {
    int nel;
    scanf("%d", &nel);
    struct Date dateSource[nel];
    struct Date dateDest[nel];
    scanStruct(dateSource, nel);
    radixSort(dateSource, dateDest, 6, nel);// q = 6 for dates(2 for day, month, year)
    printStruct(dateDest, nel);
    return 0;
}

void scanStruct(struct Date *dest, int nel) {
    for (int i = 0; i < nel; i++) {
        scanf("%04d %02d %02d", &dest[i].Year, &dest[i].Month, &dest[i].Day);
    }
    for (int i = 0; i < nel; i++) {
        dest[i].Year -= 1970;
    }
}

void printStruct(struct Date *dest, int nel) {
    for (int i = 0; i < nel; i++) {
        dest[i].Year += 1970;
        printf("%04d %02d %02d", dest[i].Year, dest[i].Month, dest[i].Day);
        printf("\n");
    }
}

void dsort(const int *key, int radix, struct Date *source, int n, struct Date *dest) { //n-nel, m - number of keys
    int k;
    int j = 0;
    int i = 1;
    int *count = calloc(radix, sizeof(int));

    while (j < n) {
        k = key[j];
        count[k] = count[k] + 1;
        j += 1;
    }
    while (i < radix) {
        count[i] = count[i] + count[i - 1];
        i += 1;
    }
    j = n - 1;

    for (int g; j >= 0; j--) {
        k = (int) key[j];
        g = count[k] - 1;
        count[k] = g;
        dest[g] = source[j];
    }
    free(count);
}

void generateKeys(struct Date *source, int *keys, int n, int id, int *radix) {
    for (int i = 0; i < n; i++) {
        switch (id) {
            case 0:
                keys[i] = source[i].Year / 10; // first digit of year -1970
                *radix = 7;
                break;
            case 1:
                keys[i] = source[i].Year % 10; // second digit of year -1970
                *radix = 10;
                break;
            case 2:
                keys[i] = source[i].Month / 10; // first digit of month
                *radix = 2;
                break;
            case 3:
                keys[i] = source[i].Month % 10; // second digit of month
                *radix = 10;
                break;
            case 4:
                keys[i] = source[i].Day / 10; // first digit of day
                *radix = 4;
                break;
            case 5:
                keys[i] = source[i].Day % 10; // second digit of day
                *radix = 10;
                break;
            default:
                printf("keys function error");
        }
    }
}

void radixSort(struct Date *source, struct Date *dest, int q, int n) {
    int keys[n];
    int *radix = malloc(sizeof(int)); //number of digits in single position (razryad?)
    memcpy(dest, source, sizeof(struct Date) * n);

    for (int id = q - 1; id >= 0; id--) {
        generateKeys(source, keys, n, id, radix);
        dsort(keys, *radix, source, n, dest);
        memcpy(source, dest, sizeof(struct Date) * n);
    }
    free(radix);
}