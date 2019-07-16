### 429. N叉树的层序遍历
> <div class="content__2ebE"><p>给定一个 N 叉树，返回其节点值的<em>层序遍历</em>。
> (即从左到右，逐层遍历)。</p>
> 
> <p>例如，给定一个&nbsp;<code>3叉树</code>&nbsp;:</p>
> 
> <p>&nbsp;</p>
> 
> <p><img style="width: 100%; max-width: 300px;"
> src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/narytreeexample.png"></p>
> 
> <p>&nbsp;</p>
> 
> <p>返回其层序遍历:</p>
> 
> <pre>[
>      [1],
>      [3,2,4],
>      [5,6] ] </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>说明:</strong></p>
> 
> <ol> 	<li>树的深度不会超过&nbsp;<code>1000</code>。</li>
> 	<li>树的节点总数不会超过&nbsp;<code>5000</code>。</li> </ol></div>

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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        queue<Node*> q1;
        q1.push(root);
        while(!q1.empty()) {
            queue<Node*> q2;
            q1.swap(q2);
            res.push_back(vector<int>());
            while(!q2.empty()) {
                Node* temp = q2.front();
                q2.pop();
                res[res.size() - 1].push_back(temp->val);
                for(Node* nd : temp->children) if(nd != nullptr) q1.push(nd);
            }
        }
        return res;
    }
};
```

使用两个队列，q1、q2分别记录两个不同层的结点指针。每次先交换q1、q2，当前层的结点指针就存在q2中，而q1被清空。在遍历时将q2中元素的子结点放入q1，循环这个步骤。
层序遍历也可以只用一个队列，对层的区分使用另外一个int计数变量。看个人爱好吧，对容器的swap操作速度是很快的，所以个人觉得使用两个队列方便。

<div style="text-align: right"> 2019/05/04 18:11   </div>
