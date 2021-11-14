//
// Created by WENZE XU on 2021/11/13.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue *P) {
    P -> front = P -> rear = (LinkNode *)malloc(sizeof(LinkNode));
    (P -> front) -> next = NULL;
}

bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) return true;
    else return false;
}

void EnQueue(LinkQueue *P, int num) {
    LinkNode *S = (LinkNode *)malloc(sizeof(LinkNode));
    S -> data = num;
    S -> next = NULL;
    (P -> rear) -> next = S;
    P -> rear = S;
}

void DeQueue(LinkQueue *P, int *P_num) {
    if (P -> rear == P -> front) printf("该队为空,无法执行出队操作");
    LinkNode *L = P -> front -> next;
    (*P_num) = L -> data;
    P -> front -> next = L -> next;
    if (P -> rear == L) {
        P -> rear = P -> front; // 如果删除的是队列的最后一个结点的话,要修改rear的值,让它再次指向头结点,而不是头结点后的那个结点
    }
    free(L);
}

int main() {
    bool judge;
    int num;
    printf("请输入需要入队的数据:");
    scanf("%d", &num);
    LinkQueue Q;
    InitQueue(&Q);
    judge = IsEmpty(Q);
    if (judge) printf("该队为空\n");
    else printf("该队非空\n");
    EnQueue(&Q, num); // 入队
    judge = IsEmpty(Q);
    if (judge) printf("该队为空\n");
    else printf("该队非空\n");
    DeQueue(&Q, &num); // 出队
    judge = IsEmpty(Q);
    if (judge) printf("该队为空\n");
    else printf("该队非空\n");
    return 0;
}