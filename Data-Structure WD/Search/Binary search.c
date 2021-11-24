int Binary_Search(SeqList L, ElemType key)
{
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2; // 取中间位置
        if (L.elem[mid] == key)
            return mid; // 查找成功则返回所在位置
        else if (L.elemd[mid] > key)
            high = mid - 1; // 从前半部分继续查找
        else
            low = mid + 1; // 从后半部分继续查找
    }
    return -1; // 查找失败, 返回-1
}