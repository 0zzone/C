#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include <stdbool.h>


Stack new_stack(void){
    return NULL;
}

int is_empty(Stack st){
    if(st == NULL)
        return 1;
    return 0;
}

Stack push_stack(Stack st, int x){
    StackElement *element;

    element = malloc(sizeof(*element));

    if(element == NULL){
        fprintf(stderr, "Problème allocation mémoire");
        exit(EXIT_FAILURE);
    }

    element->value = x;
    element->next = st;

    return element;
}


Stack clear_stack(Stack st){
    StackElement *element;
    if(is_empty(st) == 1)
        return new_stack();
    
    element = st->next;
    free(st);
    
    return clear_stack(element);
}

void display(Stack st, int i){
    if(is_empty(st) == 1){
        return;
    }
    while(!is_empty(st)){
        printf("%d -> %d \n", i, st->value);
        st = st->next;
        i++;
        return display(st, i);
    }
}


Stack depiler(Stack st){

    StackElement *element;

    if(is_empty(st) == 1){
        printf("La pile est vide, rien à dépiler ... \n");
        return NULL;
    }

    element = st->next;
    free(st);

    return element;
}

int sommet(Stack st){
    if(is_empty(st)){
        printf("Rien à renvoyer");
        return 0;
    }
    return st->value;
}


int longueur(Stack st){
    int l = 0;
    while(!is_empty(st)){
        l++;
        st = st->next;
    }
    return l;
}