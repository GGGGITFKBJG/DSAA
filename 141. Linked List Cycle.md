### 141. 环形链表

> <div class="content__2ebE"><p>给定一个链表，判断链表中是否有环。</p>
> 
> <p>为了表示给定链表中的环，我们使用整数 <code>pos</code> 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果
> <code>pos</code> 是 <code>-1</code>，则在该链表中没有环。</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例 1：</strong></p>
> 
> <pre><strong>输入：</strong>head = [3,2,0,-4], pos = 1
> <strong>输出：</strong>true <strong>解释：</strong>链表中有一个环，其尾部连接到第二个节点。
> </pre>
> 
> <p><img style="height: 97px; width: 300px;"
> src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png"
> alt=""></p>
> 
> <p><strong>示例&nbsp;2：</strong></p>
> 
> <pre><strong>输入：</strong>head = [1,2], pos = 0
> <strong>输出：</strong>true <strong>解释：</strong>链表中有一个环，其尾部连接到第一个节点。
> </pre>
> 
> <p><img style="height: 74px; width: 141px;"
> src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png"
> alt=""></p>
> 
> <p><strong>示例 3：</strong></p>
> 
> <pre><strong>输入：</strong>head = [1], pos = -1
> <strong>输出：</strong>false <strong>解释：</strong>链表中没有环。 </pre>
> 
> <p><img style="height: 45px; width: 45px;"
> src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png"
> alt=""></p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>进阶：</strong></p>
> 
> <p>你能用 <em>O(1)</em>（即，常量）内存解决此问题吗？</p> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *temp1 = head, *temp2 = head->next;
        while(true) {
            if(temp1 == temp2) return true;//快指针追上慢指针
            if(temp2 == nullptr || temp2->next == nullptr ||
               temp2->next->next == nullptr) return false;//快指针到达尾部
            temp1 = temp1->next;
            temp2 = temp2->next->next;
        }
    }
};
```

一般解法使用哈希表，空间复杂度O(n)
经典解法：快慢指针，空间复杂度O(1)

<div style="text-align: right"> 2019/04/24 11:09  </div>