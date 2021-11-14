//
// Created by WENZE XU on 2021/11/13.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue *P) {
    P -> front = 0;
    P -> rear = 0;
}

bool IsEmpty(SqQueue Q) {
    if (Q.rear == Q.front) return true;
    else return false;
}

bool EnQueue(SqQueue *P, int num) {
    if (((P -> rear) + 1) % MaxSize == P -> rear) return false;
    (*P).data[(*P).rear] = num;
    (*P).rear = ((*P).rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue *P, int *P_num) {
    if ((*P).rear == (*P).front) return false;
    *P_num = (*P).data[(*P).front];
    (*P).front = ((*P).front + 1) % MaxSize;
    return true;
}

int main() {
    SqQueue Q;
    int num;
    bool judge;
    printf("请输入需要入队的元素:");
    scanf("%d", &num);
    InitQueue(&Q);
    judge = IsEmpty(Q);
    if (judge) printf("队空\n");
    EnQueue(&Q, num);
    judge = IsEmpty(Q);
    if (judge == false) printf("非空\n");
    DeQueue(&Q, &num);
    printf("出队的元素为%d\n", num);