### 563. 二叉树的坡度

> <div class="content__2ebE"><p>给定一个二叉树，计算<strong>整个树</strong>的坡度。</p>
> 
> <p>一个树的<strong>节点的坡度</strong>定义即为，该节点左子树的结点之和和右子树结点之和的<strong>差的绝对值</strong>。空结点的的坡度是0。</p>
> 
> <p><strong>整个树</strong>的坡度就是其所有节点的坡度之和。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> 
>          1
>        /   \
>       2     3
> <strong>输出:</strong> 1
> <strong>解释:</strong> 
> 结点的坡度 2 : 0
> 结点的坡度 3 : 0
> 结点的坡度 1 : |2-3| = 1
> 树的坡度 : 0 + 0 + 1 = 1
> </pre>
> 
> <p><strong>注意:</strong></p>
> 
> <ol>
> 	<li>任何子树的结点的和不会超过32位整数的范围。</li>
> 	<li>坡度的值不会超过32位整数的范围。</li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
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
    int getTilt(TreeNode* root, int& tilt) {
        if(!root) return 0;
        int suml = getTilt(root->left, tilt);
        int sumr = getTilt(root->right, tilt);
        tilt += abs(suml - sumr);
        return suml + sumr + root->val;
    }
    
    int findTilt(TreeNode* root) {
        int tilt = 0;
        getTilt(root, tilt);
        return tilt;
    }
};
```

思路：

后序遍历，函数getTilt返回值为树结点值的和，求和过程中对变量tilt作累计求和，遍历完成后返回tilt。

<div style="text-align: right"> 2019/06/02 22:21 </div>