#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct BSTNode
{
    int key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// 在二叉排序树中查找值为key的结点
BSTNode *BST_Search(BSTree T, int key)
{
    while (T != NULL && key != T->key)
    { // 如果树是空的或者根结点的数据不等于key,则继续循环
        if (key < T->key)
            T = T->lchild; // 小于,则在左子树上寻找
        else
            T = T->rchild; // 大于,则在右子树上寻找
    }
    return T;
}

// 在二叉排序树插入关键字为k的新结点（递归实现）
int BST_Insert(BSTree &T, int k)
{
    if (T == NULL)
    { // 原树为空,新插入的结点为根结点
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1; // 返回1,插入成功
    }
    else if (k == T->key) // 说明树中存在相同的结点,插入失败
        return 0;
    else if (k < T->key) // 插入到T的左子树
        return BST_Insert(T->lchild, k);
    else // 插入到T的右子树
        return BST_Insert(T->rchild, k);
}

// 在二叉排序树插入关键字为k的新结点（递归实现）
int BST_Insert(BSTree &T, int k)
{
    if (T == NULL)
    { // 原树为空,新插入的结点为根结点
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1; // 返回1,插入成功
    }
    else if (k == T->key) // 说明树中存在相同的结点,插入失败
        return 0;
    else if (k < T->key) // 插入到T的左子树
        return BST_Insert(T->lchild, k);
    else // 插入到T的右子树
        return BST_Insert(T->rchild, k);
}

// 按照str[]中的关键字序列建立二叉排序树
void Creat_BST(BSTree &T, int str[], int n)
{
    T = NULL;
    int i = 0;
    while (i < n)
    {
        BST_Insert(T, str[i]);
        i++;
    }
}
