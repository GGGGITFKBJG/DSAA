### 235. 二叉搜索树的最近公共祖先

> <div class="content__2ebE"><p>给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。</p>
> 
> <p><a
> href="https://baike.baidu.com/item/%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/8918834?fr=aladdin">百度百科</a>中最近公共祖先的定义为：“对于有根树
> T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
> 的深度尽可能大（<strong>一个节点也可以是它自己的祖先</strong>）。”</p>
> 
> <p>例如，给定如下二叉搜索树:&nbsp; root =&nbsp;[6,2,8,0,4,7,9,null,null,3,5]</p>
> 
> <p><img style="height: 190px; width: 200px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/binarysearchtree_improved.png"
> alt=""></p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8 <strong>
> 输出:</strong> 6  <strong>
> 解释: </strong>节点 2和节点 8的最近公共祖先是 6。 </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4 <strong>
> 输出:</strong> 2 <strong>
> 解释: </strong>节点 2 和节点 4 的最近公共祖先是2, 因为根据定义最近公共祖先节点可以为节点本身。</pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>说明:</strong></p>
> 
> <ul> 	<li>所有节点的值都是唯一的。</li> 	<li>p、q 为不同节点且均存在于给定的二叉搜索树中。</li> </ul>
> </div></div>

解法一
```cpp
//时间复杂度O(logn), 空间复杂度O(logn), n是树结点个数
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val || root->val == q->val ||//p, q其中一个是根结点
           p->val < root->val && q->val > root->val ||//p, q分布在根结两侧
           p->val > root->val && q->val < root->val) return root;
        TreeNode* res;
        if(p->val < root->val && q->val < root->val) {//p, q都在左子树
            res = lowestCommonAncestor(root->left, p, q);
        }
        else {//p, q都在右子树
            res = lowestCommonAncestor(root->right, p, q);
        }
        return res;
    }
};
```

利用二叉搜索树的排序性质，可以分几种情况：
1. p、q分布在root的左、右子树，这种情况直接返回root；
2. p、q至少一个等于root，这时也直接返回root；
3. p、q分布在root的同侧（都在左子树或都在右子树），这时递归地搜索该子树；
4. 题目上说结点值唯一且必定有解，所以不考虑找不到的情况（不用处理叶子结点）。
        
<div style="text-align: right"> 2019/04/29 00:12 </div>
