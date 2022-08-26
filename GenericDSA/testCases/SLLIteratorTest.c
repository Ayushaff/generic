#include <stdlib.h>
#include <tm_sll.h>
#include <stdio.h>
int main()
{
    int i1, i2;
    int *x;
    bool succ;
    SinglyLinkedList *list1;
    SinglyLinkedListIterator iter;
    list1 = createSLL(&succ);
    if (succ == false)
    {
        printf("Unable to create list\n");
        return 0;
    }
    printf("List created\n");
    i1 = 100;
    i2 = 200;
    addToSLL(list1, (void *)&i1, &succ);
    addToSLL(list1, (void *)&i2, &succ);
    iter = getSLLIterator(list1, &succ);
    if (succ)
    {
        while (hasNextInSLLIterator(&iter))
        {
            x=(int *)getNextElementFromSLL(&iter,&succ);
            printf("%d\n",*x);
        }
    }
    //prblm in remov
    /*
    x = (void *)removeFromSLL(list1, 3, &succ);
    printf("%d removed From list1\n", *x);
    printf("Contents of list1 after removal\n");
    for ( y = 0; y < getsizeOfSLL(list1); y++)
    {
        x = (int *)getFromSLL(list1, y, &succ);
        printf("%d\n", *x);
    }*/
    printf("clearing list\n");
    clearSLL(list1);
    printf("Destroying List\n");
    destroySLL(list1);
    return 0;
}