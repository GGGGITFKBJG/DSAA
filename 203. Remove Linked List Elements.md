### 203. 移除链表元素

> <div
> class="content__2ebE"><p>删除链表中等于给定值&nbsp;<strong><em>val&nbsp;</em></strong>的所有节点。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> 1-&gt;2-&gt;6-&gt;3-&gt;4-&gt;5-&gt;6,
> <em><strong>val</strong></em> = 6 <strong>输出:</strong>
> 1-&gt;2-&gt;3-&gt;4-&gt;5 </pre> </div>

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;
        ListNode* p = head;
        while(p != nullptr && p->next != nullptr) {//把head以后的val节点删除
            if(p->next->val == val) {
                ListNode* temp = p->next;
                p->next = temp->next;
                delete temp;
            }
            else p = p->next;
        }
        if(head->val == val) {//处理头节点
            ListNode* temp = head->next;
            delete head;
            head = temp;
        }
        return head;
    }
};
```

//时间复杂度O(n), 空间复杂度O(1)
```cpp
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return nullptr;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;//内存泄漏了, 不过机器审核不关心这个
    }
};
```
   
解法一简单易懂 ，要注意的是如果头结点是要删除的结点，需要单独处理；
解法二用的递归法很巧妙，看代码。


<div style="text-align: right"> 2019/04/27 21:08   </div>