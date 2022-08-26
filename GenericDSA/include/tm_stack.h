#ifndef __TM_STACK__H
#define __TM_STACK__H 123
#include <tm_sll.h>
#include<tm_common.h>
typedef struct __$_tm_stack 
{ 
    SinglyLinkedList *singlyLinkedList;//it has singlyLinkedList.start and endpointer
} Stack;
Stack *createStack(bool *success);
void pushOnStack(Stack *stack, void *ptr, bool *success);
void *popFromStack(Stack *stack, bool *success);
int getSizeOfStack(Stack *stack);
void *elementTopOfStack(Stack *stack, bool *success);
bool isStackEmpty(Stack *stack);
void clearStack(Stack *stack);
void destroyStack(Stack *stack);
#endif