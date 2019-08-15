### 538. 把二叉搜索树转换为累加树

> <div class="content__2ebE"><p>给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。</p>
> 
> <p><strong>例如：</strong></p>
> 
> <pre><strong>输入:</strong> 二叉搜索树:
>               5
>             /   \
>            2     13
> 
> <strong>输出:</strong> 转换为累加树:
>              18
>             /   \
>           20     13
> </pre>
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
    void getSumOrConvert(TreeNode* root, int& sum, bool isFirst) {
        if(!root) return;
        getSumOrConvert(root->left, sum, isFirst);
        if(isFirst) sum += root->val;
        else {
            sum -= root->val;
            root->val += sum;
        }
        getSumOrConvert(root->right, sum, isFirst);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        getSumOrConvert(root, sum, true);
        getSumOrConvert(root, sum, false);
        return root;
    }
};
```

解法二
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
    void convert(TreeNode* root, int& sum) {
        if(!root) return;
        convert(root->right, sum);
        sum += root->val;
        root->val = sum;
        convert(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convert(root, sum);
        return root;
    }
};
```

解法一

正常思种，用中序遍历两次，第一次求所有结点值的和，第二次为每个结点更新值。使用标记isFirst判断当前遍历是第一次还是第二次。

解法二

同样可以使用中序遍历，但是是以“右子树-根结点-左子树”的顺序，这样可以只遍历一次完成这个任务。

<div style="text-align: right"> 2019/05/31 15:54 </div>