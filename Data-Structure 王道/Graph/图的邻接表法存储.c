// 邻接表法(顺式+链式存储)
// 用邻接表存储的图
typedef struct {
    AdjList vertices;1
    int vexnum, arcnum;
} ALGraph;

// 顶点
typedef struct VNode {
    VertexType data; // 顶点的信息
    ArcNode *first; // 第一条边/弧
} VNode, AdjList[MaxVertexNum];

// "边"/"弧"
typedef struct ArcNode {
    int adjvex; // 边/弧指向哪个结点
    struct ArcNode *next; // 指向下一条弧的指针
    // InfoType info; // 边的权值
} ArcNode;