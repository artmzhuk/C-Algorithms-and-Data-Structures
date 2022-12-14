#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

void build(long v, long a, long b, long* tree, long* source);
long query(long v, long a, long b, long l, long r, long* tree);
void update(long v, long a, long b, long i, long value, long* tree);
void scanElements(long nel, long* array);
void performOps(long *source, long nel, long* tree);

int main(){
    long nel;
    scanf("%li", &nel);

    long source[nel];
    scanElements(nel, source);

    /*int m;
    scanf("%d", &m);*/

    long treemaxsize = (long)pow(2, floor(log2((double)nel))+ 2);
    long *tree = malloc(treemaxsize * sizeof(long));
    if(tree == NULL)
        exit(-1);

    performOps(source, nel,  tree);

    free(tree);
    return 0;
}

void build(long v, long a, long b, long *tree, long *source) {// 1, 0, nel - 1
    if(a == b)
        tree[v] = source[a];
    else{
        long m = (a + b) / 2;
        build(v * 2, a, m, tree, source);
        build(v * 2 + 1, m + 1, b, tree, source);
        tree[v] = MAX(tree[v * 2], tree[v * 2 + 1]); //function of tree
    }
}

long query(long v, long a, long b, long l, long r, long *tree) { // 1, 0, nel - 1, l , r
    if(a > r || b < l)
        return -2147483647; // minus infinity
    else if (l <= a && r >= b){
        return tree[v];
    }
    else{
        long m = (a + b) / 2;
        if(r <= m)
            return query(v * 2, a, m, l, r, tree);
        else if (l > m)
            return query(v * 2 + 1, m + 1, b, l, r, tree);
        else
            return MAX(query(v * 2, a, m, l, r,tree),
                   query(v * 2 + 1, m + 1, b, l, r, tree));
        // спасибо за подсказку!
    }
}

void update(long v, long a, long b, long i, long value, long *tree) {//1, 0, nel - 1, i, value
    if (a == b){
        tree[v] = value;
    }
    else{
        long m = (a + b) / 2;
        if(i <= m)
            update(v * 2, a, m, i, value, tree);
        else{
            update(v * 2 + 1, m + 1, b, i, value, tree);
        }
        tree[v] = MAX(tree[v * 2], tree[v * 2 + 1]);
    }
}

void scanElements(long nel, long *array) {
    for (long i = 0; i < nel; i++){
        scanf("%li", &array[i]);
    }
}

void performOps(long *source, long nel, long *tree) {
    char operation[3];//current operation
    long param1, param2;
    build(1, 0, nel - 1, tree, source);
    while(true){
        scanf("%s %li %li", operation, &param1, &param2);
        if(operation[0] == 'M')
            printf("%li\n", query(1, 0, nel - 1, param1, param2, tree));
        else if(operation[0] == 'U')
            update(1, 0, nel - 1, param1, param2, tree);
        else if(operation[0] == 'E')
            return;
    }
}