### 101. 对称二叉树

> <div class="content__2ebE"><p>给定一个二叉树，检查它是否是镜像对称的。</p>
> 
> <p>例如，二叉树&nbsp;<code>[1,2,2,3,4,4,3]</code> 是对称的。</p>
> 
> <pre>    1    / \   2   2  / \ / \ 3  4 4  3 </pre>
> 
> <p>但是下面这个&nbsp;<code>[1,2,2,null,3,null,3]</code> 则不是镜像对称的:</p>
> 
> <pre>    1    / \   2   2    \   \    3    3 </pre>
> 
> <p><strong>说明:</strong></p>
> 
> <p>如果你可以运用递归和迭代两种方法解决这个问题，会很加分。</p> </div>

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
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr) return false;

        if(left->val != right->val) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> tq;
        tq.push(root);
        tq.push(root);
        while(!tq.empty()) {
            TreeNode *t1 = tq.front();
            tq.pop();
            TreeNode *t2 = tq.front();
            tq.pop();
            if(t1 == nullptr && t2 == nullptr) continue;
            if(t1 == nullptr || t2 == nullptr) return false;
            if(t1->val != t2->val) return false;
            tq.push(t1->left);
            tq.push(t2->right);
            tq.push(t1->right);
            tq.push(t2->left);
        }
        return true;
    }
};
```

解法一采用先序遍历(DFS)，与100题类似。
解法二采用层序遍历(BFS)，需要用到一个额外的队列。与单棵树的层序遍历不同的是，该队列一次性入队4个结点（除了根结点），一次性出队两个结点，并比较是否相等。

 <div style="text-align: right">  2019/04/22 13:34  </div>