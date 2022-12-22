#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

struct Elem {
    struct Elem *next;
    char *word;
};

void checkMem(int numOfPtrs, ...);
int scanWords(struct Elem* list);
struct Elem *bsort(struct Elem *list);
void printList(struct Elem* head);

int main(){
    struct Elem* list = malloc(510 * sizeof(struct Elem));
    struct Elem* head;
    checkMem(1, list);
    scanWords(list);
    head = bsort(list);
    printList(head);

    free(list);
    return 0;
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
int scanWords(struct Elem *list) {
    int wordCounter = 0, currentChar = 0;
    char* string = malloc(1002 * sizeof(char));
    list[0].next = NULL;
    checkMem(1, string);


    if(fgets(string, 1002, stdin) == NULL)
        exit(0);

    for(; string[currentChar] == ' '; currentChar++); //removes spaces in the beginning
    while(string[currentChar] > 31){
        if(string[currentChar] == ' '){ //removes spaces between words
            currentChar++;
            continue;
        } else {
            int wordLen = 0;
            for(;string[currentChar + wordLen] > 32; wordLen++); //calculates the length of the current word
            char* word = malloc((wordLen + 1) * sizeof(char));
            checkMem(1, word);
            for(int k = 0; k < wordLen; k++){
                word[k] = string[currentChar];
                currentChar++;
            }
            word[wordLen] = '\0';
            list[wordCounter].word = word;
            list[wordCounter].next = &list[wordCounter + 1];
            wordCounter++;
        }
    }
    list[wordCounter - 1].next = NULL;
    free(string);
    return wordCounter;
}
struct Elem *bsort(struct Elem *list) {
    bool isSwapped;
    struct Elem* head = list;
    struct Elem* toSwap;
    struct Elem* sorted = NULL;
    if(list == NULL)
        exit(0);

    do
    {
        isSwapped = false;
        toSwap = head;
        while (toSwap->next != sorted){
            int sizeA = (int) strlen(toSwap->word);
            int sizeB = (int) strlen(toSwap->next->word);
            if(sizeA - sizeB > 0){
                char *tmpWord = toSwap->word;
                toSwap->word = toSwap->next->word;
                toSwap->next->word = tmpWord;
                isSwapped = true;
            }
            toSwap = toSwap->next;
        }
        sorted = toSwap;
    } while (isSwapped);
    return head;
}
void printList(struct Elem *head) {
    struct Elem* current = head;
    while(current != NULL){
        printf("%s ", current->word);
        free(current->word);
        current = current->next;
    }
}