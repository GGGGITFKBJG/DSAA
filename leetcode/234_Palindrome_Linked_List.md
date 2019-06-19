### 234. 回文链表

> <div class="content__2ebE"><p>请判断一个链表是否为回文链表。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> 1-&gt;2 <strong>输出:</strong> false</pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> 1-&gt;2-&gt;2-&gt;1 <strong>输出:</strong> true </pre>
> 
> <p><strong>进阶：</strong><br> 你能否用&nbsp;O(n) 时间复杂度和 O(1) 空间复杂度解决此题？</p>
> </div>

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
    ListNode* reverseList(ListNode* head) {//反转链表
        ListNode *p = nullptr, *c = head, *n;
        while(c != nullptr) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) return true;
        ListNode *fast = head, *slow = head;
        while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {//循环结束后slow为链表中点
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newList = reverseList(slow->next);
        while(newList != nullptr) {
            if(newList->val != head->val) return false;
            newList = newList->next;
            head = head->next;
        }
        return true;
    }
};
```

一般思路是，先找中点，顺便使用一个栈记录下链表前半部分的元素，再从中点处开始遍历，依次与出栈值相比较，但是有额外的空间需求不符合题目要求。正确的思路如下：
1. 用快慢指针遍历一次，先找到中点slow；//O(n)
2. 将子链表slow->next反转，得到新链表newList；//O(n / 2)
3. 比较newList的元素是否依次与head链表相等。//O(n / 2)
总的时间复杂度为O(n)，空间复杂度为O(1)，副作用是它改变了链表的结构（如果有要求，可以把子链表反转回去，再拼接到一起，仍然是O(n) ）。

<div style="text-align: right"> 2019/04/28 22:38  </div>