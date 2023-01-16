#include <stdlib.h>
#include <stdio.h>

void swap(long* array, long i, long j){
    long swapbuf = array[i];
    array[i] = array[j];
    array[j] = swapbuf;
}

void selectsort(long* array, long nel){
    long j = nel - 1;
    while(j > 0){
        long k = j;
        long i = j - 1;
        while(i >= 0){
            if(array[k] < array[i]){
                k = i;
            }
            i--;
        }
        swap(array, j, k);
        j--;
    }
}

long partition(long* array, long low, long high){
    long i = low;
    long j = low;
    while(j < high){
        if(array[j] < array[high]){
            swap(array, i, j);
            i++;
        }
        j++;
    }
    swap(array, i, high);
    return i;
}

void quicksortrec(long* array, long low, long high, long m){
    if(low < high){
        long q = partition(array, low, high);
        if(q - low < m){
            selectsort(array, )
        }
        quicksortrec(array, low, q - 1, m);
        quicksortrec(array, q + 1, high, m);
    }
}

void quicksort(long* array, long nel, long m){
    quicksortrec(array, 0, nel - 1, m);
}

void scanarray(long* array, long nel){
    for(long i = 0; i < nel; i++){
        scanf("%li", &array[i]);
    }
}

int main(){
    long nel, m;
    scanf("%li", &nel);
    scanf("%li", &m);
    long* array = malloc(nel * sizeof(long));

    scanarray(array, nel);
    quicksort(array, nel, m);


    free(array);
    return 0;
}