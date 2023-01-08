#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue {
    long *data;
    long cap, count, head, tail;
};

void bufferOverflow(struct Queue *q);
void initQueue(struct Queue *q, long *buffer, long nel);
int queueEmpty(struct Queue *q);
void enqueue(struct Queue *q, long x);
long dequeue(struct Queue *q);
long getNOps();
void fENQ(char *secondWord, struct Queue *q);
void fDEQ(struct Queue *q);
void fEMPTY(struct Queue *q);
void performOps(struct Queue *q);

int main() {
    struct Queue *q = malloc(sizeof(struct Queue));
    long *buffer = malloc(4 * sizeof(long));
    initQueue(q, buffer, 4);

    performOps(q);

    free(q->data);
    free(q);
    return 0;
}

void bufferOverflow(struct Queue *q) {
    q->data = realloc(q->data, sizeof(long) * q->cap * 2);
    if (q->data == NULL)
        printf("failed buffer extension");
    memcpy(&q->data[q->cap + q->head], &q->data[q->head], sizeof(long) * (q->cap - q->head));
    q->head += q->cap;
    q->cap *= 2;
}

void initQueue(struct Queue *q, long *buffer, long nel) {
    q->data = buffer;
    q->cap = nel;
    q->count = 0;
    q->head = 0;
    q->tail = 0;
}

int queueEmpty(struct Queue *q) {
    if (q->count == 0)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue *q, long x) {
    if (q->count == q->cap)
        bufferOverflow(q);
    q->data[q->tail] = x;
    q->tail += 1;
    if (q->tail == q->cap)
        q->tail = 0;
    q->count += 1;
}

long dequeue(struct Queue *q) {
    if (queueEmpty(q) == 1)
        printf("empty");
    long x = q->data[q->head];
    q->head += 1;
    if (q->head == q->cap)
        q->head = 0;
    q->count -= 1;
    return x;
}

void fENQ(char *secondWord, struct Queue *q) {
    char *end;
    long x = strtol(secondWord, &end, 10);
    enqueue(q, x);
}

void fDEQ(struct Queue *q) {
    long x = dequeue(q);
    printf("%li ", x);
}

void fEMPTY(struct Queue *q) {
    int isEmpty = queueEmpty(q);
    if (isEmpty == 1)
        printf("true ");
    else
        printf("false ");
}

void performOps(struct Queue *q) {
    char *currentOp = malloc(20);
    char *firstWord;
    char *secondWord;
    while (1) {
        fgets(currentOp, 20, stdin);
        firstWord = strtok(currentOp, " \r\n");
        secondWord = strtok(NULL, " \r\n");
        if (strcmp(firstWord, "ENQ") == 0)
            fENQ(secondWord, q);
        else if (strcmp(firstWord, "DEQ") == 0)
            fDEQ(q);
        else if (strcmp(firstWord, "EMPTY") == 0)
            fEMPTY(q);
        else if (strcmp(firstWord, "END") == 0)
            break;
        else
            printf("invalid operation");
    }
    free(currentOp);
}