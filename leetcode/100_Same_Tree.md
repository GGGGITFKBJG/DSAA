### 100. 相同的树
> <div class="content__2ebE"><p>给定两个二叉树，编写一个函数来检验它们是否相同。</p>
> 
> <p>如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入: </strong>      1         1
>           / \       / \
>          2   3     2   3
> 
>         [1,2,3],   [1,2,3]
> 
> <strong>输出:</strong> true</pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:  </strong>    1          1
>           /           \
>          2             2
> 
>         [1,2],     [1,null,2]
> 
> <strong>输出:</strong> false </pre>
> 
> <p><strong>示例&nbsp;3:</strong></p>
> 
> <pre><strong>输入:</strong>       1         1
>           / \       / \
>          2   1     1   2
> 
>         [1,2,1],   [1,1,2]
> 
> <strong>输出:</strong> false </pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n), n是树的节点数
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;
        
        return p->val == q->val &&
               isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right);
    }
};
```

此题很简单。先序遍历：递归地遍历两棵树，先比较根结点，再比较左子树、右子树。
  
<div style="text-align: right"> 2019/04/22 12:08 </div>