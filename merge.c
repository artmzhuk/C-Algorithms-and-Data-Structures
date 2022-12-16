#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct heapstr{
    long index, k, v, v1;
};

struct q{
    struct heapstr* heap;
    long cap;
    long count;
};

int queueEmpty(struct q* src);
void insert(struct q* src, struct heapstr ptr);
void heapify(long i, long n, struct heapstr* heap);
struct heapstr extractMin(struct q* src);
long scanLenghts(long* lengths, long k);
void scanArrays(long** arrays ,long* lenghts, long k);
void merge(long k, long n, long **arrays,long* lengths, long* result);
void InitPriorityQueue(struct q* src, struct heapstr* heap, long nel);

int main(){
    long k;
    scanf("%li", &k);

    long lengths[k];
    long n = scanLenghts(lengths, k);

    long **arrays = malloc(sizeof(long*) * k);
    scanArrays(arrays, lengths, k);

    long result[n];

    merge(k, n, arrays, lengths, result);

    for(long i = 0; i < n; i++){
        printf("%li ", result[i]);
    }

    for(long i = 0; i < k; i++)
        free(arrays[i]);

    free(arrays);
    return 0;
}

void InitPriorityQueue(struct q *src, struct heapstr *heap, long nel) {
    src->heap = heap;
    src->cap = nel;
    src->count = 0;
}

int queueEmpty(struct q *src) {
    if(src->count == 0)
        return 1;
    else
        return 0;
}

void insert(struct q *src, struct heapstr ptr) {
    long i = src->count;
    if(i == src->cap)
        printf("\noverflow\n");
    src->count = i + 1;
    src->heap[i].k = ptr.k;
    src->heap[i].v = ptr.v;
    src->heap[i].v1 = ptr.v1;
    while(i > 0 && src->heap[(i-1)/2].k > src->heap[i].k){
        struct heapstr swapbuffer;
        swapbuffer = src->heap[(i-1)/2];
        src->heap[(i-1)/2] = src->heap[i];
        src->heap[i] = swapbuffer;

        src->heap[i].index = i;
        i = (i - 1) / 2;
    }
    src->heap[i].index = i;
}

void heapify(long i, long n, struct heapstr *heap) {
    long l, r, j;
    while (true){
        l = 2 * i + 1;
        r = l + 1;
        j = i;
        if(l < n && heap[i].k > heap[l].k)
            i = l;
        if(r < n && heap[i].k > heap[r].k)
            i = r;
        if(i == j)
            break;
        struct heapstr swapbuf = heap[i];
        heap[i] = heap[j];
        heap[j] = swapbuf;
        heap[i].index = i;
        heap[j].index = j;
    }
}

struct heapstr extractMin(struct q *src) {
    if(src->count == 0)
        printf("\nqueue is empty\n");
    struct heapstr ptr = src->heap[0];
    src->count -= 1;
    if(src->count > 0){
        src->heap[0] = src->heap[src->count];
        src->heap[0].index = 0;
        heapify(0, src->count, src->heap);
    }
    return ptr;
}

long scanLenghts(long *lengths, long k) {
    long sum = 0;
    for(long i = 0; i < k; i++){
        scanf("%li", &lengths[i]);
        sum += lengths[i];
    }
    return sum;
}

void scanArrays(long **arrays, long *lenghts, long k) {
    for(long i = 0; i < k; i++){
        arrays[i] = malloc(sizeof(long) * lenghts[i]);
        for(long j = 0; j < lenghts[i]; j++)
            scanf("%li", &arrays[i][j]);
    }
}

void merge(long k, long n, long **arrays, long *lengths, long *result) {
    struct heapstr* heap = calloc(k, sizeof(struct heapstr));
    struct q* queue = calloc(1, sizeof(struct q));
    InitPriorityQueue(queue, heap, n);
    for(long i = 0; i < k; i++){
        struct heapstr inserted = {i, arrays[i][0], i, 0};//k = value of array element, v = array index, v1- index in array
        insert(queue, inserted);
    }
    int i = 0;
    while(queueEmpty(queue) != 1){
        struct heapstr extracted = extractMin(queue);
        result[i] = extracted.k;
        if(extracted.v1 < lengths[extracted.v] - 1){
            struct heapstr inserted = {extracted.index, arrays[extracted.v][extracted.v1 + 1],extracted.v, (extracted.v1 + 1)};
            insert(queue, inserted);
        }
        i++;
    }
    free(heap);
    free(queue);
}