# 树
## 1. Binary Tree(二叉树)
### 1.1 Introduction
二叉树的基本单元是节点，每个节点包含值、左子树指针、右子树指针。

二叉树中，除了叶节点外，其它所有节点都包含子节点与非空子树。

二叉树常见术语  
1. 根节点（root node）：位于二叉树顶层的节点，没有父节点。  
2. 叶节点（leaf node）：没有子节点的节点，其两个指针均指向 None 。
3. 边（edge）：连接两个节点的线段，即节点引用（指针）。
4. 节点所在的层（level）：从顶至底递增，根节点所在层为 1 。
5. 节点的度（degree）：节点的子节点的数量。在二叉树中，度的取值范围是 0、1、2 。
6. 二叉树的高度（height）：从根节点到最远叶节点所经过的边的数量。
7. 节点的深度（depth）：从根节点到该节点所经过的边的数量。
8. 节点的高度（height）：从距离该节点最远的叶节点到该节点所经过的边的数量。  
![](https://www.hello-algo.com/chapter_tree/binary_tree.assets/binary_tree_terminology.png)

二叉树操作
1. 初始化二叉树
2. 插入与删除节点

常见二叉树树型
1. 完美二叉树(满二叉树, perfect binary tree)：所有层所有节点都被填满  
![](https://www.hello-algo.com/chapter_tree/binary_tree.assets/perfect_binary_tree.png)
2. 完全二叉树(complete binary tree):只有最底层的节点未被填满，且最底层的节点尽量往左边靠。
![](https://www.hello-algo.com/chapter_tree/binary_tree.assets/complete_binary_tree.png)
3. 完满二叉树(full binary tree): 除叶节点外，其它所有节点都有两个节点。
![](https://www.hello-algo.com/chapter_tree/binary_tree.assets/full_binary_tree.png)
4. 平衡二叉树(balanced binary tree): 任意节点的左子树和右子树的高度差的绝对值小于等于1。
![](https://www.hello-algo.com/chapter_tree/binary_tree.assets/balanced_binary_tree.png)

### 1.2 Traversal of Binary Tree
从物理结构的角度来看，树是一种**基于链表的数据结构**，因此其遍历方式是通过指针逐个访问节点。  
然而，树是一种非线性数据结构，这使得遍历树比遍历链表更加复杂，需要借助**搜索算法**来实现。

二叉树常见的遍历方式包括层序遍历、前序遍历、中序遍历和后序遍历等。 

- 层序遍历：在二叉树上使用广度优先搜索，并且优先选择左子树。![](https://www.hello-algo.com/chapter_tree/binary_tree_traversal.assets/binary_tree_bfs.png)
- 前、中、后序遍历：在二叉树上使用深度优先搜索。![](https://www.hello-algo.com/chapter_tree/binary_tree_traversal.assets/binary_tree_dfs.png)
    1. 前序遍历: 根节点 -> 左子树 -> 右子树
    2. 中序遍历: 左子树 -> 根节点 -> 右子树
    3. 后序遍历: 左子树 -> 右子树 -> 根节点

### 1.3 The Array Representation of Binary Tree
给定一棵完美二叉树，我们将所有节点按照层序遍历的顺序存储在一个数组中，则每个节点都对应于一个唯一的数组索引。

根据层序遍历特性，可以推理出父节点索引(i)与左右子节点的索引映射公式  
左节点索引: 2i+1  
右节点索引: 2i+2  
![](https://www.hello-algo.com/chapter_tree/array_representation_of_tree.assets/array_representation_binary_tree.png)

对于不完全的二叉树，我们需要为中间层为None的位置的层序遍历序列添加None。![](https://www.hello-algo.com/chapter_tree/array_representation_of_tree.assets/array_representation_with_empty.png)

二叉树的两种实现
---
1. 基于链表的实现
2. 基于数组的实现

二叉树上的基本操作
---
1. 二叉树的构造
2. 节点的插入与删除

## 2. Binary Search Tree
二叉搜索树的性质  
1. 对于根节点，左子树中所有节点的值 < 根节点的值 < 右子树所有节点的值；
2. 任意节点的左右子树也是二叉搜索树，同样满足条件1。

二叉搜索树的操作
---
1. 查找：给定一棵二叉搜索树`root`和一个目标值`num`，查找目标值对应的节点。  
声明一个`cur`变量指向二叉搜索树的根节点`root`，循环比较`cur.val`和`num`:  
    - 如果`cur.val > num`, 则说明`num`可能在左子树中；
    - 如果`cur.val < num`, 则说明`num`可能在右子树中； 
    - 如果`cur.val == num`, 则退出循环并返回当前节点。

2. 插入：给定一个待插入的元素`num`和一棵二叉搜索树`root`  
    1. 查找插入的位置：与查找操作相似，从根节点出发，根据当前节点值和 `num` 的大小关系循环向下搜索，直到越过叶节点（遍历至 `None` ）时跳出循环。
    2. 在该位置插入节点：初始化节点 num ，将该节点置于 None 的位置。
    ![](https://www.hello-algo.com/chapter_tree/binary_search_tree.assets/bst_insert.png)

3. 删除：先在二叉树中找到对应的节点，再删除它
    1. 如果没找到，则不对二叉树做操作；
    2. 如果找到了，
        - 假设目标节点是中间层节点或者叶节点，根据目标节点的度分为0、1、2三种情况
            - 当节点的度为0时，直接删除该节点即可；
            - 当节点的度为1时，删除该节点并将其子节点附着到父节点上即可。
            - 当节点的度为2时
                - 查找`cur`在中序遍历中的后序节点`nex`
                - 在二叉树中递归删除节点`nex`
                - 将节点`nex`的值赋给`cur`
        - 假设目标节点是根节点, 它的度可以分为0、1、2三种情况
            - 当节点度为0时，直接将root置为nullptr;
            - 当节点度为1时，则将其唯一的子节点作为root;
            - 当节点度为2时，则
                - 查找`root`在中序遍历中的后序节点`nex`
                - 在二叉树中递归删除节点`nex`
                - 将节点`nex`的值赋给`root`

二叉搜索树的常见应用  
1. 作为系统中的多级索引，实现高效的查找、插入、删除操作；
2. 作为某些算法的底层数据结构；
3. 用于存储数据流，以保持其有序状态。