### 653. 两数之和 IV - 输入 BST

> <div class="content__2ebE"><p>给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。</p>
> 
> <p><strong>案例 1:</strong></p>
> 
> <pre><strong>输入:</strong> 
>     5
>    / \
>   3   6
>  / \   \
> 2   4   7
> 
> Target = 9
> 
> <strong>输出:</strong> True
> </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>案例 2:</strong></p>
> 
> <pre><strong>输入:</strong> 
>     5
>    / \
>   3   6
>  / \   \
> 2   4   7
> 
> Target = 28
> 
> <strong>输出:</strong> False
> </pre>
> 
> <p>&nbsp;</p>
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
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(findTarget(root->left, k)) return true;
        if(us.count(root->val)) return true;
        us.insert(k - root->val);
        if(findTarget(root->right, k)) return true;
        return false;
    }
private:
    unordered_set<int> us;
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
    void build(TreeNode* root) {
        if(!root) return;
        build(root->left);
        rec.push_back(root->val);
        build(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        build(root);
        int i = 0, j = rec.size() - 1;
        while(i < j) {
            if(rec[i] + rec[j] == k) return true;
            else if(rec[i] + rec[j] > k) j--;
            else if(rec[i] + rec[j] < k) i++;
        }
        return false;
    }
    
private:
    vector<int> rec;
};
```

解法一

和第1题思路完全一样，只不过这个是遍历的树。采用哪种遍历方式都可以，这里我们采用了中序遍历。

解法二

解法一没有用到二叉搜索树的有序性质，这里我们就先用中序遍历构建一个有序数组，再使用双指针法寻找数对，这个思路以前在有一道题里面也见过。但是看起来这个修改并没有让程序性能多大的提高，甚至比解法一要更慢一些。

<div style="text-align: right"> 2019/06/14 20:38 </div>