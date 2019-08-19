### 559. N叉树的最大深度

> <div class="content__2ebE"><p>给定一个 N 叉树，找到其最大深度。</p>
> 
> <p>最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。</p>
> 
> <p>例如，给定一个&nbsp;<code>3叉树</code>&nbsp;:</p>
> 
> <p>&nbsp;</p>
> 
> <p><img style="width: 100%; max-width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/narytreeexample.png"></p>
> 
> <p>&nbsp;</p>
> 
> <p>我们应返回其最大深度，3。</p>
> 
> <p><strong>说明:</strong></p>
> 
> <ol>
> 	<li>树的深度不会超过&nbsp;<code>1000</code>。</li>
> 	<li>树的节点总不会超过&nbsp;<code>5000</code>。</li>
> </ol></div>

解法一
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int max = 0;
        vector<int> depths(root->children.size());//子树深度
        for(int i = 0; i < depths.size(); i++) {
            depths[i] = maxDepth(root->children[i]);//记录
        }
        for(int depth : depths) {//找出子树中最大的深度
            if(depth > max) max = depth;
        }
        return max + 1;//当前树深度为子树深度加1
    }
};
```

思路：

1. 先序遍历，跟二叉树求深度思路相同，先对每棵子树求深度，对于父结点为根的树，它的深为子树的深加1。
2. 唯一的区别在于，N叉树的子树数目是不确定的，需要使用动态分配的空间来记录。
3. 也可以使用层序遍历，不过需要额外的栈，没有必要。

<div style="text-align: right"> 2019/06/1 18:39 </div>