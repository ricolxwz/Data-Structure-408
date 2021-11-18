//
// Created by WENZE XU on 2021/11/13.
//

void LevelOrder(BiTree T)
{                   //
    LinkQueue Q;    // 初始化一个链式存储队列的队头指针和队尾指针
    InitQueue(&Q);  // 建立队列的头结点,并让rear和front指向它,同时将该结点的next值设置为NULL
    BiTNode *P;     // 创立一个用来存储二叉树结点的变量,待会出队的时候用来放访问该结点
    EnQueue(&Q, T); // 将根结点入队,注意此时传入的是根节点的地址T,因为在一开始定义的时候,队列中存储的就是二叉树结点的地址,所以要传入的也是根结点的地址
    while (!IsEmpty(Q))
    {                   // 当队列不空时进入循环,队列为空说明此时已经完成对数的遍历
        DeQueue(&Q, P); // 队头结点出队,并将出队元素的数据即树的节点的地址返回给容器P
        visit(P);       // 访问这个结点
        if (P->lchild != NULL)
            EnQueue(&Q, P->lchild); // 左孩子入队
        if (P->rchild != NULL)
            EnQueue(&Q, P->rchild); // 右孩子入队
    }
}

// 链式队列结点
typedef struct LinkNode
{
    BiTNode *data; // 存放的是二叉树结点的指针
    struct LinkNode *next;
} LinkNode;