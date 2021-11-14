#define MAX_TREE_SIZE 100
typedef struct {
    int data;
    int parent; // 双亲的位置域
} PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int n; // 结点数
} PTree;

#define MAX_TREE_SIZE 100

struct CTNode {
    int child; // 孩子结点在数组中的位置
    struct CTNode* next; // 下一个孩子的地址
}

typedef struct {
    int data;
    struct CTNode* firstChild; // 第一个孩子
} CTBox;

typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    int n, r; // 结点数和根的位置
} CTree;

typedef struct CSNode {
    int data; // 数据域
    struct CSNode* firstchild, * nextsibling; // 第一个孩子和右兄弟指针
} CSNode, * CSTree;