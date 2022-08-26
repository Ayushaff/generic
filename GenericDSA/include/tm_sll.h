#ifndef __TM_SLL__H
#define __TM_SLL__H 1 
#include<tm_common.h>
typedef struct __$_tm_sll_node
{
    void *ptr;
    struct __$_tm_sll_node *next;
} SinglyLinkedListNode;

typedef struct __$_tm_sll_list
{
    struct __$_tm_sll_node *start;
    struct __$_tm_sll_node *end;
    int size;
} SinglyLinkedList;

typedef struct __$_tm_sll_Iterator
{
    SinglyLinkedListNode *node;
} SinglyLinkedListIterator;

SinglyLinkedList *createSLL(bool *success);
void destroySLL(SinglyLinkedList *list);
int getsizeOfSLL(SinglyLinkedList *list);
void addToSLL(SinglyLinkedList *list, void *ptr, bool *success);
void insertToSLL(SinglyLinkedList *list, int index, void *ptr, bool *success);
void *removeFromSLL(SinglyLinkedList *list, int index, bool *success);
void clearSLL(SinglyLinkedList *list);
void appendToSLL(SinglyLinkedList *TargetSinglyLinkedlist, SinglyLinkedList *sourceSinglyLinkedList, bool *success);
void *getFromSLL(SinglyLinkedList *list, int index, bool *success);

SinglyLinkedListIterator getSLLIterator(SinglyLinkedList *list,bool *success);
bool hasNextInSLLIterator(SinglyLinkedListIterator *singlyLinkedListIterator);
void *getNextElementFromSLL(SinglyLinkedListIterator *singlyLinekedListIterator,bool *success);
#endif
