## BFS算法 最短路径问题

### 最短路径问题

1. 单源最短路径问题
   BFS算法(无权图)
2. 每对顶点间的最短路径

### 代码实现
```c
// 求顶点u到其他顶点的最短路径
void BFS_MIN_Distance(Graph G, int u)
{
	// d[i]表示从u开始到i顶点的最短路径
	for (i = 0; i < G.vexnum; i++)
	{
		d[i] = ∞; // 初始化路径长度
		path[i]  = -1; // 最短路径从哪个顶点过来
	}
   d[u] = 0;
   visited[u] = TRUE;
   EnQueue(Q, u);
   while (!isEmpty(Q)) 
   {
      DeQueue(Q, u);
      for (w = FirstNeighbor(G, u); W >= 0; w = NextNeighbor(G, u, w))
         if (!visited[w]) // w为u的尚未访问的邻接顶点
            {
               d[w] = d[u] + 1; // 路径长度+1
               path[w] = u;// 最短路径应从u到w
               visited[w] = TRUE; // 设已访问的标记
               EnQueue(Q, w); // 顶点w入队
            }
   }
}
```
