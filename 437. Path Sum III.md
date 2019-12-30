### 437. 路径总和 III

> <div class="content__2ebE"><p>给定一个二叉树，它的每个结点都存放着一个整数值。</p>
> 
> <p>找出路径和等于给定数值的路径总数。</p>
> 
> <p>路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。</p>
> 
> <p>二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。</p>
> 
> <p><strong>示例：</strong></p>
> 
> <pre>root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
> 
>       10
>      /  \
>     <strong>5</strong>   <strong>-3</strong>    <strong>
>    /</strong> <strong>\</strong>    <strong>\</strong>   <strong>
>   3</strong>  <strong> 2</strong>   <strong>11</strong>
>  / \   <strong>\</strong>
> 3  -2   <strong>1</strong>
> 
> 返回 3。和等于 8 的路径有:
> 
> 1.  5 -&gt; 3
> 2.  5 -&gt; 2 -&gt; 1
> 3.  -3 -&gt; 11 </pre> </div>

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
    int count(TreeNode* root, int curSum, int target) {//从当前根结点开始, 计算满足要求的路径数
        if(root == nullptr) return 0;
        int res = 0;
        curSum += root->val;
        if(curSum == target) res += 1;
        res += count(root->left, curSum, target) + count(root->right, curSum, target);
        return res;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        int res = count(root, 0, sum);//从根结点开始
        res += pathSum(root->left, sum) + pathSum(root->right, sum);//从左、右子树开始
        return res;
    }
};
```

如果之前没有遇到过，这个题不是那么容易想，上面递归解法的思路如下：
1. 先回顾一下第112题。112题也是求路径总和：求是否存在一条路径，它从根结点到叶子结点的整条路径和为给定值（返回布尔值）。
代码贴一下：
```cpp
bool hasPathSum(TreeNode* root, int sum) { 
    if(root == nullptr) return false;
    if(root->left == nullptr && root->right == nullptr) {//是叶子结点
        if(sum == root->val) return true;//找到
        return false;//未找到
    }
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);//这里采用了向下传差的方式, 也可以累积求和
}
```

2. 这个题使用双递归法，在第112的基础上稍加修改。
如果将第112题的要求修改两条，
①要求从根结点开始，但不必到达叶子结点，途中若存在部分和为targetSum的也算满足要求；
②求出满足条件的路径条数（返回整型值），而不单单是要判断是否存在；
依然很简单，只要①在每一层的结点判断是否满足要求；②加一个计数变量。这正是以上代码里的count函数所做的，它从单棵树的根结点开始查找满足要求的路径。
```cpp
int count(TreeNode* root, int curSum, int target) {//从当前根结点开始, 计算满足要求的路径数
    if(root == nullptr) return 0;
    int res = 0;//保存计数
    curSum += root->val;//累积和
    if(curSum == target) res += 1;//根结点就满足了, 结果 + 1
    
    //继续向下求和, 看是否有满足要求的路径(有可能有, 因为结点可以是负值)
    res += count(root->left, curSum, target) + count(root->right, curSum, target);
    return res;
}
```

3. 单是这样还不够，因为此题有要求，不单是从根结点开始，可以从任意一结点开始算起。那我们就在外层对所有结点做递归，正是主函数所做的。第3行，先对当前根结点作统计；第4行，分别对左子结点、右子结点作独立的统计，递归下去，可以以每一个结点为根结点，进行count操作。
```cpp
int pathSum(TreeNode* root, int sum) {
    if(root == nullptr) return 0;
    int res = count(root, 0, sum);//从根结点开始
    res += pathSum(root->left, sum) + pathSum(root->right, sum);//从左、右子树开始
    return res;
}
```

两个函数总的效果就是，对树上的每一个结点，进行count操作（而count操作查找当前树满足要求的路径数），对所有结点的返回值求和，就是满足要求的答案。
代码里两个函数中的res变量可以省略掉，我这里加上它是为了逻辑更清晰。此题还有很多种解法，但这个解法个人认为是最容易理解，代码也最简洁的。
<div style="text-align: right">2019/05/05 13:28  </div>
