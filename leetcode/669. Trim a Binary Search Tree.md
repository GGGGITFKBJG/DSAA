### 669. 修剪二叉搜索树

> <div class="content__2ebE"><p>给定一个二叉搜索树，同时给定最小边界<code>L</code>&nbsp;和最大边界&nbsp;<code>R</code>。通过修剪二叉搜索树，使得所有节点的值在<code>[L, R]</code>中 (R&gt;=L) 。你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> 
>     1
>    / \
>   0   2
> 
>   L = 1
>   R = 2
> 
> <strong>输出:</strong> 
>     1
>       \
>        2
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> 
>     3
>    / \
>   0   4
>    \
>     2
>    /
>   1
> 
>   L = 1
>   R = 3
> 
> <strong>输出:</strong> 
>       3
>      / 
>    2   
>   /
>  1
> </pre>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(logn)
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
    void trim(TreeNode*& root, int L, int R) {
        while(root && ((root->val < L) || (root->val > R))) {
            if(root->val < L) root = root->right;
            else root = root->left;
        }
        if(!root) return;
        trim(root->left, L, R);
        trim(root->right, L, R);
    }
    
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        trim(root, L, R);
        return root;
    }
};
```

递归法，在递归过程中，利用二叉搜索树排序的性质，可以分为三种情况：
1. 当前结点值小于L，说明当前结点及其左子树都不满足要求，需要剪去，此时我们单纯地将当前指针指向右子结点；
2. 当前结点值大于R，说明当前结点及其右子树都不满足要求，需要剪去，此时我们单纯地将当前指针指向左子结点；
3. 当前结点值大于等于L且小于等于R，此时是满足条件的，我们递归地对左、右子树进行同样的剪裁。

<div style="text-align: right"> 2019/06/17 21:19 </div>