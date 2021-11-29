// 简单选择排序
void SelectSort(ElemType A[], int n)
{
    for (i = 0; i < n - 1; i++) // 一共进行n-1趟
    {
        int min = i;                // 记录最小元素的位置
        for (j = i + 1; j < n; j++) // 在A[i...n-1]中选择最小的元素
        {
            if (A[j] < A[min])
            {
                min = j; // 更新最小元素的位置
            }
        }
        if (min != i)
        {
            swap(A[i], A[min]); // 封装的swap()函数共移动元素3次
        }
    }
}

// 交换
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}