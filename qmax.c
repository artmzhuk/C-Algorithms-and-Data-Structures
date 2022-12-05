#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dStack{
    long* data;
    long cap, top1, top2;
};
/*queue functions (based on double stack)
vvvvvvvvvvvvvvvvvvvvvvv*/
void initStack(struct dStack* s,long nel , long* data);
int stackEmpty1(struct dStack* s);
int stackEmpty2(struct dStack* s);
void push1(struct dStack* s, long x);
void push2(struct dStack* s, long x);
long pop1(struct dStack* s);
long pop2(struct dStack* s);
int queueEmpty(struct dStack* s);
long popQueue(struct dStack* s);
/*deque functions
vvvvvvvvvvvvvvvvvvvvvvv*/
long getRearElementDeq(struct dStack* D);
long getFirstElementDeq(struct dStack* D);
long getFirstElementQue(struct dStack* Q);
long popDeque(struct dStack* D);
void Enqueue(struct dStack* Q, struct dStack* D, long x);
long Dequeue(struct dStack* Q, struct dStack* D);
long Maximum(struct dStack* D);
/*string functions
vvvvvvvvvvvvvvvvvvvvvvvv*/
long getNOps();

void performOps(struct dStack* Q, struct dStack* D, long n) {
    char *currentOp = malloc(20);
    char *firstWord;
    char *secondWord;
    for (int i = 0; i < n; i++) {
        fgets(currentOp, 20, stdin);
        firstWord = strtok(currentOp, " \r\n");
        secondWord = strtok(NULL, " \r\n");
        if (strcmp(firstWord, "ENQ") == 0){
            char *end;
            long x = strtol(secondWord, &end, 10);
            Enqueue(Q, D, x);
        }
        else if (strcmp(firstWord, "DEQ") == 0){
            printf("%li\n", Dequeue(Q, D));
        }
        else if (strcmp(firstWord, "MAX") == 0){
            printf("%liM\n", Maximum(D));
        }
        else if (strcmp(firstWord, "EMPTY") == 0){
            if(queueEmpty(Q) == 1)
                printf("true \n");
            else
                printf("false \n");
        }
        else
            printf("invalid operation");
    }
    free(currentOp);
}

int main(){
    long NOps = getNOps();

    struct dStack* Queue = malloc(sizeof(struct dStack));
    struct dStack* Deque = malloc(sizeof(struct dStack));
    long* dataQ = malloc(NOps * sizeof(long));
    long* dataD = malloc( NOps * sizeof(long));
    if(!(dataQ && dataD && Queue && Deque)) // checking mallocs
        return -1;

    initStack(Queue, NOps, dataQ);
    initStack(Deque, NOps, dataD);
    performOps(Queue, Deque, NOps);

    free(dataD);
    free(dataQ);
    free(Queue);
    free(Deque);
    return 0;
}
void initStack(struct dStack *s, long nel, long *data) {
    s->data = data;
    s->cap = nel;
    s->top1 = 0;
    s->top2 = nel - 1;
}

int stackEmpty1(struct dStack *s) {
    if(s->top1 == 0)
        return  1;
    else
        return 0;
}

int stackEmpty2(struct dStack *s) {
    if(s->top2 == s->cap - 1)
        return 1;
    else
        return 0;
}

void push1(struct dStack *s, long x) {
    if(s->top2 < s->top1)
        printf("overflow");
    s->data[s->top1] = x;
    s->top1 += 1;
}

void push2(struct dStack *s, long x) {
    if(s->top2 < s->top1)
        printf("overflow");
    s->data[s->top2] = x;
    s->top2 -= 1;
}

long pop1(struct dStack *s) {
    if(stackEmpty1(s) == 1)
        printf("empty");
    s->top1 -= 1;
    long x = s->data[s->top1];
    return x;
}

long pop2(struct dStack *s) {
    if (stackEmpty2(s) == 1)
        printf("empty");
    s->top2 += 1;
    long x = s->data[s->top2];
    return x;
}

int queueEmpty(struct dStack *s) {
    if(stackEmpty1(s) == 1 && stackEmpty2(s) == 1)
        return 1;
    else
        return 0;
}

long popQueue(struct dStack *s) { //also deck pop from end
    if(stackEmpty2(s) == 1)
        while (stackEmpty1(s) == 0)
            push2(s, pop1(s));
    long x = pop2(s);
    return x;
}

long getRearElementDeq(struct dStack *D) {
    if(D->top2 + 1 < D->cap){
        return D->data[D->top2 + 1];
    }
    else{
        return D->data[0];
    }
}

long getFirstElementDeq(struct dStack *D) {
    if(D->top1 > 0)
        return D->data[D->top1 - 1];
    else
        return D->data[D->cap - 1];
}

long getFirstElementQue(struct dStack *Q) {
    if(stackEmpty2(Q) == 1)
        return Q->data[0];
    else
        return Q->data[Q->top2 - 1];
}

long popDeque(struct dStack *D) {
    if(stackEmpty1(D) == 1)
        while (stackEmpty2(D) == 0)
            push1(D, pop2(D));
    long x = pop1(D);
    return x;
}

void Enqueue(struct dStack *Q, struct dStack *D, long x) {
    push1(Q, x);
    if(queueEmpty(D) == 1)
        push2(D, x);
    else{
        while(getRearElementDeq(D) < x && queueEmpty(D) == 0)
            popDeque(D);
        push2(D, x);
    }
}

long Dequeue(struct dStack *Q, struct dStack *D) {
    long res;
    if(getFirstElementDeq(D) == getFirstElementQue(Q)){
        res = popQueue(Q);
        popDeque(D);
    } else{
        res = popQueue(Q);
    }
    return res;
}

long Maximum(struct dStack *D) {
    return getFirstElementDeq(D);
}

long getNOps() {
    char* end;
    char* nOps = malloc(10);
    fgets(nOps, 10, stdin);
    long x = strtol(nOps, &end, 10);
    free(nOps);
    return x;
}
