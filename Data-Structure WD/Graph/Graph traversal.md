## 图的遍历
### 广度优先遍历
要点：<br>
1. 找到与一个顶点相邻的所有顶点
   - `FirstNeighbor(G, x)`
   - `NextNeighbor(G, x, y)`
2. 标记哪些顶点被访问过
   - `bool visited[MAX_VERTEX_NUM]`
3. 需要一个辅助队列


