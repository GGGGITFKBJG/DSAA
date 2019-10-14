### 427. 建立四叉树

> <div class="content__2ebE"><p>我们想要使用一棵四叉树来储存一个&nbsp;<code>N x N</code>
> 的布尔值网络。网络中每一格的值只会是真或假。树的根结点代表整个网络。对于每个结点,
> 它将被分等成四个孩子结点<strong>直到这个区域内的值都是相同的.</strong></p>
> 
> <p>每个结点还有另外两个布尔变量:&nbsp;<code>isLeaf</code>
> 和&nbsp;<code>val</code>。<code>isLeaf</code>
> 当这个节点是一个叶子结点时为真。<code>val</code>&nbsp;变量储存叶子结点所代表的区域的值。</p>
> 
> <p>你的任务是使用一个四叉树表示给定的网络。下面的例子将有助于你理解这个问题：</p>
> 
> <p>给定下面这个<code>8 x 8</code>&nbsp;网络，我们将这样建立一个对应的四叉树：</p>
> 
> <p><img style="height:27%; width:27%"
> src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/01/962_grid.png"
> alt=""></p>
> 
> <p>由上文的定义，它能被这样分割：</p>
> 
> <p><img style="height:100%; width:100%"
> src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/01/962_grid_divided.png"
> alt=""></p>
> 
> <p>&nbsp;</p>
> 
> <p>对应的四叉树应该像下面这样，每个结点由一对&nbsp;<code>(isLeaf, val)</code>&nbsp;所代表.</p>
> 
> <p>对于非叶子结点，<code>val</code>&nbsp;可以是任意的，所以使用&nbsp;<code>*</code>&nbsp;代替。</p>
> 
> <p><img style="height:100%; width:100%"
> src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/01/962_quad_tree.png"
> alt=""></p>
> 
> <p><strong>提示：</strong></p>
> 
> <ol> 	<li><code>N</code>&nbsp;将小于&nbsp;<code>1000</code>&nbsp;且确保是 2
> 的整次幂。</li> 	<li>如果你想了解更多关于四叉树的知识，你可以参考这个&nbsp;<a
> href="https://en.wikipedia.org/wiki/Quadtree">wiki</a>&nbsp;页面。</li>
> </ol> </div>

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
    Node* buildTree(vector<vector<int>>& grid, int x1, int y1, int x2, int y2) {
        if(x1 == x2 && y1 == y2) return new Node(grid[x1][y1], true, nullptr, nullptr, nullptr, nullptr);
        
        bool allSame = true;
        for(int i = x1; i <= x2; i++) {
            for(int j = y1; j <= y2; j++) {
                if(grid[i][j] != grid[x1][y1]) {
                    allSame = false;
                    break;
                }
            }
            if(!allSame) break;
        }
        
        if(allSame) return new Node(grid[x1][y1], true, nullptr, nullptr, nullptr, nullptr);
        Node* cur = new Node;
        cur->val = true;//没有用
        cur->isLeaf = false;
        cur->topLeft = buildTree(grid, x1, y1, x1 + (x2 - x1) / 2, y1 + (y2 - y1) / 2);
        cur->topRight = buildTree(grid, x1, y1 + (y2 - y1) / 2 + 1, x1 + (x2 - x1) / 2, y2);
        cur->bottomLeft = buildTree(grid, x1 + (x2 - x1) / 2 + 1, y1, x2, y1 + (y2 - y1) / 2);
        cur->bottomRight = buildTree(grid, x1 + (x2 - x1) / 2 + 1, y1 + (y2 - y1) / 2 + 1, x2, y2);
        return cur;
    }
    Node* construct(vector<vector<int>>& grid) {
        return buildTree(grid, 0, 0, grid.size() - 1, grid[0].size() - 1);
    }
};
```

按照题要求实现出来即可，没什么难度。不过代码很丑，一定是题的原因。

<div style="text-align: right">  2019/05/04 15:28  </div>

leetcode官方把这个题难度改成了中等，主要是递归，不过细节可能确实有点繁琐吧。
<div style="text-align: right">  2019/07/16 15:28  </div>