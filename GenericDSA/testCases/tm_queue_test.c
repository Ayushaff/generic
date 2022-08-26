#include <tm_queue.h>
#include <stdio.h>
int main()
{
    int *x;
    bool succ;
    int x1, x2, x3, x4;
    x1 = 10;
    x2 = 20;
    x3 = 30;
    x4 = 40;
    Queue *queue;
    queue = createQueue(&succ);
    if (queue == false)
    {
        printf("Unable to create queue\n");
        return 0;
    }
    addOnQueue(queue, &x1, &succ);
    if (succ)
        printf("%d added on queue\n", x1);
    else
        printf("Unable to add %d on queue", x1);

    addOnQueue(queue, &x2, &succ);
    if (succ)
        printf("%d added on queue\n", x2);
    else
        printf("Unable to add %d on queue", x2);

    addOnQueue(queue, &x3, &succ);
    if (succ)
        printf("%d added on queue\n", x3);
    else
        printf("Unable to add %d on queue", x3);

    addOnQueue(queue, &x4, &succ);
    if (succ)
        printf("%d added on queue\n", x4);
    else
        printf("Unable to add %d on queue", x4);
    printf("size of queue %d\n", getSizeOfQueue(queue));

    if (isQueueEmpty(queue))
        printf("queue is empty\n");
    else
        printf("queue aint empty\n");

    x = (int *)elementFrontOfQueue(queue, &succ);
    printf("At front queue %d \n", *x);

    printf("Poping from queue\n");
    while (!isQueueEmpty(queue))
    {
        x = (int *)removeFromQueue(queue, &succ);
        printf("%d removed from queue\n", *x);
    }
    destroyQueue(queue);
    return 0;
}