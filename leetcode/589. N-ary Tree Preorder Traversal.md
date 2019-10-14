### 589. N叉树的前序遍历

> <div class="content__2ebE"><p>给定一个 N 叉树，返回其节点值的<em>前序遍历</em>。</p>
> 
> <p>例如，给定一个&nbsp;<code>3叉树</code>&nbsp;:</p>
> 
> <p>&nbsp;</p>
> 
> <p><img style="width: 100%; max-width: 300px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/narytreeexample.png"></p>
> 
> <p>&nbsp;</p>
> 
> <p>返回其前序遍历: <code>[1,3,5,6,2,4]</code>。</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>说明:&nbsp;</strong>递归法很简单，你可以使用迭代法完成此题吗?</p></div>

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
    void build(vector<int>& vec, Node* root) {
        if(!root) return;
        vec.push_back(root->val);
        for(Node* chd : root->children) build(vec, chd);
    }
    
    vector<int> preorder(Node* root) {
        vector<int> res;
        build(res, root);
        return res;
    }
};
```

解法二
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
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int> res;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node* temp = st.top();
            st.pop();
            res.push_back(temp->val);
            for(auto p = temp->children.rbegin(); p != temp->children.rend(); p++) {
                st.push(*p);
            }
        }
        return res;
    }
};
```

思路：

解法一，递归法。

解法二，迭代法。

<div style="text-align: right"> 2019/06/03 22:35 </div>