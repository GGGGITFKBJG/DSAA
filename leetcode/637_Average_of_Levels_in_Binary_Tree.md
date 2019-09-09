### 637. 二叉树的层平均值

> <div class="content__2ebE"><p>给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong>
>     3
>    / \
>   9  20
>     /  \
>    15   7
> <strong>输出:</strong> [3, 14.5, 11]
> <strong>解释:</strong>
> 第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
> </pre>
> 
> <p><strong>注意：</strong></p>
> 
> <ol>
> 	<li>节点值的范围在32位有符号整数范围内。</li>
> </ol>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q1;
        q1.push(root);
        while(!q1.empty()) {
            queue<TreeNode*> q2;
            q2.swap(q1);
            long sum = 0, n = 0;
            while(!q2.empty()) {
                TreeNode* temp = q2.front();
                q2.pop();
                sum += temp->val;
                n++;
                if(temp->left) q1.push(temp->left);
                if(temp->right) q1.push(temp->right);
            }
            res.push_back((double)sum / n);
        }
        return res;
    }
};
```

层序遍历。为了区分层次，使用两个队列。q1记录上一层结点，每次循环把q1给q2，清空q1，遍历q2时把其个数及和记录，q2空时说明当前层遍历结束，开始下一层。

<div style="text-align: right"> 2019/06/13 20:45 </div>