## B树

### 5叉排序树的结点定义

```c
struct Node {
    ElemType keys[4]; // 最多4个关键字
    struct Node *child[5]; // 最多五个孩子
    int num; // 节点中有几个关键字
};
```

- 最少1个关键字, 2个分叉; 最多4个关键字, 5个分叉
- 结点内关键字有序

### 如何保证查找效率

- 若每个结点内关键字太少, 导致树变高, 要查更多层的结点, 效率低
  - 策略1: m叉查找树中, 规定除了根结点外, 任何结点至少有⌈m/2⌉个分叉, 即至少含有⌈m/2⌉-1个关键字(如果整棵树只有1个元素, 根结点只有两个分叉)(对于5叉查找树, 除根结点外, 至少有3个分叉, 2个关键字)
- 不够平衡, 树会很高, 要查很多层结点
  - 策略2: m叉查找树中, 规定对于任何一个结点, 其所有子树的高度都要相同

### B树的定义

B树, 又称多路平衡查找树, B树中所有结点的孩子个数的最大值称为B树的阶, 通常用m表示. 一棵m阶B树或为空树, 或为满足如下特性的m叉树:
1. 树中每个结点至多有m棵子树, 即至多含有m-1个关键字
2. 若根结点不是终端结点, 则至少有两棵子树
3. 除根结点外的所有非叶结点至少有⌈m/2⌉棵子树, 即至少含有⌈m/2⌉-1个关键字
4. 所有的叶子结点都出现在同一层次上, 并且不带信息(可以视为外部结点或者类似于折半查找树的查找失败结点, 实际上这些结点不存在, 指向这些结点的指针为空)
5. 所有非叶结点的结构如下:
    |   n   |  P0   |  K1   |  P1   |  K2   |  P2   |  ...  |  Kn   |  Pn   |
    | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
    
    其中, Ki(i=1, 2, ..., n)为结点的关键字, 且满足K1<K2<...Kn; Pi(i=0, 1, ..., n)为指向子树根结点的指针, 且指针Pi-1所指子树中所有结点的关键字均小于Ki, Pi所指子树中所有结点的关键字均大于Ki, n(⌈m/2⌉-1≤n≤m-1)为结点中关键字的个数

### m阶B树的核心特性

1. 根结点的子树数∈[2, m], 关键字数∈[1, m-1]
   <br>其他结点的子树数∈[⌈m/2⌉, m]; 关键字数∈[⌈m/2⌉-1, m-1]
2. 对任一结点, 其所有子树的高度相同
3. 关键字的值: 子树0<关键字1<子树1<关键字2<子树2<...(类比二叉查找树 左<中<右)

### B树的高度

问题: 含n个关键字的m阶B树, 最小高度、最大高度是多少?
- 最小高度——让每个结点尽可能填满, 有m-1个关键字, m个分叉. 则结点的总数为(m-1)(1+m+m^2+...+m^(h-1))=m^h-1, 则要使n个节点构成的B树高度为h的话, 要满足n≤m^h-1, 因此h≥logm(n+1)
- 最大高度——让各层的分叉尽可能的少, 即根结点只有2个分叉, 其他结点只有⌈m/2⌉个分叉, 各层结点**至少**有: 第一层1、第二层2、第三层2⌈m/2⌉...第h层2(⌈m/2⌉)^(h-2), 第h+1层至少有叶子结点(失败结点)2(⌈m/2⌉)^(h-1)个. n个关键字的B树必有n+1个叶子结点, 则n+1≥2(⌈m/2⌉)^(h-1), 即h≤log⌈m/2⌉((n+1)/2)+1

B树的高度满足: logm(n+1)≤h≤log⌈m/2⌉((n+1)/2)+1