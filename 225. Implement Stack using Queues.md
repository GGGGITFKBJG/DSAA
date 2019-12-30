### 225. 用队列实现栈
> <div class="content__2ebE"><p>使用队列实现栈的下列操作：</p>
> 
> <ul> 	<li>push(x) -- 元素 x 入栈</li> 	<li>pop() -- 移除栈顶元素</li> 	<li>top()
> -- 获取栈顶元素</li> 	<li>empty() -- 返回栈是否为空</li> </ul>
> 
> <p><strong>注意:</strong></p>
> 
> <ul> 	<li>你只能使用队列的基本操作-- 也就是&nbsp;<code>push to back</code>,
> <code>peek/pop from front</code>, <code>size</code>, 和&nbsp;<code>is
> empty</code>&nbsp;这些操作是合法的。</li> 	<li>你所使用的语言也许不支持队列。&nbsp;你可以使用 list
> 或者 deque（双端队列）来模拟一个队列&nbsp;, 只要是标准的队列操作即可。</li>
> 	<li>你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。</li> </ul> </div>

解法一
```cpp
//两个队列实现一个栈
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        if(!q2.empty()) {//保证q2元素数不大于1
            q1.push(q2.front());
            q2.pop();
        }
        q2.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = q2.front();
        q2.pop();
        if(!q1.empty()) top();//注意这里, 如果q1为空, top()会出错
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        if(q2.empty()) {
            for(int i = 0; i < (int)(q1.size() - 1); i++) {
                q1.push(q1.front());
                q1.pop();
            }
            q2.push(q1.front());
            q1.pop();
        }
        return q2.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q2.empty();
    }
private:
    queue<int> q1, q2;//q2始终保存一个栈顶元素, q1按入栈顺序保存其他元素
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

解法二
```cpp
//一个队列实现一个栈
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);//每push一次, 就将队列循环,将最新push的元素移至队头, 此时出队序列即为出栈序列
        for(int i = 0; i < (int)(q.size() - 1); i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

解法一
1. 用了两个队列q1、q2；
2. q2始终存储1个值（栈顶元素）或0个值（空栈）；
3. push操作时，先将入栈元素加入队列q2，再将q2之前的元素（如果有的话）放入q1，此时q1是按入栈顺序存储的；
4. top操作时，若q2有元素则直接返回其队头；否则将q1自循环q1.size() - 1次（把队尾元素移至队头），再把q1队头元素放入q2，返回q2队头；top操作后q2必定有1个元素。
5. pop操作时，先令q2出队；若q1有元素，进行一次top操作；
6. 其它操作的行为显而易见。

解法二
1. 只使用了一个队列q；
2. 每次push操作，先将新入栈元素加入队尾，再使q自循环q.size() - 1次，将新元素移至队头，此时出队序列就是正确的出栈序列。
3. 其它操作逻辑都很清晰，看代码。

解法一主要耗时操作在top（pop）上，而解法二主要耗时在push上。根据栈的使用特点，push操作通常多于pop操作，可能解法一更快一些。（但是使用了一个额外的队列，只存了一个栈顶元素，不浪费吗？）

<div style="text-align: right"> 2019/04/28 20:44 </div>