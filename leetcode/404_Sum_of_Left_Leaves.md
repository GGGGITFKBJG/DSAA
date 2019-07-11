### 404. 左叶子之和

> <div class="content__2ebE"><p>计算给定二叉树的所有左叶子之和。</p>
> 
> <p><strong>示例：</strong></p>
> 
> <pre>      3
>      / \
>     9  20
>    /  \ 
>   15   7
> 
> 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24</pre>
> 
> <p>&nbsp;</p> </div>

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
    void getSum(TreeNode* root, int& sum) {
        if(root == nullptr) return;
        if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) sum += root->left->val;
        getSum(root->left, sum);
        getSum(root->right, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        getSum(root, sum);
        return sum;
    }
};
```

这道题一开始我理解错了题目的意思，题上的 ”左叶子“ 原意为所有位于左子树上的叶子结点。我第一眼当成了每层最左边的叶子结点，想到了层序遍历，使用两个队列，遇到每层最左边的叶子时就将它记录下来。看懂题目原来意思之后，那就简单多了，常规的先序遍历。

<div style="text-align: right">  2019/05/03 21:53  </div>