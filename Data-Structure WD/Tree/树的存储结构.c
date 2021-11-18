#define MAX_TREE_SIZE 100
typedef struct
{
    int data;
    int parent; // ˫�׵�λ����
} PTNode;

typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int n; // �����
} PTree;

#define MAX_TREE_SIZE 100

struct CTNode
{
    int child;           // ���ӽ���������е�λ��
    struct CTNode *next; // ��һ�����ӵĵ�ַ
}

typedef struct
{
    int data;
    struct CTNode *firstChild; // ��һ������
} CTBox;

typedef struct
{
    CTBox nodes[MAX_TREE_SIZE];
    int n, r; // ������͸���λ��
} CTree;

typedef struct CSNode
{
    int data;                                // ������
    struct CSNode *firstchild, *nextsibling; // ��һ�����Ӻ����ֵ�ָ��
} CSNode, *CSTree;