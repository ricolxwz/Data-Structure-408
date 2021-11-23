bool TopologicalSort(Graph G)
{
    InitStack(S); // 初始化栈, 存储入度为0的顶点
    for (int i = 0; i < G.vexnum; i++)
    {
        if (indegree[i] == 0)
        {
            Push(S, i); // 将所有入度为0的顶点进栈
        }
    }
    int count = 0;      // 计数, 记录当前已经输出的顶点数
    while (!isEmpty(S)) // 栈不空, 则存在入度为0的顶点
    {
        Pop(S, i);                                          // 栈顶元素出栈
        print[count++] = i;                                 // 输出顶点i
        for (p = G.vertices[i].firstarc; p; p = p->nextarc) // 将所有i指向的顶点的入度减1, 并且将入读减为0的顶点压入栈S
        {
            v = p->adjvex;
            if (!(--indegree[v]))
            {
                Push(S, v); // 入度为0, 出栈
            }
        }
    }
    if (count < G.vexnum)
        return false; // 排序失败, 有向图中有回路
    else
        return true; // 拓扑排序成功
}