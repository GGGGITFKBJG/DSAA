### 558. 四叉树交集

> <div class="content__2ebE"><p>四叉树是一种树数据，其中每个结点恰好有四个子结点：<code>topLeft</code>、<code>topRight</code>、<code>bottomLeft</code>&nbsp;和&nbsp;<code>bottomRight</code>。四叉树通常被用来划分一个二维空间，递归地将其细分为四个象限或区域。</p>
> 
> <p>我们希望在四叉树中存储 True/False 信息。四叉树用来表示 <code>N * N</code> 的布尔网格。对于每个结点, 它将被等分成四个孩子结点<strong>直到这个区域内的值都是相同的</strong>。每个节点都有另外两个布尔属性：<code>isLeaf</code>&nbsp;和&nbsp;<code>val</code>。当这个节点是一个叶子结点时&nbsp;<code>isLeaf</code>&nbsp;为真。<code>val</code>&nbsp;变量储存叶子结点所代表的区域的值。</p>
> 
> <p>例如，下面是两个四叉树 A 和 B：</p>
> 
> <pre>A:
> +-------+-------+   T: true
> |       |       |   F: false
> |   T   |   T   |
> |       |       |
> +-------+-------+
> |       |       |
> |   F   |   F   |
> |       |       |
> +-------+-------+
> topLeft: T
> topRight: T
> bottomLeft: F
> bottomRight: F
> 
> B:               
> +-------+---+---+
> |       | F | F |
> |   T   +---+---+
> |       | T | T |
> +-------+---+---+
> |       |       |
> |   T   |   F   |
> |       |       |
> +-------+-------+
> topLeft: T
> topRight:
>      topLeft: F
>      topRight: F
>      bottomLeft: T
>      bottomRight: T
> bottomLeft: T
> bottomRight: F
> </pre>
> 
> <p>&nbsp;</p>
> 
> <p>你的任务是实现一个函数，该函数根据两个四叉树返回表示这两个四叉树的逻辑或(或并)的四叉树。</p>
> 
> <pre>A:                 B:                 C (A or B):
> +-------+-------+  +-------+---+---+  +-------+-------+
> |       |       |  |       | F | F |  |       |       |
> |   T   |   T   |  |   T   +---+---+  |   T   |   T   |
> |       |       |  |       | T | T |  |       |       |
> +-------+-------+  +-------+---+---+  +-------+-------+
> |       |       |  |       |       |  |       |       |
> |   F   |   F   |  |   T   |   F   |  |   T   |   F   |
> |       |       |  |       |       |  |       |       |
> +-------+-------+  +-------+-------+  +-------+-------+
> </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>提示：</strong></p>
> 
> <ol>
> 	<li><code>A</code>&nbsp;和&nbsp;<code>B</code>&nbsp;都表示大小为&nbsp;<code>N * N</code>&nbsp;的网格。</li>
> 	<li><code>N</code>&nbsp;将确保是 2 的整次幂。</li>
> 	<li>如果你想了解更多关于四叉树的知识，你可以参考这个&nbsp;<a href="https://en.wikipedia.org/wiki/Quadtree">wiki</a>&nbsp;页面。</li>
> 	<li>逻辑或的定义如下：如果&nbsp;<code>A 为 True</code> ，或者&nbsp;<code>B 为 True</code> ，或者&nbsp;<code>A 和 B 都为 True</code>，则 "A 或 B" 为 True。</li>
> </ol>
> </div>

解法一
```cpp
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* build(Node* root1, Node* root2) {
        if(root1->isLeaf || root2->isLeaf) {//遇到叶结点
            if(!(root1->isLeaf)) {//交换
                Node* temp = root1;
                root1 = root2;
                root2 = temp;
            }
            if(root1->val) return root1;
            else return root2;
        }
        
        Node* newTree = new Node(false, false, nullptr, nullptr, nullptr, nullptr);//构造（非叶子）结点
        newTree->topLeft = build(root1->topLeft, root2->topLeft);
        newTree->topRight = build(root1->topRight, root2->topRight);
        newTree->bottomLeft = build(root1->bottomLeft, root2->bottomLeft);
        newTree->bottomRight = build(root1->bottomRight, root2->bottomRight);
        if(newTree->topLeft->isLeaf && newTree->topRight->isLeaf &&
           newTree->bottomLeft->isLeaf && newTree->bottomRight->isLeaf &&
            newTree->topLeft->val == newTree->topRight->val &&
           newTree->topRight->val == newTree->bottomLeft->val &&
           newTree->bottomLeft->val == newTree->bottomRight->val)//合并
            newTree = newTree->topLeft;
        return newTree;
    }
    
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(!quadTree1) return quadTree2;
        if(!quadTree2) return quadTree1;
        return build(quadTree1, quadTree2);
    }
};
```

思路：

1. 同时对两个四叉树进行递归遍历，终止条件为至少其中一个结点为叶子结点。
2. 如果遇到叶结点，就求并集返回。上述解中使用了交换结点指针来避免多次判断。
3. 额外要注意的是，如果一个结点的4个子结点都是叶子，而且值相同，那需要把它们合并成一个叶子结点。

为了编程简洁，这里留了一个潜在的问题。构造并集树的过程中，返回的子结点并不都是新创建的（通过new操作），有些直接将原树的结构指针直接返回，所以求完并集操作后原来的两个四叉树可能失效，而且更容易造成内存泄漏。如果是在实际应用中，最好是复制而不是直接引用。

<div style="text-align: right"> 2019/06/1 18:17 </div>