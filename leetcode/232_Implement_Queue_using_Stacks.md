### 232. 用栈实现队列

> <div class="content__2ebE"><p>使用栈实现队列的下列操作：</p>
> 
> <ul> 	<li>push(x) -- 将一个元素放入队列的尾部。</li> 	<li>pop() -- 从队列首部移除元素。</li>
> 	<li>peek() -- 返回队列首部的元素。</li> 	<li>empty() -- 返回队列是否为空。</li> </ul>
> 
> <p><strong>示例:</strong></p>
> 
> <pre>MyQueue queue = new MyQueue();
> queue.push(1); 
> queue.push(2);   
> queue.peek();  // 返回 1 
> queue.pop();  // 返回 1 
> queue.empty(); // 返回 false</pre>
> 
> <p><strong>说明:</strong></p>
> 
> <ul> 	<li>你只能使用标准的栈操作 -- 也就是只有&nbsp;<code>push to
> top</code>,&nbsp;<code>peek/pop from
> top</code>,&nbsp;<code>size</code>, 和&nbsp;<code>is
> empty</code>&nbsp;操作是合法的。</li> 	<li>你所使用的语言也许不支持栈。你可以使用 list 或者
> deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。</li> 	<li>假设所有操作都是有效的 （例如，一个空的队列不会调用
> pop 或者 peek 操作）。</li> </ul> </div>

解法一
```cpp
//两个栈实现一个队列
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s2.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = peek();
        s1.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if(s1.empty()) {
            while(!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
    
private:
    stack<int> s1, s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

经典题目。
1. 栈s2用来存储入队元素。队列push操作时只是单纯地对s2进行push操作；
2. 栈s1用来存储出队元素。队列peek（pop）操作时，①当s1非空时，直接对s1进行top（pop）操作；②当s1为空时，将所有s2元素出栈，并入栈s1；
3. 以上规则可以保证入队、出队序列总是正确的。

<div style="text-align: right"> 2019/04/28 21:57  </div>