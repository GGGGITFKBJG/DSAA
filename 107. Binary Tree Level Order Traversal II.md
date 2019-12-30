### 107. 二叉树的层次遍历 II

> <div class="content__2ebE"><p>给定一个二叉树，返回其节点值自底向上的层次遍历。
> （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）</p>
> 
> <p>例如：<br> 给定二叉树 <code>[3,9,20,null,null,15,7]</code>,</p>
> 
> <pre>    3 
>    / \ 
>   9  20
>      /  \
>     15   7 </pre>
> 
> <p>返回其自底向上的层次遍历为：</p>
> 
> <pre>[   
>    [15,7],  
>    [9,20],  
>    [3] 
> ] </pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n), n是树的节点数
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> tq;
        tq.push({root, 0});//节点指针, 层数 - 1
        while(!tq.empty()) {
            auto temp = tq.front();
            tq.pop();
            if(temp.first == nullptr) continue;
            int a = temp.first->val;
            if(temp.second == res.size()) res.push_back(vector<int>());
            res[temp.second].push_back(temp.first->val);
            tq.push({temp.first->left, temp.second + 1});
            tq.push({temp.first->right, temp.second + 1});
        }
        for(int i = 0, j = res.size() - 1; i < j; i++, j--) {
            res[i].swap(res[j]);
        }
        return res;
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
    void levelOrder(TreeNode* root, int level, vector<vector<int>>& res) {
        if(root == nullptr) return;
        if(level - 1 == res.size()) res.push_back({});
        res[level - 1].push_back(root->val);
        levelOrder(root->left, level + 1, res);
        levelOrder(root->right, level + 1, res);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root, 1, res);
        return vector<vector<int>>(res.rbegin(), res.rend());
    }
};
```

解法一
层序遍历（BFS）。使用一个队列保存了结点指针和节点层数（层数也可以不存，用状态变量来判断是否到达下一层）。层序遍历结束之后，反转结果数组（也可以不反转，保存的时候对数组进行头插）；也可以使用一个栈来保存每一层的结果，最后依次出栈构建出正确顺序的结果，不过个人觉得这么做好像并没有太大的好处，没有必要；

解法二
递归解（DFS）。其解的存储方式与解法一类似，使用递归省去了保存结点的层数，且不需要使用队列；它的思路是：
1. 维护一个二维数组res，其行数即代表树的层数，每一列代表该行中自左向右的元素；
2. 采用先序遍历（DFS），遍历到某一结点时，它能从上一层传进的参数level那里得知自己的层数，就将结点值推入相应层的数组；
3. 对于不同层的结点，它们存入res的顺序很混乱（有规律，但是对我们不重要）；对于同一层的结点，左侧的结点总是比右侧的结点先被存入res，这便保证了每一层的元素是自左向右有序排列的；
4. 我们事先不知道树的大小，所以res在运行过程中动态增长，当层数大于res的行数时，我们就为res开辟新的层；
5. 遍历结束，res反序后即是正确结果。
 
  <div style="text-align: right">  2019/04/22 23:18  </div>