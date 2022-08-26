#include "tm_avl.h"
#include <stdio.h>
#include <stdlib.h>
int myComparator(void *left, void *right) // predicate
{
    int *leftInt, *rightInt;
    leftInt = (int *)left;
    rightInt = (int *)right;
    printf("\n%d %d\n", *leftInt, *rightInt);
    return (*leftInt - *rightInt);
}
int main()
{
    AVLTreeInOrderIterator iterator;
    AVLTree *tree;
    int success;
    int *x, num, ch;
    char more;
    tree = createAVL(&success, myComparator);
    if (success == false)
    {
        printf("Unable to create tree,Low on memory");
        return 0;
    }
    while (1)
    {
        printf("1.Insert into avl Tree\n");
        printf("2.Traverse(In order)\n");
        printf("3.Remove\n");
        printf("4.search\n");
        printf("5.Exit\n");
        printf("enter your choice\n");
        scanf("%d", &ch);
        fflush(stdin);
        if (ch == 1)
        {
            printf("Enter material to insert in tree\n");
            scanf("%d", &num);
            fflush(stdin);
            x = (int *)malloc(sizeof(int));
            *x = num;
            insertToAVL(tree, (void *)x, &success);
            if (success)
                printf("address of item contains %d ,inserted to avlTree\n", *x);
            else
                printf("%d Unable to insert this in tree\n", *x);
        }
        if (ch == 2)
        {
            printf("InOrder Iteration starts\n");
            iterator = getAVLTreeInOrder(tree, &success);
            if (success)
            {
                while (hasNextInAVLTreeInOrder(&iterator))
                {
                    x = (int *)getNextElementFromAVLTree(&iterator, &success);
                    printf("%d\n", *x);
                }
            }
        }
        if (ch == 3)
        {
            printf("Enter no. to remove\n");
            scanf("%d", &num);
            fflush(stdin);
            x = removeFromAVL(tree, &num, &success);
            if (success)
                printf("%d removed from tree\n", *x);
            else
                printf("%d not found \n", *x);
        }
        if (ch == 4)
        {
            for (;;)
            {
                printf("Enter no. to search\n");
                scanf("%d", &num);
                fflush(stdin);
                x = getFromAVL(tree, &num, &success);
                if (success)
                    printf("%d found\n", *x);
                else
                    printf("%d not found\n", num);
                printf("Search more\n[Y]es[N]O\n");
                more = getchar();
                fflush(stdin);
                if (more == 'y' || more == 'Y')
                    continue;
                else
                    break;
            }
        }
        if (ch == 5)
            break;
    }
    destroyAVL(tree);
    return 0;
}
