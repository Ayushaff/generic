#ifndef __TM_SLL__C
#define __TM_SLL__C 123
#include <stdlib.h>
#include <tm_sll.h>
SinglyLinkedList *createSLL(bool *success)
{
    if (success)
        *success = false;
    SinglyLinkedList *SLLlist;
    SLLlist = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
    if (SLLlist == NULL)
        return NULL;
    SLLlist->start = NULL;
    SLLlist->end = NULL;
    SLLlist->size = 0;
    if (success)
        *success = true;
    return SLLlist;
}
void destroySLL(SinglyLinkedList *SLLlist)
{
    SinglyLinkedListNode *node;
    if (SLLlist == NULL)
        return;
    clearSLL(SLLlist);
    free(SLLlist);
}
int getsizeOfSLL(SinglyLinkedList *SLLlist)
{
    if (SLLlist == NULL)
        return 0;
    return SLLlist->size;
}
void clearSLL(SinglyLinkedList *SLLlist)
{
    SinglyLinkedListNode *node;
    if (SLLlist == NULL)
        return;
    node = SLLlist->start;
    while (SLLlist->start != NULL)
    {
        node = SLLlist->start;
        SLLlist->start = SLLlist->start->next;
        free(node);
    }
    SLLlist->end=NULL;
    SLLlist->size = 0;
}
void addToSLL(SinglyLinkedList *SLLlist, void *ptr, bool *success)
{
    SinglyLinkedListNode *node;
    if (success)
        *success = false;
    if (SLLlist == NULL)
        return;
    node = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    if (node == NULL)
        return;
    node->ptr = ptr;
    node->next = NULL;
    if (SLLlist->start == NULL)
    {
        SLLlist->start = node;
        SLLlist->end = node;
    }
    else
    {
        SLLlist->end->next = node;
        SLLlist->end = node;
    }
    SLLlist->size++;
    if (success)
        *success = true;
}
void insertToSLL(SinglyLinkedList *SLLlist, int index, void *ptr, bool *success)
{
    SinglyLinkedListNode *node, *p1, *p2;
    int x;
    if (success)
        *success = false;
    if (SLLlist == NULL)
        return;
    if (index < 0 || index > SLLlist->size)
        return;
    if (index == SLLlist->size)
    {
        ///hence add at end
        addToSLL(SLLlist, ptr, success);
        return;
    }
    //adding wherevr in nodes
    node = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    if (node == NULL)
        return;
    node->ptr = ptr;
    node->next = NULL;
    if (index == 0)
    {
        node->next = SLLlist->start;
        SLLlist->start = node;
        SLLlist->size++;
        if (success)
            *success = true;
        return;
    }
    p1 = SLLlist->start;
    x = 0;
    while (x > index)
    {
        p2 = p1;
        p1 = p1->next;
        x++;
    }
    node->next = p1;
    p2->next = node;
    SLLlist->size++;
    if (success)
        *success = true;
}
void *removeFromSLL(SinglyLinkedList *SLLlist, int index, bool *success)
{
    void *ptr;
    SinglyLinkedListNode *p1, *p2;
    int x;
    if (success)
        *success = false;
    if (SLLlist == NULL)
        return NULL;
    if (index < 0 || index >= SLLlist->size)
        return NULL;
    p1 = SLLlist->start;
    x = 0;
    while (x < index)
    {
        p2 = p1;
        p1 = p1->next;
        x++;
    }
    ptr = p1->ptr;
    if (SLLlist->start == p1 && SLLlist->end == p1)
    {
        SLLlist->start = NULL;
        SLLlist->end = NULL;
    }
    else if (SLLlist->start == p1)
    {
        SLLlist->start = SLLlist->start->next;
    }
    else if (SLLlist->end == p1)
    {
        SLLlist->end = p2;
        SLLlist->end->next = NULL;
    }
    else
    {
        p2->next = p1->next;
    }
    free(p1);
    SLLlist->size--;
    if (success)
        *success = true;
    return ptr;
}
void appendToSLL(SinglyLinkedList *TargetSinglyLinkedlist, SinglyLinkedList *sourceSinglyLinkedList, bool *success)
{
    SinglyLinkedListNode *s, *e, *t, *node;
    bool done;
    if (success)
        *success = false;
    if (TargetSinglyLinkedlist == NULL)
        return;
    if (sourceSinglyLinkedList == NULL || sourceSinglyLinkedList->size == 0)
    {
        if (success)
            *success = true;
        return;
    }
    s = NULL;
    e = NULL;
    done = true;
    t = sourceSinglyLinkedList->start;
    while (t != NULL)
    {
        node = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
        if (node == NULL)
        {
            done = false;
            break;
        }
        node->ptr = t->ptr;
        node->next = NULL;
        if (s == NULL)
        {
            s = node;
            e = node;
        }
        else
        {
            e->next = node;
            e = node;
        }
        t = t->next;
    }
    if (done == false)
    {
        while (s != NULL)
        {
            node = s;
            s = s->next;
            free(node);
        }
        return;
    }
    if (TargetSinglyLinkedlist->start == NULL)
    {
        TargetSinglyLinkedlist->start = s;
        TargetSinglyLinkedlist->end = e;
        TargetSinglyLinkedlist->size = sourceSinglyLinkedList->size;
    }
    else
    {
        TargetSinglyLinkedlist->end->next = s;
        TargetSinglyLinkedlist->end = e;
        TargetSinglyLinkedlist->size += sourceSinglyLinkedList->size;
    }
    if (success)
        *success = true;
}
void *getFromSLL(SinglyLinkedList *SLLlist, int index, bool *success)
{
    SinglyLinkedListNode *node;
    int x;
    if (success)
        *success = false;
    if (SLLlist == NULL)
        return NULL;
    if (index < 0 || index >= SLLlist->size)
        return NULL;
    x = 0;
    node = SLLlist->start;
    while (x < index)
    {
        node = node->next;
        x++;
    }
    if (success)
        *success = true;
    return node->ptr;
}
SinglyLinkedListIterator getSLLIterator(SinglyLinkedList *SLLlist, bool *success)
{
    SinglyLinkedListIterator SLLiterator;
    SLLiterator.node = NULL;
    if (success)
        *success = false;
    if (SLLlist == NULL)
        return SLLiterator;
    if (SLLlist->start == NULL)
    {
        if (success)
            *success = true;
        return SLLiterator;
    }
    if (success)
        *success = true;
    SLLiterator.node = SLLlist->start;
    return SLLiterator;
}
bool hasNextInSLLIterator(SinglyLinkedListIterator *singlyLinkedListIterator)
{
    if (singlyLinkedListIterator == NULL)
        return false;
    if (singlyLinkedListIterator->node == NULL)
        return false;
    return true;
}
void *getNextElementFromSLL(SinglyLinkedListIterator *singlyLinkedListIterator, bool *success)
{
    void *ptr = NULL;
    if (success)
        *success = false;
    if (singlyLinkedListIterator == NULL || singlyLinkedListIterator->node == NULL)
        return ptr;
    ptr = singlyLinkedListIterator->node->ptr;
    singlyLinkedListIterator->node = singlyLinkedListIterator->node->next;
    if(success) *success=true;
    return ptr;
}
#endif