//
// Created by WENZE XU on 2021/11/13.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode, *LiStack;

void InitLNode(LiStack *DP)
{
    *DP = NULL;
}

bool StackEmpty(LiStack P)
{
    if (P == NULL)
        return true;
    else
        return false;
}

void Push(LiStack *DP, int num)
{
    LinkNode *S = (LinkNode *)malloc(sizeof(LinkNode));
    if (StackEmpty(*DP) == true)
    {
        (*DP) = S;
        S->data = num;
        S->next = NULL;
    }
    else
    {
        S->next = (*DP);
        (*DP) = S;
        S->data = num;
    }
}

void Pop(LiStack *DP, int *P_num)
{
    if (StackEmpty(*DP) == true)
    {
        printf("空栈\n");
    }
    else
    {
        LinkNode *Q = (*DP);
        (*P_num) = Q->data;
        (*DP) = Q->next;
        free(Q);
    }
}

void GetTop(LiStack P)
{
    if (StackEmpty(P) == true)
    {
        printf("空栈,无栈顶\n");
    }
    else
    {
        printf("栈顶的值为:%d\n", P->data);
    }
}

int main()
{
    int num;
    printf("请输入Num的值:");
    scanf("%d", &num);
    LiStack P; // 初始化一个不带头结点的链栈的头指针
    InitLNode(&P);
    Push(&P, num);
    GetTop(P);
    Pop(&P, &num);
    GetTop(P);
    return 0;
}