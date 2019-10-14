### 83. 删除排序链表中的重复元素

> <div class="content__2ebE"><div><p>给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> 1-&gt;1-&gt;2 <strong>输出:</strong> 1-&gt;2
> </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> 1-&gt;1-&gt;2-&gt;3-&gt;3
> <strong>输出:</strong> 1-&gt;2-&gt;3</pre> </div></div>

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *p = head;
        while(p->next != nullptr) {
            if(p->val == p->next->val) {
                ListNode *temp = p->next;
                p->next = temp->next;
                delete temp;
            }
            else p = p->next;
        }
        return head;
    }
};
```

思路：
1. 设置一个指针变量p指向第一个元素；
2. 确保p->next不为空，比较p结点的值与p->next结点的值；
3. 若相等则删除p->next，不等则让p向后移1；
3. 到末尾返回head。