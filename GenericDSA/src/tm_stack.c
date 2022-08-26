#ifndef __TM_STACK_C
#define __TM_STACK_C 123
#include <stdlib.h>
#include <tm_stack.h>
#include <tm_sll.h>
Stack *createStack(bool *success)
{
    Stack *stack;
    SinglyLinkedList *SSLlist;
    SSLlist = createSLL(success);
    if (*success == false)
        return NULL;
    stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
    {
        destroySLL(SSLlist);
        if (success)
            *success = false;
        return NULL;
    }
    stack->singlyLinkedList = SSLlist;
    if (success)
        *success = true;
    return stack;
}
void pushOnStack(Stack *stack, void *ptr, bool *success)
{
    if (success)
        *success = false;
    if (stack == NULL || stack->singlyLinkedList == NULL)
        return;
    insertToSLL(stack->singlyLinkedList, 0, ptr, success);
}
void *popFromStack(Stack *stack, bool *success)
{
    void *ptr;
    if (success)
        *success = false;
    if (isStackEmpty(stack))    
        return NULL;
    ptr = removeFromSLL(stack->singlyLinkedList, 0, success);
    if (success)
        *success = true;
    return ptr;
}
int getSizeOfStack(Stack *stack)
{
    if (stack == NULL || stack->singlyLinkedList == NULL)
        return 0;
    return getsizeOfSLL(stack->singlyLinkedList);
}
void *elementTopOfStack(Stack *stack, bool *success)
{
    void *ptr;
    if (success)
        *success = false;
    if (isStackEmpty(stack))
        return NULL;
    ptr = getFromSLL(stack->singlyLinkedList, 0, success);
    if (success)
        *success = true;
    return ptr;
}
bool isStackEmpty(Stack *stack)
{
    if (stack == NULL)
        return true;
    if (stack->singlyLinkedList == NULL)
        return true;
    if (getsizeOfSLL(stack->singlyLinkedList) == 0)
        return true;
    return false;
}
void clearStack(Stack *stack)
{
    if(stack==NULL)return;
    if(stack->singlyLinkedList==NULL)return;
    clearSLL(stack->singlyLinkedList);
}
void destroyStack(Stack *stack)
{
    if(stack==NULL)return;
    if(stack->singlyLinkedList==NULL)return;
    destroySLL(stack->singlyLinkedList);
    free(stack);
}
#endif