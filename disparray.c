#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

struct List {
    long key;
    long value;

    struct List *next;
};

struct HashTable {
    long size;

    struct List **list;
};

struct List *listSearch(struct List *list, long key);
struct HashTable *initHashTable(long m);
long lookup(struct HashTable *t, long key);
void delete(struct HashTable *t, long key);
void insert(struct HashTable *t, long key, long value);
void performOps(struct HashTable *t, long m);
void freeTable(struct HashTable *t);
void checkMem(int numOfPtrs, ...);


int main() {
    long m;
    scanf("%li", &m);
    struct HashTable *hashtable = initHashTable(m);
    performOps(hashtable, m);
    freeTable(hashtable);

    return 0;
}

void freeTable(struct HashTable *t) {
    for (long i = 0; i < t->size; i++) {
        while (t->list[i] != NULL) {
            struct List *toFree = t->list[i];
            t->list[i] = toFree->next;
            free(toFree);
        }
    }
    free(t->list);
    free(t);
}

void performOps(struct HashTable *t, long m) {
    char operation[7] = {'\0'};
    long i;
    long v;
    while (true) {
        scanf("%s %li %li", operation, &i, &v);
        if (operation[1] == 'T') // AT
            printf("%li\n", lookup(t, i));
        else if (operation[1] == 'S') //ASSIGN
            insert(t, i, v);
        else if (operation[1] == 'N') //END
            break;
    }
}

void insert(struct HashTable *t, long key, long value) {
    long i = key % t->size;
    struct List *found = listSearch(t->list[i], key);
    if (value == 0) {
        if (found != NULL)
            delete(t, key);
        return;
    }

    if (found == NULL) {
        struct List *p = malloc(sizeof(struct List));
        checkMem(1, p);
        p->key = key;
        p->value = value;
        p->next = t->list[i];
        t->list[i] = p;
    } else {
        found->value = value;
    }
}

void delete(struct HashTable *t, long key) {
    long i = key % t->size;
    struct List *y = NULL;
    struct List *x = t->list[i];
    while (x != NULL) {
        if (x->key == key) {
            if (y == NULL) {
                struct List *toDelete = t->list[i];
                t->list[i] = toDelete->next;
                free(toDelete);
            } else {
                struct List *toDelete = y->next;
                y->next = toDelete->next;
                free(toDelete);
            }
            return;
        }
        y = x;
        x = x->next;
    }
}

long lookup(struct HashTable *t, long key) {
    struct List *p = listSearch(t->list[key % t->size], key);
    if (p == NULL)
        return 0;
    else
        return p->value;
}

struct HashTable *initHashTable(long m) {
    struct HashTable *t = malloc(sizeof(struct HashTable));
    t->list = (struct List **) malloc(m * sizeof(struct List *));
    checkMem(2, t, t->list);
    t->size = m;
    for (long i = 0; i < m; i++) {
        t->list[i] = NULL;
    }
    return t;
}

struct List *listSearch(struct List *list, long key) {
    struct List *x = list;
    while (x != NULL && x->key != key)
        x = x->next;
    return x;
}
void checkMem(int numOfPtrs, ...) {
    /*this function is used to check mallocs or callocs,
     it returns index * -1 of NULL pointer (if exists) starting from 1 */
    va_list args;
    va_start(args, numOfPtrs);

    for(int i = 0; i < numOfPtrs; i++){
        if(va_arg(args, void*) == NULL){
            printf("\nFailed memory allocation, exiting\n");
            exit(-(i + 1));
        }
    }
    va_end(args);
}