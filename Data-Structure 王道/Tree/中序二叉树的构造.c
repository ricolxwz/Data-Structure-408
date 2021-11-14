//
// Created by WENZE XU on 2021/11/13.
//

// 中序建立线索二叉树
void InThread(TreadTree &P, ThreadTree &pre) {
if ((P) != NULL) {
InThread(P -> lchild, pre);
if (P -> lchild == NULL) {
P -> lchild = pre;
P -> ltag = 1;
}
if (pre != NULL && pre -> rchild) { // 这里的pre!=NULL是因为当pre为NULL时即访问第一个结点不能对NULL进行pre->rchild操作
pre -> rchild = P;
pre -> rtag = 1;
}
pre = P;
InThread(P -> rchild, pre); // 结束循环的时候，pre指向最后一个结点
}
}

void CreateInThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T != NULL) { // 只能对非空二叉树执行线索化
        InThread(T, pre);
        pre -> rchild = NULL; // 处理遍历的最后一个结点，将pre的右孩子设为空
        pre -> rtag = 1;
    }
}
// 此处用了引用类型，C里面是没有引用类型的，这里是为了方便

ThreadNode *pre = NULL;

typedef struct ThreadNode
{
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag; // 左右线索的标志
} ThreadNode, *ThreadTree;

void CreatInThread(ThreadTree T) {
    pre = NULL;
    if (T != NULL) { // 非空二叉树才能执行线索化
        InThread(T);
        if (pre -> rchild == NULL) pre -> rtag = 1;
    }
}

void InThread(ThreadTree T) {
    if (T != NULL) {
        InThread(T -> lchild);
        visit(T);
        InThread(T -> rchild);
    }
}

void visit(ThreadNode *q) {
    if (q -> lchild = NULL) { // 左子树为空,建立前驱线索
        q -> lchild = pre;
        q -> ltag = 1;
    }
    if (pre != NULL && pre -> rchild == NULL) {
        pre -> rchild = q; // 建立前驱结点的后继线索
        pre -> rtag = 1;
    }
    pre = q;
}