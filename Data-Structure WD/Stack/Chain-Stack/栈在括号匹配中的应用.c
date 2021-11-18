//
// Created by WENZE XU on 2021/11/13.
//

#include <stdio.h>
#include <stdbool.h>
#define MaxSize 10

typedef struct SqStack
{
    char data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack *P)
{
    P->top = -1;
}

bool StackEmpty(SqStack L)
{
    if (L.top == true)
        return true;
    return false;
}

bool Push(SqStack *P, char Push_char)
{
    if (P->top == MaxSize - 1)
        return false;
    P->data[++(P->top)] = Push_char;
    return true;
}

bool Pop(SqStack *P, char *Pop_char)
{
    if (P->top == -1)
        return false;
    *Pop_char = P->data[(P->top)--];
    return true;
}

bool GetTop(SqStack L, int *Top_num)
{
    if (L.top == -1)
        return false;
    *Top_num = L.data[L.top];
    return true;
}

bool BracketCheck(char str[], int length)
{
    SqStack L;
    InitStack(&L);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            Push(&L, str[i]); // 扫描到左括号,将值推入栈中
        }
        else
        {
            // 检测是否为右括号单身:如果是右括号且为空栈则右括号单身
            if (StackEmpty(L))
                return false;
            char TopElem;
            Pop(&L, &TopElem); // 将栈顶的值取出
            if (str[i] == ')' && TopElem != '(')
                return false;
            if (str[i] == ']' && TopElem != '[')
                return false;
            if (str[i] == '}' && TopElem != '{')
                return false;
        }
    }
    return StackEmpty(L); // 检测是否为左括号单身:如果不是空栈说明还有左括号等待匹配
}

int main()
{
    char str[MaxSize];
    int length;
    printf("请输入一堆括号和括号的个数:");
    scanf("%s %d", str, &length);
    BracketCheck(str, length);
    return 0;
}