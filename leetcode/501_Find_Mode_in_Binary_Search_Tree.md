### 501. 二叉搜索树中的众数
> <div class="content__2ebE"><div><p>给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。</p>
> 
> <p>假定 BST 有如下定义：</p>
> 
> <ul>
> 	<li>结点左子树中所含结点的值小于等于当前结点的值</li>
> 	<li>结点右子树中所含结点的值大于等于当前结点的值</li>
> 	<li>左子树和右子树都是二叉搜索树</li>
> </ul>
> 
> <p>例如：<br>
> 给定 BST <code>[1,null,2,2]</code>,</p>
> 
> <pre>   1
>     \
>      2
>     /
>    2
> </pre>
> 
> <p><code>返回[2]</code>.</p>
> 
> <p><strong>提示</strong>：如果众数超过1个，不需考虑输出顺序</p>
> 
> <p><strong>进阶：</strong>你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）</p>
> </div></div>

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
    void count(TreeNode* root) {
        if(root == nullptr) return;
        ++um[root->val];
        count(root->left);
        count(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        count(root);
        int max = INT_MIN;
        vector<int> res;
        for(auto it = um.begin(); it != um.end(); it++) {
            if(it->second > max) max = it->second;
        }
        for(auto it = um.begin(); it != um.end(); it++) {
            if(it->second == max) res.push_back(it->first);
        }
        return res;
    }
private:
    unordered_map<int, int> um;
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
    void findMode(TreeNode* root, int& max, int& lastVal, int& count) {
        if(root == nullptr) return;
        findMode(root->left, max, lastVal, count);
        count = root->val == lastVal ? count + 1 : 1;//更新计数
        if(count > max) {
            res.clear();
            res.push_back(root->val);
            max = count;
        }
        else if(count == max) {
            res.push_back(root->val);
        }
        lastVal = root->val;
        findMode(root->right, max, lastVal, count);
    }
    vector<int> findMode(TreeNode* root) {
        int max = 0, lastVal = -1, count = 0;
        findMode(root, max, lastVal, count);
        return res;
    }
private:
    vector<int> res;
};
```

解法一

暴力解法，遍历整个数，用一个map对所有出现的数字计数，然后再遍历map，找出最多的数字，并输出。

解法二

题上要求不使用额外空间，解法一明显是不满足要求的。那要怎么做呢？

如果此题的**二叉树**的条件改为**有序数组**，此题应该会容易得多：很容易想到，
1. 使用一个变量max记录出现过的最多元素的个数，一个变量count对当前遍历的元素计数；
2. 如果计数count大于max，就把原最大元素替换为当前元素（清空res并存入当前元素）；若等于，直接追加当前元素；若小于则继续向后遍历。
3. 最终得到的res即为所求。

由于搜索树的性质，我们使用中序遍历，恰好能得到一个由小到大的序列，所以就可以按上述思路实施了。
<div style="text-align: right"> 2019/05/15 17:26 </div>