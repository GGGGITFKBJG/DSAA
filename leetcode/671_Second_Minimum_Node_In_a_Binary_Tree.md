### 671. 二叉树中第二小的节点

> <div class="content__2ebE"><p>给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为&nbsp;<code>2</code>&nbsp;或&nbsp;<code>0</code>。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。&nbsp;</p>
> 
> <p>给出这样的一个二叉树，你需要输出所有节点中的<strong>第二小的值。</strong>如果第二小的值不存在的话，输出 -1 <strong>。</strong></p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> 
>     2
>    / \
>   2   5
>      / \
>     5   7
> 
> <strong>输出:</strong> 5
> <strong>说明:</strong> 最小的值是 2 ，第二小的值是 5 。
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> 
>     2
>    / \
>   2   2
> 
> <strong>输出:</strong> -1
> <strong>说明:</strong> 最小的值是 2, 但是不存在第二小的值。
> </pre>
> </div>

解法一
```cpp
//时间复杂度O(nlogn), 空间复杂度O(logn)
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
    int pcldown(TreeNode*& root) {
        if(!root) return -1;
        int ret = root->val;
        
        if(!root->left && !root->right) {
            root = nullptr;
            return ret;
        }
        else if(!root->left && root->right) {
            root->val = root->right->val;
            pcldown(root->right);
        }
        else if(root->left && !root->right) {
            root->val = root->left->val;
            pcldown(root->left);
        }
        else {
            int vl = root->left->val;
            int vr = root->right->val;
            if(vl < vr) {
                root->val = vl;
                pcldown(root->left);
            }
            else {
                root->val = vr;
                pcldown(root->right);
            }
        }

        return ret;
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int last = pcldown(root), rec;
        while((rec = pcldown(root)) == last);
        return rec;
    }
};
```

解法二
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
    int find(TreeNode* root, int last) {
        if(!root) return -1;
        if(root->val > last) return root->val;
        int vl = find(root->left, last);
        int vr = find(root->right, last);
        return vl == -1 || vr == -1 ? max(vl, vr) : min(vl, vr);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        int last = root->val;
        return find(root, last);
    }
};
```
解法一

这个特殊的树有如下性质：

对于该树的每一个结点，它的结点值不大于其子结点（如果有的话）值。

有一种数据结构叫***堆***，函数pcldown与堆的DeleteMin操作类似：每次调用pcldown，就将树的根结点值挖走，用其较小的子结点作填充；然后递归地对其用来填充的子结点作相同的下滤操作，直到遇到子结点为空。

主函数反复地对树进行pcldown操作，直到挖出的值不等于第一个值last，返回即可。

解法二

上面的解法华而不实。解法二是常规的先序遍历，如果遇到了比last大的元素就直接返回；否则就在左、右子树中寻找，比较后返回。

<div style="text-align: right"> 2019/06/17 23:08 </div>