### 617. 合并二叉树

> <div class="content__2ebE"><p>给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。</p>
> 
> <p>你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则<strong>不为&nbsp;</strong>NULL 的节点将直接作为新二叉树的节点。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> 
> 	Tree 1                     Tree 2                  
>           1                         2                             
>          / \                       / \                            
>         3   2                     1   3                        
>        /                           \   \                      
>       5                             4   7                  
> <strong>输出:</strong> 
> 合并后的树:
> 	     3
> 	    / \
> 	   4   5
> 	  / \   \ 
> 	 5   4   7
> </pre>
> 
> <p><strong>注意:</strong>&nbsp;合并必须从两个树的根节点开始。</p>
> </div>

解法一
```cpp
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t2) return t1;//t2为空
        if(!t1) return t2;
        
        //t1, t2都非空
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        
        return t1;
    }
};
```

思路：

先序遍历合并两树的每一个节点，返回合并后的子树的根结点，终止条件为其中一个为空，分4种情况：
1. t1为空，t2非空，此时直接返回t2；
2. t1为空，t2为空，此时返回t1（空）；
3. t1非空，t2为空，此时返回t1（非空）；
4. t1非空，t2非空，此时将t1的值加上t2的值，返回t1。

<div style="text-align: right"> 2019/06/10 11:44 </div>