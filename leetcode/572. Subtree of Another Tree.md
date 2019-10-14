### 572. 另一个树的子树

> <div class="content__2ebE"><p>给定两个非空二叉树 <strong>s</strong> 和 <strong>t</strong>，检验&nbsp;<strong>s</strong> 中是否包含和 <strong>t</strong> 具有相同结构和节点值的子树。<strong>s</strong> 的一个子树包括 <strong>s</strong> 的一个节点和这个节点的所有子孙。<strong>s</strong> 也可以看做它自身的一棵子树。</p>
> 
> <p><strong>示例 1:</strong><br>
> 给定的树 s:</p>
> 
> <pre>     3
>     / \
>    4   5
>   / \
>  1   2
> </pre>
> 
> <p>给定的树 t：</p>
> 
> <pre>   4 
>   / \
>  1   2
> </pre>
> 
> <p>返回 <strong>true</strong>，因为 t 与 s 的一个子树拥有相同的结构和节点值。</p>
> 
> <p><strong>示例 2:</strong><br>
> 给定的树 s：</p>
> 
> <pre>     3
>     / \
>    4   5
>   / \
>  1   2
>     /
>    0
> </pre>
> 
> <p>给定的树 t：</p>
> 
> <pre>   4
>   / \
>  1   2
> </pre>
> 
> <p>返回 <strong>false</strong>。</p>
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
    bool comp(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s && t || s && !t) return false;
        if(s->val != t->val) return false;
        return comp(s->left, t->left) && comp(s->right, t->right);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s && t || s && !t) return false;
        if(comp(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
```

思路：

双重递归。主函数isSubtree递归地遍历s的每个结点，在遍历过程中，比较**以当前结点为根的树**与**树t**比较；函数comp则比较两个树是否完全相等。

<div style="text-align: right"> 2019/06/02 23:07 </div>