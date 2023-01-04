#include <stdio.h>
#include <stdlib.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

struct List {
    struct Elem *head, *tail;
};

void scanElem(struct Elem *elements, long nel);
void cut(struct Elem *N);
void insertAfter(struct Elem *x, struct Elem *y);
struct List initListInfo(struct Elem *elements, long nel);
void insertsort(struct List *list);
void printList(struct List list, long nel);

int main() {
    long nel;
    scanf("%li", &nel);
    struct Elem *elements = malloc(nel * sizeof(struct Elem));
    scanElem(elements, nel);
    struct List list = initListInfo(elements, nel);
    insertsort(&list);

    printList(list, nel);

    free(elements);
    return 0;
}

void scanElem(struct Elem *elements, long nel) { //scans elements to the list
    int value;
    scanf("%d", &value);
    if (nel >= 2) {
        elements[0].v = value;
        elements[0].next = &elements[1];
        elements[0].prev = &elements[nel - 1];
        elements[nel - 1].next = &elements[0];
        elements[nel - 1].prev = &elements[nel - 2];
    } else {
        elements[0].v = value;
        elements[0].next = &elements[0];
        elements[0].prev = &elements[0];
        return;
    }
    for (long i = 1; i < nel - 1; i++) {
        scanf("%d", &value);
        elements[i].v = value;
        elements[i].prev = &elements[i - 1];
        elements[i].next = &elements[i + 1];
    }
    scanf("%d", &value);
    elements[nel - 1].v = value;
}

void cut(struct Elem *N) {
    struct Elem *A = N->prev;
    struct Elem *B = N->next;
    A->next = B;
    B->prev = A;
}

void insertAfter(struct Elem *x, struct Elem *y) { // removes y from it's position and places after x
    struct Elem *z = x->next;
    x->next = y;
    y->prev = x;
    y->next = z;
    z->prev = y;
}

struct List initListInfo(struct Elem *elements, long nel) { //initializes info about list (ptr to tail & head)
    struct List info;
    info.head = &elements[0];
    info.tail = &elements[nel - 1];
    return info;
}

void insertsort(struct List *list) { // performs insertion sort on list
    struct Elem *S = list->head;
    struct Elem *N;
    struct Elem *K;
    while (S->next != list->head) {
        N = S->next;
        if (N->v >= S->v)
            S = N;
        else {
            K = S;
            cut(N);
            while (K != list->head && K->prev->v > N->v)
                K = K->prev;
            insertAfter(K->prev, N);
            if (N->prev == list->tail) {
                list->head = N;
                continue;
            }
            if (N == list->tail) {
                list->head = N;
                break;
            }
        }
    }
    list->head = S->next;
    list->tail = S;

}

void printList(struct List list, long nel) { //prints list (based of its head and nel)
    struct Elem *current = list.head;
    for (long i = 0; i < nel; i++) {
        printf("%d ", current->v);
        current = current->next;
    }
}