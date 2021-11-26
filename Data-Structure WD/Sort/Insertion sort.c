// 直接插入排序
void InsertSort(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; ++i) // 将各元素插入已经排好序的序列中
    {
        if (A[i] < A[i - 1]) // 如果A[i]的关键字小于前驱
        {
            temp = A[i];                                // 用temp暂存A[i]
            for (j = i - 1; j >= 0 && A[j] > temp; j--) // 检查所有前面已经排好序的元素
            {
                A[j + 1] = A[j]; // 所有大于temp的元素都向后挪位
            }
            A[j + 1] = temp; // 复制到插入位置
        }
    }
}

// 直接插入排序(带哨兵)
void InsertSort(int A[], int n)
{
    int i, j;
    for (i = 2; i <= n; i++) // 依次将A[2] - A[n]插入到前面已经排序的序列
    {
        if (A[i] < A[i - 1]) // 若A[i]关键码小于其前驱, 将A[i]插入有序表
        {
            A[0] = A[i];                      // 复制为哨兵, A[0]不存放元素
            for (j = i - 1; A[0] < A[j]; --j) // 从后往前查找带插入的位置
            {
                A[j + 1] = A[j]; // 向后挪位
            }
            A[j + 1] = A[0]; // 复制到插入位置
        }
    }
}