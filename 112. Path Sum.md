### 112. 路径总和

> <div
> class="content__2ebE"><p>给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。</p>
> 
> <p><strong>说明:</strong>&nbsp;叶子节点是指没有子节点的节点。</p>
> 
> <p><strong>示例:</strong>&nbsp;<br> 给定如下二叉树，以及目标和 <code>sum =
> 22</code>，</p>
> 
> <pre>              <strong>5</strong>
>              / \
>             <strong>4 </strong>  8
>            /   / \
>           <strong>11 </strong> 13  4
>          /  \      \
>         7    <strong>2</strong>      1 </pre>
> 
> <p>返回 <code>true</code>, 因为存在目标和为 22 的根节点到叶子节点的路径
> <code>5-&gt;4-&gt;11-&gt;2</code>。</p> </div>

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
    bool hasPathSum(TreeNode* root, int sum) { 
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr) {//是叶子结点
            if(sum == root->val) return true;//找到
            return false;//未找到
        }
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};
```

思路：
1. 采用先序遍历，访问每个结点；
2. 对于每个叶子结点，比较目标值sum与当前结点值是否一样，一样则返回true，否则为false；
3. 对于非叶子结点，将目标值设为sum - val，查找其子结点。

   <div style="text-align: right">  2019/04/23 10:21 </div>