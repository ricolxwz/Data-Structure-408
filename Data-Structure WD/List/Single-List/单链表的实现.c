//
// Created by WENZE XU on 2021/11/13.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 定义单链表的节点
typedef struct LNode
{
    int data;
    struct Lnode *next;
} LNode, *LinkList;

// 初始化一个空的头结点
bool InitList(LinkList *P)
{
    *P = (LNode *)malloc(sizeof(LNode));
    if ((*P) == NULL)
    {
        return false;
    }
    (*P)->next = NULL;
    return true;
}

// 结点的数量统计
int CountNode(LinkList P)
{
    int count = 0;
    while (P->next != NULL)
    {
        count++;
        P = P->next;
    }
    return count;
}

// 输入检测
void TestImport(int *i, int *num, int count)
{
    while (1)
    {
        printf("请输入需要插入的结点的位置和值:");
        scanf("%d %d", i, num);
        if (*i < 1 || (*i > count + 1 && *i != 9999))
        {
            printf("输入错误请重新输入!\n");
        }
        else
        {
            break;
        }
    }
}

// 扫描前驱结点的位置
LNode *ScanPriorNode(LNode *P, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    int j;
    for (j = 0; j < i - 1 && P != NULL; j++)
    {
        P = P->next;
    }
    return P;
}

// 按位查找
LNode *GetElem(LNode *P, int i)
{
    if (i < 0)
    {
        return NULL;
    }
    int j;
    for (j = 0; j < i && P != NULL; j++)
    {
        P = P->next;
    }
    return P;
}

// 按值查找
LNode *LocateElem(LinkList L, int num)
{
    LNode *P = L->next;
    while (P != NULL && P->data != num)
    {
        P = P->next;
    }
    return P;
}

// 指定结点的后插操作
bool InsertNextNode(LNode *P, int num)
{
    if (P == NULL)
    {
        return false;
    }
    LNode *S = (LNode *)malloc(sizeof(LNode));
    if (S == NULL)
    {
        return false;
    }
    S->data = num;
    S->next = P->next;
    P->next = S;
    return true;
}

// 指定结点的前插操作
bool InsertPriorNode(LNode *P, int num)
{
    if (P == NULL)
    {
        return false;
    }
    LNode *S = (LNode *)malloc(sizeof(LNode));
    if (S == NULL)
    {
        return false;
    }
    // 一下操作偷天换日,牛逼
    S->data = P->data;
    P->data = num;
    S->next = P->next;
    P->next = S;
    return true;
}

// 删除结点
bool ListDelete(LinkList P, int i, int *num)
{
    if (i < 1)
    {
        return false;
    }
    LNode *move;
    move = ScanPriorNode(P, i);
    if (move == NULL)
    {
        return false;
    }
    if (move->next == NULL)
    {
        return false;
    }
    LNode *q = move->next;
    num = q->data;
    move->next = q->next;
    free(q);
    return true;
}

// 删除指定结点 该段代码有bug最后的结点不符合操作
bool DeleteNode(LNode *P)
{
    if (P == NULL)
    {
        return false;
    }
    LNode *q = P->next;
    LNode *move;
    move = P->next;
    P->data = move->data;
    P->next = q->next;
    free(q);
    return true;
}

// 运用头插法向单链表中添加结点
LinkList HeadInsert(LinkList *P)
{
    int num;
    printf("请输入需要插入的数据:");
    scanf("%d", &num);
    while (num != 9999)
    {
        LNode *S = (LNode *)malloc(sizeof(LNode));
        S->data = num;
        S->next = (*P)->next;
        (*P)->next = S;
        printf("请输入需要插入的数据:");
        scanf("%d", &num);
    }
    return (*P);
}

// 运用尾插法建立单链表
LinkList List_TailInsert(LinkList *P)
{
    int num;
    // 先标记尾结点
    LNode *R, *move, *S;
    R = (*P);
    move = (*P)->next;
    while (move != NULL)
    {
        R = move;
        move = move->next;
    }
    printf("请输入需要插入的数据:");
    scanf("%d", &num);
    while (num != 9999)
    {
        S = (LNode *)malloc(sizeof(LNode));
        S->next = NULL;
        R->next = S;
        R = S;
        S->data = num;
        printf("请输入需要插入的数据:");
        scanf("%d", &num);
    }
    return (*P);
}

// 任意位置插入结点
LinkList RandomInsert(LinkList *P)
{
    LNode *move, *S;
    int j;
    int i;
    int num;
    int count;
    count = CountNode(*P);
    TestImport(&i, &num, count);
    while (i != 9999)
    {
        move = ScanPriorNode(*P, i);
        S = (LNode *)malloc(sizeof(LNode));
        InsertNextNode(move, num);
        count++;
        TestImport(&i, &num, count);
    }
    return (*P);
}

// 遍历单链表
void PrintList(LinkList *P)
{
    LNode *move;
    move = (*P)->next; // 跳过头结点
    while (move != NULL)
    {
        printf("%d\n", move->data);
        move = move->next;
    }
}

int main()
{
    // 初始化一个指向链表的指针,还没有创建任何的结点
    LinkList L;
    // 初始化一个空表
    bool judge;
    judge = InitList(&L);
    if (judge == true)
    {
        printf("初始化完成\n");
    }
    else
    {
        printf("初始化失败\n");
    }
    // 运用头插法向单链表中添加结点
    //    L = HeadInsert(&L);
    // 运用尾插法向单链表中添加结点
    //    L = List_TailInsert(&L);
    // 随机的位置插入结点
    L = RandomInsert(&L);
    // 遍历单链表
    PrintList(&L);
    int pos;
    int num1;
    printf("请输入要删除的位序:");
    scanf("%d", &pos);
    ListDelete(L, pos, num1);
    PrintList(&L);
    return 0;
}