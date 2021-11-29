## 归并排序

### 归并的含义

归并: 把两个或者多个已经有序的序列合并成一个

### "m路"归并

- 把m个已经有序的序列合并成一个
- m路归并, 每选出一个元素需要对比关键字m-1次
- 通常使用2路归并

### 核心操作

把数组内的两个有序序列归并为一个

### 代码实现

```c
int *B = (int *)malloc(n * sizeof(int)); // 辅助数组B

// A[low...mid]和A[mid+1...high]各自有序, 将两个部分归并
void Merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    for (k = low, k <= high; k++)
    {
        B[k] = A[k]; // 将A中所有的元素都复制到B中
    }
    for (i = low, j = mid + 1; k = i; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j])
        {
            A[k] = B[i++]; // 将较小的值复制到A中
        }
        else
        {
            A[k] = B[j++];
        }
    }
    while (i <= mid)
    {
        A[k++] = B[i++];
    }
    while (j <= high)
    {
        A[k++] = B[j++];
    }
}

void MergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high);      // 从中间划分
        MergeSort(A, low, mid);      // 对左半部分归并排序
        MergeSort(A, mid + 1, high); // 对右半部分归并排序
        Merge(A, low, mid, high);    // 归并
    }
}
```

### 算法效率分析

- 2路归并的归并树, 在形态上就是一棵倒立的二叉树
- 二叉树的第h层最多有2^(h-1)个结点; 若树高为h, 则应满足n≤2^(h-1), 即h-1=⌈log2n⌉
- n个元素进行2路归并排序, 归并趟数=⌈log2n⌉
- 每趟归并时间复杂度为O(n), 则算法时间复杂度为O(nlog2n)
- 空间复杂度: O(n), 来自于辅助数组B
- 稳定性: 稳定