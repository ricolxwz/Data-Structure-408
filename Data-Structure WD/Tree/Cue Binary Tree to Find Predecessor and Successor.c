//
// Created by WENZE XU on 2021/11/13.
//

// 找到以P为根的子树中,第一个被中序遍历的结点
ThreadNode *FirstNode(ThreadNode *p)
{
    // 循环找到最左下的结点(不一定是叶结点,有可能还挂着一个右孩子)
    while (p->ltag == 0)
        p = p->lchild;
    return p;
}

// 在中序线索二叉树中找到结点p的后继结点
ThreadNode *NextNode(ThreadNode *p)
{
    // 找到右子树最左下的结点(不一定是叶结点)
    if (p->rtag == 0)
        return FirstNode(p->rchild);
    else
        return p->rchild; // rtag == 1的话直接返回后继线索
}

// 对中序线索二叉树进行中序遍历(利用线索实现的非递归算法)
void Inorder(ThreadNode *T)
{
    for (ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p))
        visit(p);
}

// 找到以p为根的子树中,最后一个被中序遍历的结点
ThreadNode *LastNode(ThreadNode *p)
{
    // 循环找到最右下角的结点(不一定是右结点)
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}

// 在中序线索二叉树中找到结点p的前驱结点
ThreadNode *PreNode(ThreadNode *p)
{
    // 左子树最右下的结点
    if (p->ltag == 0)
        return LastNode(p->lchild);
    else
        return p->lchild; // 如果ltag==1的话直接返回前驱线索
}

// 对中序线索二叉树进行逆向中序遍历
void RevInorderk(ThreadNode *T)
{
    for (ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p))
        visit(p);
}

// 找到以p为根的子树中,最后一个被中序遍历的结点
ThreadNode *LastNode(ThreadNode *p)
{
    // 循环找到最右下角的结点(不一定是右结点)
    while (p->rtag == 0)
        p = p->rchild;
    return p;
}

// 在中序线索二叉树中找到结点p的前驱结点
ThreadNode *PreNode(ThreadNode *p)
{
    // 左子树最右下的结点
    if (p->ltag == 0)
        return LastNode(p->lchild);
    else
        return p->lchild; // 如果ltag==1的话直接返回前驱线索
}

// 对中序线索二叉树进行逆向中序遍历
void RevInorderk(ThreadNode *T)
{
    for (ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p))
        visit(p);
}

// 在后序线索二叉树中找后序前驱
ThreadNode *PreNode(ThreadNode *p)
{
    if (p->ltag == 1)
        return p->lchild;
    if (p->ltag == 0 && p->rtag == 0)
        return p->rchild;
    if (p->ltag == 0 && p->rtag == 1)
        return p->lchild;
}
//