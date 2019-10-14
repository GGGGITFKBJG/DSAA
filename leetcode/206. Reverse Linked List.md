### 206. 反转链表

> <div class="content__2ebE"><p>反转一个单链表。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL
> <strong>输出:</strong> 5-&gt;4-&gt;3-&gt;2-&gt;1-&gt;NULL</pre>
> 
> <p><strong>进阶:</strong><br> 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？</p> </div>

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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = nullptr, *c = head, *n;
        while(c != nullptr) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        return p;
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(n)
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;//链表结点数小于2时返回
        ListNode *first = head->next;//保存新链表尾
        head->next = nullptr;//head修改next指针
        ListNode *last = reverseList(first);//反转子链表, 并返回新链表头
        first->next = head;//子链表尾加上head
        return last;//返回新链表头
    }
};
```

解法一
常规解法，用三个变量p、c、n分别记下前一个、当前、下一个结点，循环地将当前结点的next指向前结点，再将三个指针向后移动。最后返回p（它是最后一个结点，也是新链表的第一个结点）。
解法二
递归法：
1. 每次抽出第一个结点head，记下第二个结点first；
2. 然后将第二个结点开始的后续链表反转，并返回反转后的第一个结点last；
3. 再将新链表尾元素first后，加上head；
4. 递归地进行，终止条件是当前结点的next指针为空。

<div style="text-align: right">   2019/04/28 18:24  </div>