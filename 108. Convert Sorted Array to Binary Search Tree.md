### 108. 将有序数组转换为二叉搜索树

> <div class="content__2ebE"><p>将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。</p>
> 
> <p>本题中，一个高度平衡二叉树是指一个二叉树<em>每个节点&nbsp;</em>的左右两个子树的高度差的绝对值不超过 1。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre>给定有序数组: [-10,-3,0,5,9],
> 
> 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
> 
>          0
>         / \
>       -3   9
>       /   /
>     -10  5 </pre> </div>

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
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if(left == right) return new TreeNode(nums[left]);
        if(left > right) return nullptr;
        
        TreeNode *p = new TreeNode(nums[left + (right - left) / 2]);
        p->left = buildBST(nums, left, left + (right - left) / 2 - 1);
        p->right = buildBST(nums, left + (right - left) / 2 + 1, right);
        return p;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};
```

中序遍历的逆过程，取数组中点作为根结点，中点左边的值作为左子树，分别递归地构建左子树和右子树。
 
  <div style="text-align: right">   2019/04/22 23:22 </div>