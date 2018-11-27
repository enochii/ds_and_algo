- ## Short life

- ### 前言
>
> 不排除内容有点low而且我说的还是错的 的事实
>

- [二分插入](binary_insert.py)
    - 其实就是在二分搜索失败的地方插入新元素。听起来是不是有点耳熟，对，这玩意很容易联想到二叉树插入新节点。为啥应该在二分搜fail的地方insert呢？二分搜结束时low=high，考虑程序归约到只剩一个节点的情形，区间左开右闭，这时low = high - 1，mid = low。如果arr[ mid ]>element，则high是element应该插入的位置，若arr[ mid ]< element,则low是element应该插入的位置，相应地high会-1或者low会+1，对应到二叉树的插入就是在左/右插入新节点。

- [deepest common parent](tree/bst/dcp.py)
    - 查找两个值在树中的dcp(最深公共父节点，没错，这个名字我随便起的。)考虑这个dcp，它应该是从两个节点出发，互相往对方的方向向上走，第一次相遇的地方。同时，容易感性地想到，这是他们通向根节点的路径重合的所有点中，唯一满足x < node.data < y的节点。x y是“两个值”，node代表“所有点”。也就是说，我们根据当前节点的值与x y的大小关系从根节点向下走，当满足x < node.data < y时，node就是所求父节点。
