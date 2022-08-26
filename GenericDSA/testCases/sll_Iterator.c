#include <stdlib.h>
#include <tm_sll.h>
#include <stdio.h>
int main()
{
    int i1, i2, i3, i4, i5, i6;
    int *x, y;
    bool succ;
    SinglyLinkedList *list1, *list2;
    SinglyLinkedListIterator iter;
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
    iter = getSLLIterator(list1, &succ);
    if (succ)
    {
        while (hasNextInSLLIterator(&iter))
        {
            int *x = (int *)getNextElementFromSLL(&iter, &succ);
            printf("%d\n", *x);
        }
    }
    destroySLL(list1);
    return 0;
}