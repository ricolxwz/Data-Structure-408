## 有向无环图描述表达式

### DAG图的定义

若一个有向图中不存在环, 则称为有向无环图, 简称DAG图

### DAG图的生成方法

1. 把各个操作数不重复的排成一排
2. 标出各个运算符的生效顺序(先后顺序有点出入无所谓)
3. 按顺序加入运算符, 注意“分层”
4. 从底向上逐层检查同层的运算符是否可以合体

### DAG图的检验

顶点中不可能出现重复的操作数