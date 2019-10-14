### 606. 根据二叉树创建字符串

> <div class="content__2ebE"><p>你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。</p>
> 
> <p>空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> 二叉树: [1,2,3,4]
>        1
>      /   \
>     2     3
>    /    
>   4     
> 
> <strong>输出:</strong> "1(2(4))(3)"
> 
> <strong>解释:</strong> 原本将是“1(2(4)())(3())”，
> 在你省略所有不必要的空括号对之后，
> 它将是“1(2(4))(3)”。
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> 二叉树: [1,2,3,null,4]
>        1
>      /   \
>     2     3
>      \  
>       4 
> 
> <strong>输出:</strong> "1(2()(4))(3)"
> 
> <strong>解释:</strong> 和第一个示例相似，
> 除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
> </pre>
> </div>

解法一
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
    string tree2str(TreeNode* t) {
        if(!t) return "";
        string s1 = tree2str(t->left);
        string s2 = tree2str(t->right);
        if(s1 == "" && s2 == "") return to_string(t->val);
        if(s1 != "" && s2 == "") return to_string(t->val) + "(" + s1 + ")";
        if(s1 == "" && s2 != "") return to_string(t->val) + "()" + "(" + s2 + ")";
        return to_string(t->val) + "(" + s1 + ")" + "(" + s2 + ")";
    }
};
```

思路：

前序遍历，处理空括号时有4种情况：
1. 左、右子树都为空，此时只返回“根结点值”；
2. 左子树空，右子树非空，此时返回“根结点值”+“()”+“(右子树字符串)”；
3. 左子树非空，右子树空，此时返回“根结点值”+“(左子树字符串)”；
4. 左、右子树都非空，此时返回“根结点值”+“(左子树字符串)”+“(右子树字符串)”。

<div style="text-align: right"> 2019/06/10 10:55 </div>