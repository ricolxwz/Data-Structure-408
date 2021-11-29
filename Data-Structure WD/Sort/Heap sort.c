// 建立大根堆
void BuildMaxHeap(int A[], int len)
{
    for (int i = len / 2; i > 0; i--) // 从后往前调整所有非终端结点
    {
        HeadAdjust(A, i, len);
    }
}

// 将以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len)
{
    A[0] = A[k];                          // A[0]暂存子树的根结点
    for (int i = 2 * k; i <= len; i *= 2) // 沿key较大的子结点向下筛选
    {
        if (i < len && A[i] < A[i + 1])
        {
            i++; // 取key较大的子结点的下标
        }
        if (A[0] >= A[i]) // 筛选结束
        {
            break;
        }
        else
        {
            A[k] = A[i]; // 将A[i]调整到双亲结点上
            k = i;       // 修改k值, 以便继续向下筛选
        }
    }
    A[k] = A[0]; // 被筛选结点的值放入最终的位置
}