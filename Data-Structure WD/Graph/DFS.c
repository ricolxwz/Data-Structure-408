bool visited[MAX_VERTEX_NUM]; // 访问标记数组

void DFS(Graph G, int v) // 从顶点v出发, 深度优先遍历图G
{
    visit(v);          // 访问顶点v
    visited[v] = TRUE; // 设已访问标记
    for (w = FirstNeighbor(G, v); w >= 0; w = NextNeighbor)
    {
        if (!visited[w]) // w为u的尚未访问的邻接顶点
            DFS(G, w);
    }
}

/*
    存在的问题:
        无法遍历非连通图
*/

void DFSTraverse(Graph G) // 对图G进行深度优先遍历
{
    for (v = 0; v < G.vexnum; v++) // 初始化已访问标记数据
        visited[v] = FALSE;
    for (v = 0; v < G.vexnum; v++) // 本代码中是从v=0开始遍历
        if (!visited[v])
            DFS(G, v);
}