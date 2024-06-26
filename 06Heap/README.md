# 堆
## 1. Introduction
两种堆:
1. 大堆顶: 堆顶元素最大  
2. 小堆顶: 堆顶元素最小  

堆的特性
- 最底层节点靠左填充，其它层节点都被填满；
- 将二叉树的根节点称为"堆顶", 将底层最靠右的节点称为"堆底"。

堆通常用于实现优先队列，大堆顶相当于元素按照由大到小的顺序出队的优先队列。  
从使用的角度上，二者等价。堆与优先队列可以互换。

堆上的操作
1. push() 元素如堆 O(logn)
2. pop() 堆顶元素出堆 O(logn)
3. peek() 访问堆顶元素 O(1)
4. size() 获取堆的元素数量 O(1)
5. isEmpty() 判断堆是否为空 O(1)

## 2. The Implementation of Heap
### 2.1 The Storage and Representation of heap
堆可以视作一种完全二叉树，因此可以通过数组来表示。  
当使用数组表示二叉树时，数组元素代表节点值，数组索引表示节点在二叉树中的位置。  
反之，节点指针通过索引映射来找到对应的数组索引。  
![堆的逻辑表示和实际表示](https://www.hello-algo.com/chapter_heap/heap.assets/representation_of_heap.png)  

索引映射公式，给定数组索引$i$，
- 左子节点索引$2i+1$
- 右子节点索引$2i+2$, 索引越界时表示节点不存在。
- 父节点索引为$(i-1)/2$(向下取整)。   

### 2.2 Access to Top Element of Heap
访问堆顶元素：直接返回数组的首个元素`maxHeap[0]`。

### 2.3 Push
元素入堆：
1. 先将元素插入到堆底
2. 由于是大顶堆，暂时插入在堆底的元素可能会大于它上层的元素，从而破坏大顶堆的结构，因此需要修复**从插入节点到根节点的路径上**的各个节点，该步骤称为从底至顶的堆化(heapify|shift up)。
    - 从插入的节点开始，循环比较插入的节点是否大于它的父节点，直至满足大顶堆的特性或者到达根节点。
        - 如果插入节点大于它的父节点，则交换。

### 2.4 Pop 堆顶元素出堆
为什么要交换堆顶元素与堆底元素?  
>如果直接删除堆顶元素(数组首元素), 则剩余所有的元素的索引都会改变。  
>交换堆顶元素与堆底元素后，我们可以轻易的删除堆底元素而不对其它元素产生影响。  
>同时，原先的堆底元素交换到堆顶后造成的混乱相对直接删除数组首元素来说是较小的，可以通过执行**自顶向下的堆化对堆化**(shift down)进行修复。

堆顶元素出堆步骤
1. 交换堆顶元素和堆底元素，然后删除该元素
2. 将交换上来的堆顶元素视作父节点，判断堆父节点和它的两个子节点是否满足大顶堆的要求，满足则退出循环，否则
    - 找到父节点元素和它的两个子节点中最大的，然后交换父节点元素和较大的子节点;

**堆的常见应用**
---
1. 优先队列
2. 堆排序
3. 获取最大的$k$个元素

## 3. Construct of Heap
### 3.1 借助入堆操作实现
先建一个空堆，然后对每个元素执行入堆操作。  
这种建堆方式属于自顶向下的建堆，时间复杂度为O(nlog(n))。

### 3.2 通过遍历堆化实现
步骤  
1. 将列表所有元素原封不动添加到堆中，此时堆的性质尚未得到满足；
2. 倒序遍历堆，依次对每个非叶节点执行“从顶至底堆化”。  
倒序遍历可以保证当前节点之下的子树都是合法的子堆。  
由于叶节点没有子节点，因此它们是天然的合法子堆，无须堆化。  

## 4. Top-K问题
采用堆结构解决top-k问题，找到数组中的最大的前k个元素，假设k小于数组大小n  
    
    1. 先使用数组的前k个元素初始化一个小顶堆；
    2. 对于数组中剩余的元素，判断其与小顶堆堆顶元素的大小
        - 如果大于堆顶元素，则弹出堆顶，并将此元素添加入堆。

该算法较为简单，不做实现。

## 5. Q&A
Q：数据结构的“堆”与内存管理的“堆”是同一个概念吗？

两者不是同一个概念，只是碰巧都叫“堆”。计算机系统内存中的堆是动态内存分配的一部分，程序在运行时可以使用它来存储数据。程序可以请求一定量的堆内存，用于存储如对象和数组等复杂结构。当这些数据不再需要时，程序需要释放这些内存，以防止内存泄漏。相较于栈内存，堆内存的管理和使用需要更谨慎，使用不当可能会导致内存泄漏和野指针等问题。