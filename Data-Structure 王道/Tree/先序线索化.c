//
// Created by WENZE XU on 2021/11/13.
//

// 先序遍历中的“爱的魔力转圈圈”问题
void PreThread(ThreadTree T) {
    if (T != NULL) {
        visit(T);
        if (T -> ltag == 0)
            PreThread(T -> lchild);
        /*
        PreThread(T -> lchild);
        如果只这样写的话会造成“爱的魔力转圈圈问题”，下次遍历的时候可能会导致重复访问前面的结点
        */
        PreThread(T -> rchild);
    }
}

void visit(ThreadNode *q) {
    if (q -> child == NULL) {
        q -> lchild = pre;
        q -> ltag = q;
    }
    if (pre != NULL && pre -> rchild == NULL) {
        pre -> rchild = q;
        pre -> rtag = 1;
    }
    pre = q;
}

ThreadNode *pre = NULL;