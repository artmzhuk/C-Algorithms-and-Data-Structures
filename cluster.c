#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct task{
    long tstart, tdelta, tfinish;
};

struct queue{
    struct task* tasks;
    long count;
};

void InitPriorityQueue(struct queue *q, struct task* tasks);
void insert(struct queue *q, struct task task);
void heapify(long i, long n, struct task* tasks);
long extractMin(struct queue *q);
void scanTasks(struct task* tasks,long nel);
long runClaster(struct queue q, struct task* tasks, long CPUs, long tasksAmount);

int main(){
    long N, M;
    scanf("%li %li", &N, &M);

    struct queue q;
    struct task* tasks = calloc((M + 1), sizeof(struct task));
    InitPriorityQueue(&q, tasks);
    scanTasks(tasks, M);
    long res = runClaster(q, tasks, N, M);
    printf("%li", res);

    free(tasks);
    return 0;
}

void InitPriorityQueue(struct queue *q, struct task *tasks) {
    q->tasks = tasks;
    q->count = 0;
}

void insert(struct queue *q, struct task task) {
    long i = q->count;
    q->count = i + 1;
    q->tasks[i] = task;
    while (i > 0 && q->tasks[(i-1)/2].tfinish > q->tasks[i].tfinish){
        struct task swapbuf = q->tasks[i];
        q->tasks[i] = q->tasks[(i-1)/2];
        q->tasks[(i-1)/2] = swapbuf;
        i = (i - 1) / 2;
    }
}

void heapify(long i, long n, struct task *tasks) {
    struct task swapbuf;
    while(1){
        long l = 2 * i + 1;
        long r = l + 1;
        long j = i;
        if(l < n && tasks[i].tfinish > tasks[l].tfinish)
            i = l;
        if(r < n && tasks[i].tfinish > tasks[r].tfinish)
            i = r;
        if (i == j)
            break;
        swapbuf = tasks[j];
        tasks[j] = tasks[i];
        tasks[i] = swapbuf;
    }
}

long extractMin(struct queue *q) {
    struct task result = q->tasks[0];
    q->count -= 1;
    if(q->count > 0){
        q->tasks[0] = q->tasks[q->count];
        heapify(0, q->count, q->tasks);
    }
    return result.tfinish;
}

void scanTasks(struct task *tasks, long nel) {
    for(long i = 0; i < nel; i++){
        scanf("%li %li", &tasks[i].tstart, &tasks[i].tdelta);
    }
}

long runClaster(struct queue q, struct task *tasks, long CPUs, long tasksAmount) {
    if(CPUs >= tasksAmount){ //checks if there is enough CPUs to perform all tasks simultaneously
        long result = 0;
        for(long i = 0; i < tasksAmount; i++){
            result = MAX(result, tasks[i].tstart + tasks[i].tdelta);
        }
        return result;
    }
    for(long i = 0; i < CPUs; i++){ //inserts first tasks
        tasks[i].tfinish = tasks[i].tstart + tasks[i].tdelta;
        insert(&q, tasks[i]);
    }
    long performedTasks = CPUs - 1;
    long currentTime = tasks[0].tfinish;

    while (1){
        if(performedTasks < tasksAmount - 1
           && currentTime >= tasks[performedTasks + 1].tstart){ //at least 1 CPU is available
            extractMin(&q);
            performedTasks++;
            tasks[performedTasks].tfinish = currentTime + tasks[performedTasks].tdelta;
            insert(&q, tasks[performedTasks]);
            currentTime = tasks[0].tfinish;
        }
        else if (performedTasks < tasksAmount - 1){ //no CPUs available at the moment
            currentTime = tasks[performedTasks + 1].tstart;
            extractMin(&q);
            performedTasks++;
            tasks[performedTasks].tfinish = tasks[performedTasks].tstart + tasks[performedTasks].tdelta;
            insert(&q, tasks[performedTasks]);
            currentTime = tasks[0].tfinish;
        }
        else if(performedTasks == tasksAmount - 1){ //perform last tasks
            for(long i = CPUs; i > 0; i--){
                extractMin(&q);
                currentTime = tasks[0].tfinish;
            }
            break;
        }
    }
    return currentTime;
}