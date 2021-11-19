## DFS
### 树的深度优先遍历
```c
// 树的先根遍历
void PreOrder(TreeNode *R)
{
    if (R != NULL)
    {
        visit(R); // 访问根结点
        while (R还有下一个子树)
            PreOrder(T); // 先根遍历下一棵子树
    }
}
```
### DFS算法(final版)
```c
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
```
### 复杂度分析
空间复杂度: 来自于函数调用栈
<br>
1. 最坏的情况, 递归深度为`O(|V|)`
<br>
2. 最好的情况, `O(1)`, 就是发散的情况

时间复杂度: 无论是DFS还是BFS, 时间复杂度都可以简化为访问各个结点所需要的时间 + 探索各条边所需要的时间
<br>
1. 邻接矩阵存储的图: 访问`|V|`个结点需要`O(|V|)`的时间, 查找每个顶点的邻接点都需要`O(|V|)`的时间, 而总共有`|V|`个顶点, 时间复杂度 = `O(|V|^2)`
2. 邻接表存储的图: 访问`|V|`个结点需要`O(|V|)`的时间, 查找每个顶点的邻接点都需要`O(|E|)`的时间, 时间复杂度 = `O(|V|+|E|)`
### 深度优先生成树
### 深度优先生成森林
### 图的遍历和图的连通性
对于无向图进行广度或者深度遍历, 调用BFS/DFS函数的次数 = 连通分量数; 对于连通图, 只需要调用一次BFS/DFS

对于有向图进行BFS/DFS遍历, 调用BFS/DFS函数的次数要具体问题具体分析; 若起始顶点到其他各顶点都有路径, 则只需调用一次BFS/DFS函数; ~~如果是强连通图~~, 从任一顶点出发都只需要调用1次BFS/DFS