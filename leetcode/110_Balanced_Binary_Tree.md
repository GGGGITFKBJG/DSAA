### 110. 平衡二叉树

> <div class="content__2ebE"><p>给定一个二叉树，判断它是否是高度平衡的二叉树。</p>
> 
> <p>本题中，一棵高度平衡二叉树定义为：</p>
> 
> <blockquote> <p>一个二叉树<em>每个节点&nbsp;</em>的左右两个子树的高度差的绝对值不超过1。</p>
> </blockquote>
> 
> <p><strong>示例 1:</strong></p>
> 
> <p>给定二叉树 <code>[3,9,20,null,null,15,7]</code></p>
> 
> <pre>     3
>     / \
>    9   20
>       /  \
>      15   7</pre>
> 
> <p>返回 <code>true</code> 。<br> <br> <strong>示例 2:</strong></p>
> 
> <p>给定二叉树 <code>[1,2,2,3,3,null,null,4,4]</code></p>
> 
> <pre>       1
>       / \
>      2   2
>     / \
>    3   3
>   / \
>  4   4 </pre>
> 
> <p>返回&nbsp;<code>false</code> 。</p> </div>

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
    bool isBalanced(TreeNode* p, int& height) {
        if(p == nullptr) {
            height = 0;
            return true;
        }
        
        int hl, hr;
        if(!isBalanced(p->left, hl)) return false;
        if(!isBalanced(p->right, hr)) return false;
        if(abs(hl - hr) > 1) return false;
        height = (hl > hr ? hl : hr) + 1;
        return true;
    }
    bool isBalanced(TreeNode* root) {
        int h;
        return isBalanced(root, h);
    }
};
```

解法二
```cpp
//优化解法一
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //从层序遍历的数组, 生成树的函数
 //TreeNode* makeTree(vector<int>& a) {
//	queue<TreeNode*> q;
//	TreeNode* root = new TreeNode(a[0]);
//	q.push(root);
//	int i = 1;
//	while (i < a.size()) {
//		TreeNode* temp = q.front();
//		q.pop();
//		if (a[i] != -1) {
//			temp->left = new TreeNode(a[i]);
//			q.push(temp->left);
//		}
//		i++;
//		if (i < a.size()) {
//			if (a[i] != -1) {
//				temp->right = new TreeNode(a[i]);
//				q.push(temp->right);
//			}
//			i++;
//		}
//	}
//	return root;
//}
 
class Solution {
public:
    int isBalanced_int(TreeNode* p) {//返回结点p的高, -1代表不平衡
        if(p == nullptr) return 0;
        
        int hl = isBalanced_int(p->left);//左子树高
        int hr = isBalanced_int(p->right);//右子树高
        if(hl == -1 || hr == -1 || abs(hl - hr) > 1) return -1;//左或右子树、或根结点不平衡
        return (hl > hr ? hl : hr) + 1;//当前根结点高
    }
    bool isBalanced(TreeNode* root) {
        return isBalanced_int(root) != -1;
    }
};
```

计算树高的同时判断是否平衡。

  <div style="text-align: right">  2019/04/23 01:14 </div>