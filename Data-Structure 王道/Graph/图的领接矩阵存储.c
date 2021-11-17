#define MaxVertexNum 100     // 顶点数目的最大值
#define INFINITY 最大的int值 // 用int的上限表示∞

// 无向图邻接矩阵(非带权图)
typedef struct
{
    char Vex[MaxVertexNum]; // 顶点表
    // 可以将邻接矩阵的数据类型设置为bool, 以减少占用空间
    int Edge[MaxVertexNum][MaxVertexNum]; // 邻接矩阵, 边表
    int vexnum, arcnumn;                  // 图的当前顶点树和边数/弧数
} MGraph;

// 邻接矩阵法存储带权图(网)
typedef char VertexType; // 顶点的数据类型
typedef int EdgeType;    // 带权图边上权值的数据类型
typedef struct
{
    VertexType Vex[MaxVertexNum];              // 顶点
    EdgeType Edge[MaxVertexNum][MaxVertexNum]; // 边的权
    int vexnum, arcnum;                        // 图的当前顶点数和弧度
} MGraph;