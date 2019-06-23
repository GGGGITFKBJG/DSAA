### 257. 二叉树的所有路径

> <div class="content__2ebE"><p>给定一个二叉树，返回所有从根节点到叶子节点的路径。</p>
> 
> <p><strong>说明:</strong>&nbsp;叶子节点是指没有子节点的节点。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong>
> 
>    1  /   \ 2     3  \   5
> 
> <strong>输出:</strong> ["1-&gt;2-&gt;5", "1-&gt;3"]
> 
> <strong>解释:</strong> 所有根节点到叶子节点的路径为: 1-&gt;2-&gt;5, 1-&gt;3</pre>
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
    void allPath(vector<string>& vs, TreeNode* node) {
        if(vs[vs.size() - 1].empty()) vs[vs.size() - 1] += to_string(node->val);//node不可能为空
        else vs[vs.size() - 1] += "->" + to_string(node->val);
        
        if(node->left != nullptr && node->right == nullptr) allPath(vs, node->left);
        else if(node->left == nullptr && node->right != nullptr) allPath(vs, node->right);
        else if(node->left != nullptr && node->right != nullptr) {
            string temp = vs[vs.size() - 1];//缓存两子树的公共的前缀
            allPath(vs, node->left);//追加原字符串
            vs.push_back(string(temp));//新增中下个字符, 初始化为公共前缀
            allPath(vs, node->right);//追加新增字符串
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) return {};
        vector<string> vs = {""};
        allPath(vs, root);
        return vs;
    }
};
```

思路还是DFS。不过有些细节：
1. 先序遍历每个结点。对于每个当前结点，先将当前结点值追加到容器vs的最后一个字串末尾；
2. 接下来分几种情况，
当前结点左、右子树都为空，此时什么也不干直接返回；
当左、右子树其一为空，就继续遍历非空子树，子树接着对当前结点使用的字符串进行追加；
当左、右子树都非空，先将当前结点访问的字符串缓存下来。遍历完左子树，此时当前字符串已经完成一整条路径，再将原容器新增一个字符串作当前字符串，初始化为之前缓存的前缀，继续遍历右子树。
3. 遍历结束后，将容器返回。

看起来有些绕，这个解法是利用了先序遍历的特点。
对于一次先序遍历，只看叶子结点，对叶子结点的访问是按顺序进行的，从图上看也就是说叶子结点的访问顺序是从左向右。
隐含的意义是，先序遍历只有访问完第1条路径之后（访问完第一个叶子结点），才会去访问第二条路径（才会访问第二个叶子结点），所以这样可以不用判断，直接对容器内的最后一个字符串进行追加，因为容器内之前的字符串都已经完成访问，不需要再修改了。
<div style="text-align: right"> 2019/04/29 13:25   </div>