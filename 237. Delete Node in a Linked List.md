### 237. 删除链表中的节点

> <div
> class="content__2ebE"><p>请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。</p>
> 
> <p>现有一个链表 --&nbsp;head =&nbsp;[4,5,1,9]，它可以表示为:</p>
> 
> <p><img style="height: 49px; width: 300px;"
> src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/01/19/237_example.png"
> alt=""></p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> head = [4,5,1,9], node = 5
> <strong>输出:</strong> [4,1,9] <strong>解释:
> </strong>给定你链表中值为&nbsp;5&nbsp;的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -&gt; 1
> -&gt; 9. </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> head = [4,5,1,9], node = 1
> <strong>输出:</strong> [4,5,9] <strong>解释:
> </strong>给定你链表中值为&nbsp;1&nbsp;的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -&gt; 5
> -&gt; 9. </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>说明:</strong></p>
> 
> <ul> 	<li>链表至少包含两个节点。</li> 	<li>链表中所有节点的值都是唯一的。</li>
> 	<li>给定的节点为非末尾节点并且一定是链表中的一个有效节点。</li> 	<li>不要从你的函数中返回任何结果。</li> </ul>
> </div>

解法一
```cpp
//时间复杂度O(1), 空间复杂度O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```

第一次看见这个题直接看懵了，完全不知道前一个指针还能删除链表结点？看了答案确实很巧妙，答案不再去想办法删掉当前的节点，而是选择将下一节点替换到当前结点，删除下一个节点来代替，代码很简单。
看来学多了数据结构的经典方法，思路慢慢被固化了。哎，合上书也要学会思考，睡了，加油。
<div style="text-align: right"> 2019/04/29 00:25  </div>
