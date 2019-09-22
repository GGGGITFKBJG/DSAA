### 687. 最长同值路径

> <div class="content__2ebE"><p>给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。</p>
> 
> <p><strong>注意</strong>：两个节点之间的路径长度由它们之间的边数表示。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <p>输入:</p>
> 
> <pre>              5
>              / \
>             4   5
>            / \   \
>           1   1   5
> </pre>
> 
> <p>输出:</p>
> 
> <pre>2
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <p>输入:</p>
> 
> <pre>              1
>              / \
>             4   5
>            / \   \
>           4   4   5
> </pre>
> 
> <p>输出:</p>
> 
> <pre>2
> </pre>
> 
> <p><strong>注意:</strong> 给定的二叉树不超过10000个结点。&nbsp;树的高度不超过1000。</p>
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
    int find(TreeNode* root) {
        if(!root) return 0;
        int pl = find(root->left);
        int pr = find(root->right);
        int count = 0, pathLen = 0;
        if(root->left && root->right) {
            int vl = root->left->val, vr = root->right->val, vm = root->val;
            count = max(vl == vm ? pl + 1 : 0, vr == vm ? pr + 1 : 0);
            if(vl == vm && vl == vr) pathLen = pl + pr + 2;
        }
        else if(root->left && !root->right) {
            count = root->left->val == root->val ? pl + 1 : 0;
        }
        else if(!root->left && root->right) {
            count = root->right->val == root->val ? pr + 1 : 0;
        }
        res = max(res, max(count, pathLen));
        return count;
    }
    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        find(root);
        return res;
    }
private:
    int res;
};
```

思路：

此题解法和之前求树高的题目类似，只不过不再是单纯地对树高求和，中间要加一些条件，需要满足条件的父子结点才能计数。

函数find(root)采用先序遍历，返回值count是***从当前根结点root出发***的最长同值路径长。所以在遍历过程中有几种情况：
1. 当前根结点root的左、右子树都为空。此时count为0；
2. 左、右子树有其一为空。此时可分两种情况：
<pre>① 非空子结点值等于根结点值。此时count为find(root->left) + 1；
② 非空子结点值不等于根结点值。此时count为0；</pre>
3. 左、右子树都非空。此时可分3种情况：
<pre>
①左子结点值右子结点值都等于根结点值，此时count为 1 + max(find(root->left), find(root->right));
②左、右子结点值有其一等于根结点值，此时count为 1 + find(子结点值等于根结点值的那个子树)；
③左、右子结点值都不等于根结点值，此时count为0。
</pre>

以上的find函数只是返回了从根结点出发的最长同值路径长，而题目要求路径不一定要以根结点为出发点（就是说可以穿过根结点），所以需要一个变量pathLen，计录遍历过程中穿过当前根结点的最长同值路径长。

还好这一改动并不复杂，第1、2种情况（左、右子树至少有一个为空）里，pathLen都等于count。

对于第3种情况（左、右子树都非空），在其分类②、③中，pathLen也直接等于count。在分类①中，需要使pathLen等于左、右子树的最长同值路径长之和再加2，也就是pathLen = find(root->left) + find(root->rigfht) + 2。

使用res记录pathLen出现过的最大值即可。

思路理顺很好理解，就是条件太多，代码不好看。

<div style="text-align: right"> 2019/06/20 23:36 </div>