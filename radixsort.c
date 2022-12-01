#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

void scanArray(union Int32* array, int nel){ //also flipping the sign bit (to add support of negative numbers)
    for(int i = 0; i < nel; i++){
        scanf("%d", &array[i].x);
        array[i].bytes[3] ^= (unsigned char) 128; //flipping the sign bit
    }
}

void printArray(union Int32* array, int nel){
    for(int i = 0; i < nel; i++){
        array[i].bytes[3] ^= (unsigned char) 128; //flipping the sign bit back
        printf("%d ", array[i].x);
    }
}

void generateKeys(union Int32 *source, int charN, int nel, unsigned char* keys){
    for(int i = 0; i < nel; i++){
        keys[i] = source[i].bytes[charN];
    }
}

void dsort(const unsigned char *key, int radix, union Int32 *source, int n, union Int32 *dest) { //n-nel, m - number of keys
    unsigned char k;
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
        k = key[j];
        g = count[k] - 1;
        count[k] = g;
        dest[g].x = source[j].x;
    }
    free(count);
}

void radixSort(union Int32 *source, union Int32 *dest, int nel) {
    unsigned char keys[nel];
    //int *radix = malloc(1); //number of digits in single position (razryad?)
    memcpy(dest, source, sizeof(int) * nel);

    for (int id = 0; id <= 3; id++) {
        generateKeys(source, id, nel, keys);
        dsort(keys, 256, source, nel, dest);
        memcpy(source, dest, sizeof(int) * nel);
    }
    //free(radix);
}

int main(){
    int nel;
    scanf("%d", &nel);
    union Int32 source[nel];
    union Int32 dest[nel];
    scanArray(source, nel);
    radixSort(source, dest, nel);
    printArray(dest, nel);


    return 0;
}