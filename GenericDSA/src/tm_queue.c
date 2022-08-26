#ifndef __TM_QUEUE_C
#define __TM_QUEUE_C 123
#include <stdlib.h>
#include <tm_queue.h>
#include <tm_sll.h>
Queue *createQueue(bool *success)
{
    Queue *queue;
    SinglyLinkedList *SSLlist;
    SSLlist = createSLL(success);
    if (*success == false)
        return NULL;
    queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        destroySLL(SSLlist);
        if (success)
            *success = false;
        return NULL;
    }
    queue->singlyLinkedList = SSLlist;
    if (success)
        *success = true;
    return queue;
}
void addOnQueue(Queue *queue, void *ptr, bool *success)
{
    if (success)
        *success = false;
    if (queue == NULL || queue->singlyLinkedList == NULL)
        return;
    insertToSLL(queue->singlyLinkedList, 0, ptr, success);
}
void *removeFromQueue(Queue *queue, bool *success)
{
    void *ptr;
    if (success)
        *success = false;
    if (isQueueEmpty(queue))
        return NULL;
    ptr = removeFromSLL(queue->singlyLinkedList, 0, success);
    if (success)
        *success = true;
    return ptr;
}
int getSizeOfQueue(Queue *queue)
{
    if (queue == NULL || queue->singlyLinkedList == NULL)
        return 0;
    return getsizeOfSLL(queue->singlyLinkedList);
}
void *elementFrontOfQueue(Queue *queue, bool *success)
{
    void *ptr;
    if (success)
        *success = false;
    if (isQueueEmpty(queue))
        return NULL;
    ptr = getFromSLL(queue->singlyLinkedList, 0, success);
    if (success)
        *success = true;
    return ptr;
}
bool isQueueEmpty(Queue *queue)
{
    if (queue == NULL)
        return true;
    if (queue->singlyLinkedList == NULL)
        return true;
    if (getsizeOfSLL(queue->singlyLinkedList) == 0)
        return true;
    return false;
}
void clearQueue(Queue *queue)
{
    if(queue==NULL)return;
    if(queue->singlyLinkedList==NULL)return;
    clearSLL(queue->singlyLinkedList);
}
void destroyQueue(Queue *queue)
{
    if(queue==NULL)return;
    if(queue->singlyLinkedList==NULL)return;
    destroySLL(queue->singlyLinkedList);
    free(queue);
}
#endif