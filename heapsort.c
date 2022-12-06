#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b);
void swap(void *base, int a, int b, size_t width);
void hsort(void *base, size_t nel, size_t width,
           int (*compare)(const void *a, const void *b));


int main() {
    int nel;
    scanf("%d", &nel);
    char src[nel][1001];
    for (int i = 0; i < nel; i++) {
        scanf("%s", src[i]);

    }
    hsort(src, nel, 1001, compare);
    for (int i = 0; i < nel; ++i) {
        printf("%s \n", src[i]);
    }
    printf("\n");
    return 0;
}

int compare(const void *a, const void *b) {
    int counterA = 0;
    int counterB = 0;
    char elementA = *(char *) a;
    char elementB = *(char *) b;
    for (int i = 0; i < 1001 && elementA != '\0'; i++) {
        if (elementA == 'a')
            counterA += 1;
        elementA = *(char *) (a + i);
    }
    for (int i = 0; i < 1001 && elementB != '\0'; i++) {
        if (elementB == 'a')
            counterB += 1;
        elementB = *(char *) (b + i);
    }
    return counterA - counterB;
}

void swap(void *base, int a, int b, size_t width) {
    void *swapBuffer = malloc(width);
    memcpy(swapBuffer, base + a * width, width);
    memcpy(base + a * width, base + b * width, width);
    memcpy(base + b * width, swapBuffer, width);
    free(swapBuffer);
}

void hsort(void *base, size_t nel, size_t width, int (*compare)(const void *, const void *)) {
    for (int i1 = ((int) nel / 2) - 1; i1 >= 0; i1--) { //inlined buildheap from lection
        int i = i1;
        while (1 == 1) {
            int l = 2 * i + 1;
            int r = l + 1;
            int j = i;
            if (l < nel && (compare(base + i * width, base + l * width) < 0))
                i = l;
            if (r < nel && (compare(base + i * width, base + r * width) < 1))
                i = r;
            if (i == j)
                break;
            swap(base, i, j, width);
        }
    }
    for (int i = (int) nel - 1; i > 0; i--) {
        swap(base, 0, i, width);
        int i1 = 0; //inlined heapify from lection
        while (1 == 1) {
            int l = 2 * i1 + 1;
            int r = l + 1;
            int j = i1;
            if (l < i && (compare(base + i1 * width, base + l * width) < 0))
                i1 = l;
            if (r < i && (compare(base + i1 * width, base + r * width) < 1))
                i1 = r;
            if (i1 == j)
                break;
            swap(base, i1, j, width);
        }
    }
}