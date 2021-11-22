void BFS_MIN_Distance(Graph G, int u)
{
    // d[i]表示从u到i结点的最短路径
    for (i = 0; i < G.vexnum; i++)
    {
        d[i] = ∞;     // 初始化路径长度为无穷
        path[i] = -1; // 初始化前驱结点为-1
    }
    visited[u] = TRUE;
    d[u] = 0;
    EnQueue(Q, u);
    while (!isEmpty(Q)) // BFS算法主过程
    {
        DeQueue(Q, u); // 队头元素出队, 并将序号返回给u
        for (w = FirstNeikghbor(G, u); w >= 0; w = NextNeighbor(G, u, w))
        {
            if (!visited[w]) // w为u尚未访问过的邻接顶点
            {
                visited[w] = TRUE; // 设置已访问的标记
                d[w] = d[u] + 1;   // 路径长度加1
                path[w] = u;       // 将w的前驱邻接顶点设为u
                EnQueue(Q, w);     // 顶点w入队
            }
        }
    }
}