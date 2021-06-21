#ifndef __STACK__H__
#define __STACK__H__

typedef struct StackElement
{
    int value;
    struct StackElement *next;
} StackElement, *Stack;



Stack new_stack(void);
int is_empty(Stack st);
Stack push_stack(Stack st, int x);
Stack clear_stack(Stack st);
void display(Stack sta, int i);
Stack depiler(Stack sta);
int sommet(Stack sta);
int longueur(Stack sta);



#endif