### 590. N叉树的后序遍历

> <div class="content__2ebE"><p>给定一个 N 叉树，返回其节点值的<em>后序遍历</em>。</p>
> 
> <p>例如，给定一个&nbsp;<code>3叉树</code>&nbsp;:</p>
> 
> <p>&nbsp;</p>
> 
> <p><img style="width: 100%; max-width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/narytreeexample.png"></p>
> 
> <p>&nbsp;</p>
> 
> <p>返回其后序遍历: <code>[5,6,3,2,4,1]</code>.</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>说明:</strong>&nbsp;递归法很简单，你可以使用迭代法完成此题吗?</p></div>

解法一
```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int> res;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* temp = st.top();
            st.pop();
            res.insert(res.begin(), temp->val);
            for(Node* chd : temp->children) st.push(chd);
        }
        return res;
    }
};
```

思路：

迭代法。与前序遍历类似，只是在结果保存时将其反序存储。入栈顺序是从左到右，出栈顺序就是从右到左，那么原来前序遍历的顺序是**中-右-左**，将其反序输出，就是**左-右-中**的后序遍历结果。

所以这个问题的关键就是，前序遍历与后序遍历之间的反序关系。

<div style="text-align: right"> 2019/06/04 21:32 </div>