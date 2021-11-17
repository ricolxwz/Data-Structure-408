//
// Created by WENZE XU on 2021/11/13.
//

#include <stdio.h>
#include <stdbool.h>

#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

void InitList(SqList *p)
{
    for (int i = 0; i < MaxSize; i++)
    {
        p->data[i] = i;
    }
    p->length = MaxSize - 1; // 先预留一个位置,给新加进来的元素提供位置
}

bool ListInsert(SqList *p, int num, int place)
{
    if (place < 1 || place > p->length + 1)
        return false;
    if (p->length >= MaxSize)
        return false;
    for (int j = p->length; j >= place; j--)
        p->data[j] = p->data[j - 1];
    p->data[place - 1] = num;
    p->length++;
    return true;
}

bool ListDelete(SqList *p, int place_delete)
{
    if (place_delete < 1 || place_delete > p->length)
        return false;
    for (int j = place_delete - 1; j < p->length - 1; j++)
        p->data[j] = p->data[j + 1];
    p->length--;
    return true;
}

int LocateElem(SqList *p, int num_locate)
{
    for (int i = 0; i < p->length; i++)
    {
        if (p->data[i] == num_locate)
        {
            return i + 1;
        }
    }
    return 0;
}

int main()
{
    SqList L;
    SqList *p = &L;
    InitList(p);
    printf("%p\n", L.data);
    printf("%p\n", p);
    printf("%p\n", &(L.data[0]));
    printf("请输入需要插入的数和要插入的位置:");
    int num;
    int place;
    scanf("%d %d", &num, &place);
    bool judge;
    judge = ListInsert(p, num, place);
    if (judge == true)
    {
        printf("插入成功\n");
    }
    else
    {
        printf("插入失败\n");
    }
    for (int i = 0; i < MaxSize; i++)
    {
        printf("data[%d] = %d\n", i, L.data[i]);
    }
    int place_delete;
    printf("请输入需要删除的位置:");
    scanf("%d", &place_delete);
    bool judge_delete;
    judge_delete = ListDelete(p, place_delete);
    if (judge_delete == true)
    {
        printf("删除成功\n");
    }
    else
    {
        printf("删除失败\n");
    }
    for (int i = 0; i < MaxSize; i++)
    {
        printf("data[%d] = %d\n", i, L.data[i]);
    }
    printf("请输入需要寻找的值:");
    int num_locate;
    scanf("%d", &num_locate);
    int Locate;
    Locate = LocateElem(p, num_locate);
    if (Locate != 0)
    {
        printf("查找成功,位序为%d", Locate);
    }
    else
    {
        printf("查找失败");
    }
    return 0;
}