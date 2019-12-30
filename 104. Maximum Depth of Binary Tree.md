### 104. 二叉树的最大深度

> <div class="content__2ebE"><p>给定一个二叉树，找出其最大深度。</p>
> 
> <p>二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。</p>
> 
> <p><strong>说明:</strong>&nbsp;叶子节点是指没有子节点的节点。</p>
> 
> <p><strong>示例：</strong><br> 给定二叉树
> <code>[3,9,20,null,null,15,7]</code>，</p>
> 
> <pre>             3   
>             / \   
>            9  20
>              /  \    
>             15   7</pre>
> 
> <p>返回它的最大深度&nbsp;3 。</p> </div>

解法一
```cpp
//时间复杂度O(n), 平均空间复杂度O(logn), 最坏空间复杂度O(n), n是树的节点数
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftDepth = maxDepth(root->left);//左子树的深度
        int rightDepth = maxDepth(root->right);//右子树的深度
        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;//根深
    }
};
```

解法二
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int depth = 0;
        while(!q.empty()) {
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            if(temp.first == nullptr) continue;
            if(depth < temp.second) depth = temp.second;
            q.push( {temp.first->left, temp.second + 1} );
            q.push( {temp.first->right, temp.second + 1} );
        }
        return depth;
    }
};
```

解法一，采用后序遍历。
解法二，层序遍历。

 <div style="text-align: right">  2019/04/22 19:55  </div>