### 21. 合并两个有序链表

> <div
> class="content__2ebE"><div><p>将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。&nbsp;</p>
> 
> <p><strong>示例：</strong></p>
> 
> <pre><strong>输入：</strong>1-&gt;2-&gt;4, 1-&gt;3-&gt;4
> <strong>输出：</strong>1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4 </pre>
> </div></div>

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode *newList, *temp;
        if(l1->val <= l2->val) {
            temp = l1;
            l1 = l1->next;
        }
        else {
            temp = l2;
            l2 = l2->next;
        }
        newList = temp;//保存头指针
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1 == nullptr) temp->next = l2;
        else temp->next = l1;
        
        return newList;
    }
};
```
这个题很简单。用头结点的好处是不用处理特殊情况，不用的话节省空间和运行速度（Maybe？我试了两种，带头结点的耗时24ms，不带头结点的耗时16ms，计时仅供参考）。