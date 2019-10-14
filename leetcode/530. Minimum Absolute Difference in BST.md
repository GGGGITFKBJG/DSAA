### 530. 二叉搜索树的最小绝对差

> <div class="content__2ebE"><div><p>给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。</p>
> 
> <p><strong>示例 :</strong></p>
> 
> <pre><strong>输入:</strong>
> 
>    1
>     \
>      3
>     /
>    2
> 
> <strong>输出:</strong>
> 1
> 
> <strong>解释:
> </strong>最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
> </pre>
> 
> <p><strong>注意: </strong>树中至少有2个节点。</p>
> </div></div>

解法一
```cpp
//时间复杂度O(n^2), 空间复杂度O(n)
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
    void buildArray(TreeNode* root) {
        if(root == nullptr) return;
        rec.push_back(root->val);
        buildArray(root->left);
        buildArray(root->right);
    };
    int getMinimumDifference(TreeNode* root) {
        buildArray(root);
        int minAbs = INT_MAX;
        for(int i = 1; i < rec.size(); i++) {
            for(int j = 0; j < i; j++) {
                int diff = abs(rec[i] - rec[j]);
                if(diff < minAbs) minAbs = diff;
            }
        }
        return minAbs;
    }
    
private:
    vector<int> rec;
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
    void getMinDiff(TreeNode* root, int& minDiff, int& preVal) {//先前最小绝对值差, 上一个节点值
        if(root->left) getMinDiff(root->left, minDiff, preVal);//访问左子树
        if(preVal >= 0) minDiff = min(root->val - preVal, minDiff);//更新最小绝对值差
        preVal = root->val;//更新上一节点值
        if(root->right) getMinDiff(root->right, minDiff, preVal);//右子树
    }
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX, preVal = -1;
        getMinDiff(root, minDiff, preVal);//中序遍历
        return minDiff;
    }
};
```

解法一
暴力搜索，先遍历一次构建一个数组，再对数组进行双重遍历。这样没有用到BST的排序性质，需要二次的运行时间；

解法二
对BST进行中序遍历，会得到一个从小到大的序列，刚好相邻两个元素就可以用来求绝对值差。使用了变量minDiff记录出现过的最小绝对值差，使用变量preVal记录上一个元素的值。
要特别注意的是，序列中第一个节点没有preVal，所以preVal = -1代表它是最小元素，不需要更新minDiff。

<div style="text-align: right"> 2019/05/28 11:48 </div>