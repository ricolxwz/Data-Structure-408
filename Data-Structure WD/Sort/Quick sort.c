// 用第一个元素将待排序序列划分为左右两个部分
int Partition(int A[], int low, int high)
{
    int pivot = A[low]; // 将第一个元素作为枢轴
    while (low < high)  // 用low, high搜索枢轴的最终位置
    {
        while (low < high && A[high] >= pivot)
        {
            --high;
        }
        A[low] = A[high]; // 比枢轴小的元素移动到最左端
        while (low < high && A[low] <= pivot)
        {
            ++low;
        }
        A[high] = A[low]; // 比枢轴大的元素移动到最右端
    }
    A[low] = pivot; // 枢轴元素存放到最终位置
    return low;     // 返回存放枢轴的最终位置
}

// 快速排序
void QuickSort(int A[], int low, int high)
{
    if (low < high) // 递归跳出的条件
    {
        int pivotpos = Partition(A, low, high); // 划分
        QuickSort(A, low, pivotpos - 1);        // 划分左子表
        QuickSort(A, pivotpos + 1, high);       // 划分右子表
    }
}