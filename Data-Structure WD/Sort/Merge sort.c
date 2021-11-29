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