#include <stdio.h>
#include <stdlib.h>

struct Task {
    int low, high;
};

struct Stack {
    long cap;
    long top;
    struct Task* data;
};

void push(struct Stack *stack, struct Task task){
    if(stack->top == stack->cap){
        printf("stackoverflow\n");
    }
    stack->data[stack->top] = task;
    stack->top += 1;
}

struct Task pop(struct Stack *stack){
    if(stack->top == 0){
        printf("\n stack is empty\n");
    }
    struct Task popped = stack->data[stack->top - 1];
    stack->top -= 1;
    return popped;
}

void swap(long* array, long i, long j){
    long swapbuf = array[i];
    array[i] = array[j];
    array[j] = swapbuf;
}

long part(long* array, struct Task task){ //from lections module 2
    long i = task.low;
    long j = task.low;
    long high = task.high;
    while (j <= high){
        if(array[j] < array[high]){
            swap(array, i, j);
            ++i;
        }
        ++j;
    }
    swap(array, i, high);
    return i;
}

void quicksortNonRec(long* array, long nel) {
    struct Task *data = calloc(nel, sizeof(struct Task));
    struct Stack stack = {nel, 0, data};

    struct Task initialPush = {0, (int)nel - 1};
    push(&stack, initialPush);

    while(stack.top){
        struct Task popped = pop(&stack);
        int low = popped.low;
        int high = popped.high;
        long p = part(array, popped);
        if(p - 1 > low){
            struct Task toPush = {low, (int)p - 1};
            push(&stack, toPush);
        }
        if(p + 1 < high){
            struct Task toPush = {(int)p + 1, high};
            push(&stack, toPush);
        }
    }
    free(data);
}

int main(){
    long n;
    scanf("%li", &n);

    long* array = calloc(n, sizeof(long));
    for(int i = 0; i < n; ++i){
        scanf("%li", &array[i]);
    }

    quicksortNonRec(array, n);

    for(int i = 0; i < n; ++i){
        printf("%li ", array[i]);
    }

    free(array);
    return 0;
}