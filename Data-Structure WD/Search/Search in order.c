typedef struct // 查找表的数据结构(顺序表)
{
    ElemType *elem; // 动态数组基址
    int TableLen;   // 表的长度
} SSTable;

// 顺序查找
int Search_Seq(SSTable ST, ElemType key)
{
    int i;
    for (i = 0; i < ST.TableLen && ST.elem[i] != key; ++i)
        ; // 从前往后找
    return i == ST.TableLen ? -1 : i;
}

// 顺序查找(“哨兵”模式)
int Search_Seq(SSTable ST, ElemType key)
{
    ST.elem[0] = key; // 哨兵
    int i;
    for (i = ST.TableLen; ST.elem[i] != key; --i)
        ;     // 从后往前找
    return i; // 查找成功, 则返回元素下标; 查找失败, 则返回0
}