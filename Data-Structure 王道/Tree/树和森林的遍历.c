//
// Created by ricol on 2021/11/13.
//
// 树的先根遍历
void PreOrder(TreeNode *R)
{
    if (R != NULL)
    {
        visit(R); // 访问根结点
        while (R还有下一棵子树T)
            PreOrder(T); // 先根遍历下一棵子树
    }
}

void PostOrder(TreeNode *R)
{
    if (R != NULL)
    {
        while (R还有下一个孩子)
            PostOrder(T); // 后根遍历下一棵子树
        visit(R);         // 访问根结点
    }
}