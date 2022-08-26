#ifndef __TM_AVL__C
#define __TM_AVL__C
#include <stdlib.h>
#include <stdio.h>
#include <tm_stack.h>
#include <tm_avl.h>
AVLTree *createAVL(bool *success, int (*predicate)(void *, void *))
{
    if (success)
        *success = false;
    AVLTree *avlTree;
    avlTree = (AVLTree *)malloc(sizeof(AVLTree));
    if (avlTree == NULL || predicate == NULL)
        return NULL;
    avlTree->start = NULL;
    avlTree->size = 0;
    avlTree->predicate = predicate;
    if (success)
        *success = true;
    return avlTree;
}
void destroyAVL(AVLTree *avltree)
{
    if (avltree == NULL)
        return;
    clearAVL(avltree);
    free(avltree);
}
int getsizeOfAVL(AVLTree *avltree)
{
    if (avltree == NULL)
        return 0;
    return avltree->size;
}
void clearAVL(AVLTree *avltree)
{
}
void insertToAVL(AVLTree *avltree, void *ptr, bool *success)
{
    AVLNode *j, *t;
    int weight;
    if (success)
        *success = false;
    if (avltree == NULL)
        return;
    if (avltree->start == NULL)
    {
        t = (AVLNode *)malloc(sizeof(AVLNode));
        if (t == NULL)
            return;
        t->ptr = ptr;
        t->left = NULL;
        t->right = NULL;
        avltree->start = t;
        avltree->size++;
        if (success)
            *success = true;
        return;
    }
    j = avltree->start;
    while (1)
    {
        weight = avltree->predicate(ptr, j->ptr);
        if (weight == 0)
            return;
        if (weight < 0)
        {
            if (j->left == NULL)
            {
                t = (AVLNode *)malloc(sizeof(AVLNode));
                if (t == NULL)
                    return;
                t->ptr = ptr;
                t->left = NULL;
                t->right = NULL;
                j->left = t;
                break;
            }
            else
            {
                j = j->left;
            }
        }
        else
        {
            if (j->right == NULL)
            {
                t = (AVLNode *)malloc(sizeof(AVLNode));
                if (t == NULL)
                    return;
                t->ptr = ptr;
                t->left = NULL;
                t->right = NULL;
                j->right = t;
                break;
            }
            else
            {
                j = j->right;
            }
        }
    }
    if (success)
        *success = true;
    avltree->size++;
}
void *removeFromAVL(AVLTree *avltree, void *ptr, bool *success)
{
    AVLNode *t, *j, *e, *f;
    AVLNode **p2p;
    void *foundPtr;
    int weight;
    if (success)
        *success = false;
    if (avltree == NULL || avltree->start == NULL)
        return NULL;
    t = avltree->start;
    while (t != NULL)
    {
        weight = avltree->predicate(ptr, t->ptr);
        if (weight == 0)
            break;
        j = t;
        if (weight < 0)
            t = t->left;
        else
            t = t->right;
    }
    if (t == NULL)
        return NULL;
    foundPtr = t->ptr;
    if (t == avltree->start)
        p2p = &(avltree->start);
    else if (j->left == t)
        p2p = &(j->left);
    else
        p2p = &(j->right);
    if (t->left == t->right) // only if both are NULL;
    {
        *p2p = NULL;
    }
    else
    {
        if (t->right != NULL)
        {
            for (e = t->right; e->left != NULL; e = e->left)
                f = e;
            if (e == t->right)
            {
                e->left = t->left;
            }
            else
            {
                f->left = e->right;
                e->left = t->left;
                e->right = t->right;
            }
            *p2p = e;
        } // successor parts ends here
        else
        {
            for (e = t->left; e->right != NULL; e = e->right)
                f = e;
            if (e == t->left)
            {
                e->right = t->right;
            }
            else
            {
                f->right = e->left;
                e->left = t->left;
                e->right = t->right;
            }
            *p2p = e;
        }
    }
    free(t);
    avltree->size--;
    if (success)
        *success = true;
    return foundPtr;
}
// search
void *getFromAVL(AVLTree *avltree, void *ptr, bool *success)
{
    int weight;
    AVLNode *t;
    if (success)
        *success = false;
    if (avltree == NULL || avltree->start == NULL)
        return NULL;
    t = avltree->start;
    while (t != NULL)
    {
        weight = avltree->predicate(ptr, t->ptr);
        if (weight == 0)
        {
            if (success)
                *success = true;
            return t->ptr;
        }
        if (weight < 0)
            t = t->left;
        else
            t = t->right;
    }
    return NULL;
}
AVLTreeInOrderIterator getAVLTreeInOrder(AVLTree *avlTree, bool *success)
{
    int succ;
    AVLNode *t;
    AVLTreeInOrderIterator avlInorderIterator;
    avlInorderIterator.node = NULL;
    avlInorderIterator.stack = NULL;
    if (success)
        *success = false;
    if (avlTree == NULL)
        return avlInorderIterator;
    if (avlTree->start == NULL)
    {
        if (success)
            *success = true;
        printf("Tree all empty\n\n");
        return avlInorderIterator;
    }
    avlInorderIterator.stack = createStack(&succ);
    if (succ == false)
        return avlInorderIterator; // par vo start toh aa he chuka hoga
    t = avlTree->start;
    while (t != NULL)
    {
        pushOnStack(avlInorderIterator.stack, (void *)t, &succ);
        if (succ == false)
        {
            destroyStack(avlInorderIterator.stack);
            avlInorderIterator.stack = NULL;
            return avlInorderIterator;
        }
        t = t->left; // wen t==NULL
    }
    avlInorderIterator.node = (AVLNode *)popFromStack(avlInorderIterator.stack, &succ);
    if (success)
        *success = true;
    return avlInorderIterator;
}
bool hasNextInAVLTreeInOrder(AVLTreeInOrderIterator *avlTreeInOrder)
{
    if (avlTreeInOrder == NULL || avlTreeInOrder->node == NULL)
        return false;
    return true;
    // return avlTreeInOrder!=NULL;
}
void *getNextElementFromAVLTree(AVLTreeInOrderIterator *avlTreeInOrder, bool *success)
{
    AVLNode *j, *t;
    int succ;
    if (success)
        *success = false;
    if (avlTreeInOrder == NULL)
        return NULL;
    if (avlTreeInOrder->node == NULL)
        return NULL;
    j = avlTreeInOrder->node;
    t = j->right;
    while (t != NULL)
    {
        pushOnStack(avlTreeInOrder->stack, (void *)t, &succ);
        if (succ == false)
        {
            destroyStack(avlTreeInOrder->stack);
            avlTreeInOrder->stack = NULL;
            avlTreeInOrder->node = NULL;
            if (success)
                *success = true;
            return j->ptr;
        }
        t = t->left;
    }
    if (isStackEmpty(avlTreeInOrder->stack))
    {
        destroyStack(avlTreeInOrder->stack);
        avlTreeInOrder->node = NULL;
        avlTreeInOrder->stack = NULL;
    }
    else
    {
        avlTreeInOrder->node = (AVLNode *)popFromStack(avlTreeInOrder->stack, &succ);
    }
    if (success)
        *success = true;
    return j->ptr;
}
int getHeightOfTree(AVLNode *root)
{
    int leftTreeHeight, rightTreeHeight;
    if (root == NULL)
        return 0;
    leftTreeHeight = getHeightOfTree(root->left);
    rightTreeHeight = getHeightOfTree(root->right);
    return (leftTreeHeight > rightTreeHeight) ? leftTreeHeight + 1 : rightTreeHeight + 1;
}
void balanceAVLTree(Stack *stack){

}
#endif