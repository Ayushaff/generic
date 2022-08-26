#include <stdlib.h>
#include <tm_sll.h>
#include <stdio.h>
int main()
{
    int i1, i2, i3, i4, i5, i6;
    int *x, y;
    bool succ;
    SinglyLinkedList *list1, *list2;
    list1 = createSLL(&succ);
    list2 = createSLL(&succ);
    i1 = 100;
    i2 = 200;
    i3 = 300;
    i4 = 400;
    i5 = 500;
    i6 = 600;
    addToSLL(list1, (void *)&i1, &succ);
    addToSLL(list1, (void *)&i2, &succ);
    addToSLL(list1, (void *)&i3, &succ);
    addToSLL(list1, (void *)&i4, &succ);
    addToSLL(list1, (void *)&i5, &succ);
    addToSLL(list1, (void *)&i6, &succ);
    appendToSLL(list1, list2, &succ);
    if (succ)
        printf("Appended\n");
    else
        printf("Uanble to append\n");
    for (y = 0; y < getsizeOfSLL(list1); y++)
    {
        x = (int *)getFromSLL(list1, y, &succ);
        printf("%d\n", *x);
    }

    for (y = 0; y < getsizeOfSLL(list2); y++)
    {
        x = (int *)getFromSLL(list2, y, &succ);
        printf("%d\n", *x);
    }

    printf("size of list 1: %d\n", getsizeOfSLL(list1));
    printf("size of list 2: %d\n", getsizeOfSLL(list2));

    //remove no iseu
    x = (void *)removeFromSLL(list1, 3, &succ);
    printf("%d removed From list1\n", *x);
    printf("Contents of list1 after removal\n");
    for ( y = 0; y < getsizeOfSLL(list1); y++)
    {
        x = (int *)getFromSLL(list1, y, &succ);
        printf("%d\n", *x);
    }
    printf("size of list 1: %d\n", getsizeOfSLL(list1));
    printf("size of list 2: %d\n", getsizeOfSLL(list2));

    clearSLL(list1);
    printf("clearing list\n");
    destroySLL(list1);
    printf("Destroying List\n");
    return 0;
}