#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

void build(long v, long a, long b, long* tree, long* source);
long query(long v, long a, long b, long l, long r, long* tree);
void update(long v, long a, long b, long i, long value, long* tree);
void scanElements(long nel, long* array);
void scanOps(int m, char* operations);
void performOps(long* source, long nel, int m, char* ops);

int main(){
    long nel;
    scanf("%li", &nel);

    long source[nel];
    scanElements(nel, source);

    int m;
    scanf("%d", &m);
    char* operations = calloc(m, 30);
    scanOps(m, operations);

    performOps(source, nel, m, operations);

    free(operations);
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
        return MAX(query(v * 2, a, m, l, r,tree),
                   query(v * 2 + 1, m + 1, b, l, r, tree));
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
        scanf("%lu", &array[i]);
    }
}

void scanOps(int m, char *operations) {
    char* buf = malloc(3);
    fgets(buf, 3, stdin);//removes /r and /n
    free(buf);
    for(int i = 0; i < m; i++){
        fgets(operations + i * 30, 30, stdin);
    }
}

void performOps(long *source, long nel, int m, char *ops) {
    int treemaxsize = (int)pow(2, ceil(log2((double)nel)) + 1);
    long tree[treemaxsize];
    build(1, 0, nel - 1, tree, source);
    for(int i = 0; i < m; i++){
        char operation[30];// current operation
        strcpy(operation, ops + i * 30);
        char* end;
        char* end2;
        long param1 = strtol(operation + 3, &end, 10);
        long param2 = strtol(end, &end2, 10);
        if(operation[0] == 'M')
            printf("%li\n", query(1, 0, nel - 1, param1, param2, tree));
        if(operation[0] == 'U')
            update(1, 0, nel - 1, param1, param2, tree);
    }
}