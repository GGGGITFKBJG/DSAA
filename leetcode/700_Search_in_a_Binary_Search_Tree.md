### 700. 二叉搜索树中的搜索

> <div class="content__2ebE"><p>给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。</p>
> 
> <p>例如，</p>
> 
> <pre>给定二叉搜索树:
> 
>         4
>        / \
>       2   7
>      / \
>     1   3
> 
> 和值: 2
> </pre>
> 
> <p>你应该返回如下子树:</p>
> 
> <pre>      2     
>      / \   
>     1   3
> </pre>
> 
> <p>在上述示例中，如果要找的值是 <code>5</code>，但因为没有节点值为 <code>5</code>，我们应该返回 <code>NULL</code>。</p>
> </div>

解法一
```cpp
//时间复杂度O(logn), 空间复杂度O(logn)
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return nullptr;
        if(val == root->val) return root;
        if(val > root->val) return searchBST(root->right, val);
        return searchBST(root->left, val);
    }
};
```

思路很明显，如果当前结点值等于val，直接返回root；
如果当前结点值大于val，就去左子树中找；否则去右子树中找；找不到返回null。

<div style="text-align: right"> 2019/06/23 14:27 </div>