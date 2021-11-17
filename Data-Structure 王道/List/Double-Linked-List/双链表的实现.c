//
// Created by WENZE XU on 2021/11/13.
//

//
// Created by ricol on 2021/10/30.
//

#ifndef DOUBLE_LINKED_LIST_FUC_H
#define DOUBLE_LINKED_LIST_FUC_H
#include <stdlib.h>
#include "struct.h"

// 初始化双链表
bool InitDLinkList(DLinkList *P)
{
    *P = (DNode *)malloc(sizeof(DNode)); // 分配头结点
    if ((*P) == NULL)
    {
        return false;
    }
    (*P)->prior = NULL; // 头结点的prior永远指向NULL
    (*P)->next = NULL;
    return true;
}

// 判断双链表是否为空
bool Empty(DLinkList L)
{
    if (L->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 在P结点之后插入S结点
bool InsertNextNode(DNode *P)
{
    DNode *S = (DNode *)malloc(sizeof(DNode));
    S->next = P->next;
    if (P->next != NULL) // 在双链表的尾部插入的特殊情况
        P->next->prior = S;
    P->next = S;
    S->prior = P;
}

// 删除P结点的后继结点Q
bool DeleteNextNode(DNode *P)
{
    DNode *Q = P->next;
    if (P == NULL)
        return false;
    if (Q == NULL)
        return false;
    P->next = Q->next;
    if (Q->next != NULL)
        Q->next->prior = P;
    free(Q);
    return true;
}

// 双链表的删除
void DestoryList(DLinkList *P)
{
    while ((*P)->next != NULL)
        DeleteNextNode(*P);
    free(*P);
    *P = NULL; // 需要修改头指针的指向为NULL,所以需要传入二级指针
}

// 双链表的遍历
void PrintList(DLinkList L)
{
    L = L->next; // 跳过头结点
    while (L != NULL)
    {
        printf("%d", L->data);
        L = L->next;
    }
}

#endif //DOUBLE_LINKED_LIST_FUC_H