#include <stdio.h>
#include <stdlib.h>

struct Array {
    long *data;
    long nextId; //stores id of next element to insert in priority queue
    long length;
};

struct Queue {
    long *heap;
    long *arrayIdx;
    long count;
};

void swap(struct Queue *queue, long a, long b) {
    long swapBufValue = queue->heap[a];
    long swapBufId = queue->arrayIdx[a];
    queue->heap[a] = queue->heap[b];
    queue->arrayIdx[a] = queue->arrayIdx[b];
    queue->heap[b] = swapBufValue;
    queue->arrayIdx[b] = swapBufId;
}

void Insert(struct Queue *queue, struct Array *array, long idx) {
    long i = queue->count;
    if (array[idx].nextId != array[idx].length) {
        queue->count++;
        queue->heap[i] = array[idx].data[array[idx].nextId];
        array[idx].nextId++;
        queue->arrayIdx[i] = idx;
        while (i > 0 && queue->heap[(i - 1) / 2] > queue->heap[i]) {
            swap(queue, (i - 1) / 2, i);
            i = (i - 1) / 2;
        }
    }
}

void Heapify(struct Queue *queue, long i, long n) {
    while (1) {
        long l = 2 * i + 1;
        long r = l + 1;
        long j = i;
        if (l < n && queue->heap[i] > queue->heap[l])
            i = l;
        if (r < n && queue->heap[i] > queue->heap[r])
            i = r;
        if (i == j)
            break;
        swap(queue, i, j);
    }
}

long Extract(struct Queue *queue, long *extractedIdx) {
    if (queue->count == 0) {
        printf("\nExtract Error\n");
        return 0;
    }
    long extracted = queue->heap[0];
    *extractedIdx = queue->arrayIdx[0];
    queue->count--;
    if (queue->count > 0) {
        swap(queue, 0, queue->count);
        Heapify(queue, 0, queue->count);
    }
    return extracted;
}

long *merge(struct Array *source, long k, long total_len) {
    long *output = malloc(total_len * sizeof(long));
    long *heap = malloc(k * sizeof(long));
    long *arrayIdxs = malloc(k * sizeof(long));
    long outputCounter = 0;
    struct Queue queue = {heap, arrayIdxs, 0};
    for (long i = 0; i < k; ++i) {
        Insert(&queue, source, i);
    }
    while (queue.count != 0) {
        long extractedIdx;
        output[outputCounter] = Extract(&queue, &extractedIdx);
        outputCounter++;
        Insert(&queue, source, extractedIdx);
    }
    free(heap);
    free(arrayIdxs);
    return output;
}

int main() {
    long k;
    long total_len = 0;
    scanf("%li", &k);
    struct Array *source = malloc(k * sizeof(struct Array));

    for (long i = 0; i < k; ++i) { // scans lengths and allocates memory for data
        long length;
        scanf("%li", &length);
        source[i].data = malloc(length * sizeof(long));
        source[i].length = length;
        total_len += length;
    }
    for (long i = 0; i < k; ++i) {
        for (long j = 0; j < source[i].length; ++j) {
            scanf("%li", &source[i].data[j]);
        }
        source[i].nextId = 0;
    }

    long *result = merge(source, k, total_len);

    for (long i = 0; i < total_len; ++i) {
        printf("%li ", result[i]);
    }

    for (long i = 0; i < k; ++i) {
        free(source[i].data);
    }
    free(source);
    free(result);
    return 0;
}