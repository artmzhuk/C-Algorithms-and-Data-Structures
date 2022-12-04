#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct Stack {
    long data[100000];
    long cap;
    long top;
};

void performOps(struct Stack *stack, long n);
void initStack(struct Stack *stack, long n);
int stackEmpty(struct Stack *stack);
void push(struct Stack *stack, long x);
long pop(struct Stack *stack);
void fCONST(char *secondWord, struct Stack *stack);
void fADD(struct Stack *stack);
void fSUB(struct Stack *stack);
void fMUL(struct Stack *stack);
void fDIV(struct Stack *stack);
void fMAX(struct Stack *stack);
void fMIN(struct Stack *stack);
void fNEG(struct Stack *stack);
void fDUP(struct Stack *stack);
void fSWAP(struct Stack *stack);
long getNOps();

int main() {
    struct Stack *stack = malloc(sizeof(struct Stack));
    if (stack == NULL)
        return -1;

    long nOps = getNOps();
    performOps(stack, nOps);
    printf("%li", pop(stack));

    free(stack);
    return 0;
}

void initStack(struct Stack *stack, long n) {
    stack->cap = n;
    stack->top = 0;
}

int stackEmpty(struct Stack *stack) {
    if (stack->top == 0)
        return 1;
    else
        return 0;
}

void push(struct Stack *stack, long x) {
    if (stack->top == stack->cap)
        printf("error: overflow");
    stack->data[stack->top] = x;
    stack->top += 1;
}

long pop(struct Stack *stack) {
    if (stackEmpty(stack) == 1)
        printf("error: empty");
    stack->top -= 1;
    long x = stack->data[stack->top];
    return x;
}

void fCONST(char *secondWord, struct Stack *stack) {
    char *end;
    long x = strtol(secondWord, &end, 10);
    push(stack, x);
}

void fADD(struct Stack *stack) {
    long a = pop(stack);
    long b = pop(stack);
    push(stack, a + b);
}

void fSUB(struct Stack *stack) {
    long a = pop(stack);
    long b = pop(stack);
    push(stack, a - b);
}

void fMUL(struct Stack *stack) {
    long a = pop(stack);
    long b = pop(stack);
    push(stack, a * b);
}

void fDIV(struct Stack *stack) {
    long a = pop(stack);
    long b = pop(stack);
    push(stack, a / b);
}

void fMAX(struct Stack *stack) {
    long a = pop(stack);
    long b = pop(stack);
    push(stack, MAX(a, b));
}

void fMIN(struct Stack *stack) {
    long a = pop(stack);
    long b = pop(stack);
    push(stack, MIN(a, b));
}

void fNEG(struct Stack *stack) {
    long a = pop(stack);
    push(stack, -1 * a);
}

void fDUP(struct Stack *stack) {
    long a = pop(stack);
    push(stack, a);
    push(stack, a);
}

void fSWAP(struct Stack *stack) {
    long a = pop(stack);
    long b = pop(stack);
    push(stack, a);
    push(stack, b);
}

void performOps(struct Stack *stack, long n) {
    initStack(stack, n);
    char *currentOp = malloc(20);
    char *firstWord;
    char *secondWord;
    for (int i = 0; i < n; i++) {
        fgets(currentOp, 20, stdin);
        firstWord = strtok(currentOp, " \r\n");
        secondWord = strtok(NULL, " \r\n");
        if (strcmp(firstWord, "CONST") == 0)
            fCONST(secondWord, stack);
        else if (strcmp(firstWord, "ADD") == 0)
            fADD(stack);
        else if (strcmp(firstWord, "SUB") == 0)
            fSUB(stack);
        else if (strcmp(firstWord, "MUL") == 0)
            fMUL(stack);
        else if (strcmp(firstWord, "DIV") == 0)
            fDIV(stack);
        else if (strcmp(firstWord, "MAX") == 0)
            fMAX(stack);
        else if (strcmp(firstWord, "MIN") == 0)
            fMIN(stack);
        else if (strcmp(firstWord, "NEG") == 0)
            fNEG(stack);
        else if (strcmp(firstWord, "DUP") == 0)
            fDUP(stack);
        else if (strcmp(firstWord, "SWAP") == 0)
            fSWAP(stack);
        else
            printf("invalid operation");
    }
    free(currentOp);
}

long getNOps() {
    char* end;
    char* nOps = malloc(10);
    fgets(nOps, 10, stdin);
    long x = strtol(nOps, &end, 10);
    free(nOps);
    return x;
}