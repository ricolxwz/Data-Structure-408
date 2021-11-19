bool visited[MAX_VERTEX_NUM]; // 初始的时候visited数组都是false

// 广度优先遍历
void BFS(Graph G, int v) // 从顶点v出发, 广度优先遍历图G
{
    visit(v);          // 访问初始顶点v
    visited[v] = TRUE; // 对v做已访问标记
    Enquene(Q, v);     // 顶点v入队列Q
    while (isEmpty(Q))
    {
        DeQueue(Q, v); // 顶点v出队列, 出队的时候更新了v
        for (w = FirstNetghbor(G, v); w >= 0; w = NextNeighbor(G, v, w))
            // 检测v所有的邻接点
            if (!visited[w]) // w为v的尚未访问的邻接点
            {
                visit(w);          // 访问顶点w
                visited[w] = TRUE; // 对w做已经访问过的标记
                EnQueue(Q, w);     // 顶点w入队列
            }
    }
}