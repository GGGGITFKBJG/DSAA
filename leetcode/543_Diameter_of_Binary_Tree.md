### 543. 二叉树的直径

> <div class="content__2ebE"><p>给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。</p>
> 
> <p><strong>示例 :</strong><br>
> 给定二叉树</p>
> 
> <pre>          1
>          / \
>         2   3
>        / \     
>       4   5    
> </pre>
> 
> <p>返回&nbsp;<strong>3</strong>, 它的长度是路径 [4,2,1,3] 或者&nbsp;[5,2,1,3]。</p>
> 
> <p><strong>注意：</strong>两结点之间的路径长度是以它们之间边的数目表示。</p>
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
    int findLongestPath(TreeNode* root, int& max) {//返回树高(认为叶高为1)
        if(!root) return 0;
        int hl = findLongestPath(root->left, max);
        int hr = findLongestPath(root->right, max);
        if(hl + hr > max) max = hl + hr;
        return hl > hr ? hl + 1 : hr + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        findLongestPath(root, max);
        return max;
    }
};
```

思路：
对于一棵树，使得路径最长（即树的直径）的两个叶子，一定有一个共同的父结点，其最长路径长为该父结点左、右子树的高之和（认为叶子的高为1）。

那么我们只要遍历该树，对于每个结点，求其左、右子树高之和，并记录下最大值，这个最大值就是整棵树的直径。

1. 使用一个变量max记录每个子树直径的最大值，初始化为0；
2. 使用后序遍历，求出每个子树的高；
3. 遍历过程中，在父结点处，求出左、右子树的高之和（潜在的直径），与max比较，若比max大则更新max；
4. 遍历完成后，max就是树的直径。

<div style="text-align: right"> 2019/05/31 20:16 </div>