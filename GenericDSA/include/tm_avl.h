#ifndef __TM_AVL__H
#define __TM_AVL__H
#include <tm_sll.h>
#include <tm_stack.h>
typedef struct __$_tm_avl_node
{
    void *ptr;
    struct __$_tm_avl_node *left;
    struct __$_tm_avl_node *right;
} AVLNode;

typedef struct __$_tm_avl_tree
{
    struct __$_tm_avl_node *start;
    int (*predicate)(void *, void *);
    int size;
} AVLTree;

typedef struct __$_tm_avl_in_order_Iterator
{
    AVLNode *node;
    Stack *stack;
} AVLTreeInOrderIterator;

AVLTree *createAVL(bool *success, int (*predicate)(void *, void *));
void destroyAVL(AVLTree *avltree);
int getsizeOfAVL(AVLTree *avltree);
void clearAVL(AVLTree *avltree);

void insertToAVL(AVLTree *avltree, void *ptr, bool *success);
void *removeFromAVL(AVLTree *avltree, void *ptr, bool *success);
void *getFromAVL(AVLTree *avltree, void *ptr, bool *success);//search

AVLTreeInOrderIterator getAVLTreeInOrder(AVLTree *avlTree, bool *success);
bool hasNextInAVLTreeInOrder(AVLTreeInOrderIterator *avlTreeInOrder);
void *getNextElementFromAVLTree(AVLTreeInOrderIterator *avlTreeInOrder, bool *success);

int getHeightOfTree(AVLNode *root);
void balanceAVLTree(Stack *stack);
#endif
