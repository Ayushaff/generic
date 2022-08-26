#include <tm_stack.h>
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
    Stack *stack;
    stack = createStack(&succ);
    if (stack == false)
    {
        printf("Unable to create stack\n");
        return 0;
    }
    pushOnStack(stack, &x1, &succ);
    if (succ)
        printf("%d pushed on stack\n", x1);
    else
        printf("Unable to push %d on stack", x1);

    pushOnStack(stack, &x2, &succ);
    if (succ)
        printf("%d pushed on stack\n", x2);
    else
        printf("Unable to push %d on stack", x2);

    pushOnStack(stack, &x3, &succ);
    if (succ)
        printf("%d pushed on stack\n", x3);
    else
        printf("Unable to push %d on stack", x3);

    pushOnStack(stack, &x4, &succ);
    if (succ)
        printf("%d pushed on stack\n", x4);
    else
        printf("Unable to push %d on stack", x4);
    printf("size of stack %d\n", getSizeOfStack(stack));

    if (isStackEmpty(stack))
        printf("stack is empty\n");
    else
        printf("stack aint empty\n");

    x = (int *)elementTopOfStack(stack, &succ);
    printf("At top stack %d \n", *x);

    printf("Poping from stack\n");
    while (!isStackEmpty(stack))
    {
        x = (int *)popFromStack(stack, &succ);
        printf("%d popped from stack\n", *x);
    }
    destroyStack(stack);
    return 0;
}