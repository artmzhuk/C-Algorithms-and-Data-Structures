#include <stdio.h>
#include <stdlib.h>

struct Task {
    int low, high;
};

struct Stack {;
    struct Task* tasks;//array of (struct Task)
    int top;
};

int stackEmpty(struct Stack *stack);
void push(struct Stack *stack, int low, int high);
struct Task pop(struct Stack *stack);
void swap(long* a, long* b);
int partition(int low, int high, long* array);
void qssort(long* array, int low, int high);
void scanArray(long* array, int nel);
void printArray(long* array, int nel);

int main(){
    int nel;
    scanf("%d", &nel);
    long array[nel];
    scanArray(array, nel);
    qssort(array, 0, nel - 1);
    printArray(array, nel);
    return 0;
}

void printArray(long *array, int nel) {
    for(int i = 0; i < nel; i++){
        printf("%li ", array[i]);
    }
}

void scanArray(long *array, int nel) {
    for(int i = 0; i < nel; i++){
        scanf("%li", &array[i]);
    }
}

void qssort(long *array, int low, int high) {
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->tasks = malloc(high * sizeof(struct Task));
    stack->top = 0;
    struct Task currentTask;
    push(stack, low, high);
    while(stack->top > 0){
        currentTask = pop(stack);
        int pivot = partition(currentTask.low, currentTask.high, array);
        if(pivot - 1 > currentTask.low)
            push(stack, currentTask.low, pivot - 1);
        if(pivot + 1 < currentTask.high)
            push(stack, pivot + 1, currentTask.high);
    }
    free(stack->tasks);
    free(stack);
}

int partition(int low, int high, long *array) {
    int i = low;
    for(int j = low; j < high; j++){
        if(array[j] < array[high]){
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[high]);
    return i; //returns index of pivot element
}

void swap(long *a, long *b) {
    long tmp = *a;
    *a = *b;
    *b = tmp;
}

struct Task pop(struct Stack *stack) {
    stack->top -= 1;
    struct Task poppedTask = stack->tasks[stack->top];
    return poppedTask;
}

void push(struct Stack *stack, int low, int high) {
    stack->tasks[stack->top].low = low;
    stack->tasks[stack->top].high = high;
    stack->top += 1;
}

int stackEmpty(struct Stack *stack) {
    if (stack->top == 0)
        return 1;
    else
        return 0;
}