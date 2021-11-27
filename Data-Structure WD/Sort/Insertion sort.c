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

// 折半插入排序
void InsertSort(int A[], int n)
{
    int i, j, lowm, high, mid;
    for (i = 2; i <= n; i++) // 依次将A[2]~A[n]插入前面的已排序序列
    {
        A[0] = A[i]; // 将A[i]暂存到A[0]
        low = 1;     // 设置折半查找的范围
        high = i - 1;
        while (low <= high) // 折半查找(默认递增有序)
        {
            mid = (low + high) / 2; // 取中间点
            if (A[mid] > A[0])
            {
                high = mid - 1; // 查找左半子表
            }
            else
            {
                low = mid + 1; // 查找右半子表
            }
            for (j = i - 1; j >= high + 1; --j)
            {
                A[j + 1] = A[j]; // 统一后移元素, 空出插入位置
            }
            A[high + 1] = A[0]; // 插入操作
        }
    }
}