#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include <stdbool.h>


int main(void){

    Stack sta = new_stack();
    int i = 1;

    sta = push_stack(sta, 14);
    sta = push_stack(sta, 47);

    int length = longueur(sta);
    printf("Hauteur de la pile -> %d \n", length);

    return 0;
}