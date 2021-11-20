## 最小生成树
### 含义
对于带权无向图G, 生成树不同, 每棵树权的和也不同, 其中, 权值之和最小的即为最小生成树(MST)
### 性质
- 最小生成树不是唯一的, 可能对于一个带权无向图会有多个生成树. 当G中的各边权值互不相等的时候, G的最小生成树就是唯一的. (特殊的, 如果图G本身是一棵树, 则其最小生成树就是自己)
- 只有连通图才有生成树, 非连通图只有生成森林
- 最小生成树的权值是唯一的(最小的)
### 构造最小生成树的算法
1. Prim算法
从某一个顶点开始构建生成树, 直到所有顶点都纳入为止(注意不能成环)
2. Kruskal算法
每次选择一条权值最小的边, 使这条边的两头连通(原本已经连通就不选, 因为要避免成圈)直到所有结点都连通
### 两种算法的比较
1. Prim算法
时间复杂度: O(|V|^2), 适用于边稠密图
2. Kruskal算法
时间复杂度: O(|E|log2|E|), 适用于边稀疏图
### Prim算法的实现思想
1. 循环遍历所有个结点, 找到lowCast最低的, 且还没加入树的顶点
   ![avatar](https://github.com/Ricolxwz/Data-Structure/blob/main/IMG/Graph/The%20realization%20idea%20of%20%E2%80%8B%E2%80%8BPrim%20algorithm%201.png)
2. 再次循环遍历, 更新还没加入各个顶点的lowCast值(就是更新lowCast数组)
   ![avatar](https://github.com/Ricolxwz/Data-Structure/blob/main/IMG/Graph/The%20realization%20idea%20of%20%E2%80%8B%E2%80%8BPrim%20algorithm%202.png)

从V0开始, 总共需要n-1轮处理.(因为有n-1个结点需要加入到生成树中) 每一轮遍历的过程中, 循环遍历所有结点, 找到lowCast最低的, 且还没有入树的顶点. 再次循环遍历, 更新还没有加入的各个顶点的lowCast值. 每一轮的时间复杂度是O(2n). 总的时间复杂度为O(n^2), 即O(|V|^2)
### Kruskal算法的实现思想
1. 第一轮: 检查第一条边的两个顶点是否连通(是否属于同一个集合), 如果是属于同一个集合, 那么无法连接. 如果不是属于同一个集合的话, 把两个顶点连起来.
   ![avatar](https://github.com/Ricolxwz/Data-Structure/blob/main/IMG/Graph/The%20realization%20idea%20of%20%E2%80%8B%E2%80%8BKruskal%20algorithm%201.png)
2. 第二轮: 检查第二条边的两个顶点是否连通(是否属于同一个集合)
3. 依此类推

共执行e轮(有e条边), 每轮判断的两个顶点是否属于同一个集合, 需要O(log2e), 总的时间复杂度O(elog2e)