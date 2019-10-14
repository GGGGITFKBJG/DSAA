### 111. 二叉树的最小深度

> <div class="content__2ebE"><p>给定一个二叉树，找出其最小深度。</p>
> 
> <p>最小深度是从根节点到最近叶子节点的最短路径上的节点数量。</p>
> 
> <p><strong>说明:</strong>&nbsp;叶子节点是指没有子节点的节点。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <p>给定二叉树&nbsp;<code>[3,9,20,null,null,15,7]</code>,</p>
> 
> <pre>         3
>         / \
>        9  20
>          /  \
>         15   7</pre>
> 
> <p>返回它的最小深度 &nbsp;2.</p> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int dl = minDepth(root->left);
        int dr = minDepth(root->right);
        if(dl == 0) return dr + 1;//左子树为空, 返回右子树的深度
        if(dr == 0) return dl + 1;//右子树为空, 返回左子树的深度
        return dl < dr ? dl + 1 : dr + 1;//都不为空, 返回较小者
    }
};
```

  此题有个陷阱。乍一看好像跟平常的计算最大深度差不多，只是递归返回左、右子树较小的深度。但是深度定义为根结点到叶子结点的结点数。如果结点有一个子树为空，它的深度应该是另一棵子树的深，而不是1（如按照前述算法计算会得到1）。这样想通了，加两条判断子树为空的语句，解决。思路：
1. 如果结点的左、右子树都为空，它的最小深度为1；
2. 如果结点的左、右子树其一为空，它的最小深度为非空子树的最小深度；
3. 如果结点的左、右子树都非空，它的最小深度为左、右子树最小深度的较小者。

<div style="text-align: right"> 2019/04/23 09:24  </div>