### 226. 翻转二叉树

> <div class="content__2ebE"><p>翻转一棵二叉树。</p>
> 
> <p><strong>示例：</strong></p>
> 
> <p>输入：</p>
> 
> <pre>       4
>      /   \   
>     2     7  
>    / \   / \ 
>   1   3 6   9</pre>
> 
> <p>输出：</p>
> 
> <pre>       4  
>      /   \ 
>     7     2
>    / \   / \ 
>   9   6 3   1</pre>
> 
> <p><strong>备注:</strong><br> 这个问题是受到 <a
> href="https://twitter.com/mxcl">Max Howell </a>的 <a
> href="https://twitter.com/mxcl/status/608682016205344768">原问题</a> 启发的
> ：</p>
> 
> <blockquote>谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。</blockquote>
> </div>

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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        TreeNode* temp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(temp);
        return root;
    }
};
```

解法二
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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur == nullptr) continue;
            TreeNode* temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;
            q.push(cur->left);
            q.push(cur->right);
        }
        return root;
    }
};
```

解法一
递归法（后序遍历，DFS）。

解法二
迭带法（层序遍历，BFS）。

<div style="text-align: right"> 2019/04/28 21:01  </div>