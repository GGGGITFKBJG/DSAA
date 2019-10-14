### 707. 设计链表

> <div class="content__2ebE"><p>设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：<code>val</code>&nbsp;和&nbsp;<code>next</code>。<code>val</code>&nbsp;是当前节点的值，<code>next</code>&nbsp;是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性&nbsp;<code>prev</code>&nbsp;以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。</p>
> 
> <p>在链表类中实现这些功能：</p>
> 
> <ul>
> 	<li>get(index)：获取链表中第&nbsp;<code>index</code>&nbsp;个节点的值。如果索引无效，则返回<code>-1</code>。</li>
> 	<li>addAtHead(val)：在链表的第一个元素之前添加一个值为&nbsp;<code>val</code>&nbsp;的节点。插入后，新节点将成为链表的第一个节点。</li>
> 	<li>addAtTail(val)：将值为&nbsp;<code>val</code> 的节点追加到链表的最后一个元素。</li>
> 	<li>addAtIndex(index,val)：在链表中的第&nbsp;<code>index</code>&nbsp;个节点之前添加值为&nbsp;<code>val</code>&nbsp; 的节点。如果&nbsp;<code>index</code>&nbsp;等于链表的长度，则该节点将附加到链表的末尾。如果 <code>index</code> 大于链表长度，则不会插入节点。</li>
> 	<li>deleteAtIndex(index)：如果索引&nbsp;<code>index</code> 有效，则删除链表中的第&nbsp;<code>index</code> 个节点。</li>
> </ul>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例：</strong></p>
> 
> <pre>MyLinkedList linkedList = new MyLinkedList();
> linkedList.addAtHead(1);
> linkedList.addAtTail(3);
> linkedList.addAtIndex(1,2);   //链表变为1-&gt; 2-&gt; 3
> linkedList.get(1);            //返回2
> linkedList.deleteAtIndex(1);  //现在链表是1-&gt; 3
> linkedList.get(1);            //返回3
> </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>提示：</strong></p>
> 
> <ul>
> 	<li>所有值都在&nbsp;<code>[1, 1000]</code>&nbsp;之内。</li>
> 	<li>操作次数将在&nbsp;&nbsp;<code>[1, 1000]</code>&nbsp;之内。</li>
> 	<li>请不要使用内置的 LinkedList 库。</li>
> </ul>
> </div>

解法一
```cpp
class MyLinkedList {
public:
    struct Node {
        Node() : val(0), next(nullptr) {}
        Node(int elem, Node* ptr) : val(elem), next(ptr) {}
        int val;
        Node* next;
    };
    
    /** Initialize your data structure here. */
    MyLinkedList() : head(new Node(0, nullptr)), len(0) {}
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index > len - 1) return -1;
        Node* p = head->next;
        while(index--) p = p->next;
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* p = new Node(val, head->next);
        head->next = p;
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* p = head;
        for(int i = 0; i < len; i++) p = p->next;
        p->next = new Node(val, nullptr);
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > len) return;
        if(index <= 0) addAtHead(val);
        else if(index == len) addAtTail(val);
        else {
            Node* p = head;
            while(index--) p = p->next;
            Node* temp = p->next;
            p->next = new Node(val, temp);
            len++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index > len - 1) return;
        Node* p = head;
        while(index--) p = p->next;
        p->next = p->next->next;
        len--;
    }
private:
    Node* head;
    int len;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```

常见题目，有以下几点：

1. 为了方便增加了头结点；
2. 使用了一个整数记录链表长度，这样就可以直接判断出所给的索引值是否有效，而不用耗费线性时间去遍历一次。

<div style="text-align: right"> 2019/06/26 21:12 </div>