### 155. 最小栈

> <div class="content__2ebE"><p>设计一个支持 push，pop，top
> 操作，并能在常数时间内检索到最小元素的栈。</p>
> 
> <ul> 	<li>push(x)&nbsp;-- 将元素 x 推入栈中。</li> 	<li>pop()&nbsp;--
> 删除栈顶的元素。</li> 	<li>top()&nbsp;-- 获取栈顶元素。</li> 	<li>getMin() --
> 检索栈中的最小元素。</li> </ul>
> 
> <p><strong>示例:</strong></p>
> 
> <pre>MinStack minStack = new MinStack(); 
> minStack.push(-2);
> minStack.push(0); 
> minStack.push(-3); 
> minStack.getMin();   --&gt; 返回-3.
> minStack.pop(); 
> minStack.top();      --&gt; 返回 0. 
> minStack.getMin();   --&gt; 返回 -2. </pre> </div>

解法一
```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() : array(nullptr), minElem({INT_MAX, 0}), length(0), maxSize(10) {
        array = new int [10];
        if(array == nullptr) {
            maxSize = 0;
            length = 0;
        }
    }
    
    ~MinStack() {
        delete[] array;
    }
    
    void push(int x) {
        if(length == maxSize) {
            int *temp = new int[maxSize + 10];
            if(temp == nullptr) return;
            memcpy(temp, array, sizeof(int) * length);
            delete[] array;
            array = temp;
            maxSize += 10;
        }
        array[length++] = x;
        if(x < minElem.first) {
            minElem.first = x;
            minElem.second = 1;
        }
        else if(x == minElem.first) minElem.second++;
    }
    
    void pop() {
        if(length == 0) return;
        if(array[length - 1] == minElem.first) minElem.second--;
        length--;
        if(minElem.second == 0) {//更新最小值
            minElem.first = INT_MAX;
            for(int i = 0; i < length; i++) {
                if(array[i] < minElem.first) {
                    minElem.first = array[i];
                    minElem.second = 1;
                }
                else if(array[i] == minElem.first) minElem.second++;
            }
        }
    }
    
    int top() {
        if(length > 0) return array[length - 1];
        return INT_MIN;
    }
    
    int getMin() {
        return minElem.first;
    }
private:
    int *array;
    pair<int, int> minElem;//minVal, count
    int length;
    int maxSize;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

解法二
```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if(min.empty() || x <= min.top()) min.push(x);//注意要有等号
        st.push(x);
    }
    
    void pop() {
        if(st.top() == min.top()) min.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
    stack<int> st;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

解法一比较原始：
1. 为了实现最小元素查找，用了一个键值对分别保存最小元素的值和个数，每次入栈和出栈判断是否要更新该键值对，其中最小元素个数为0时，要花费O(n)的时间来再次确定最小元素；
2. 为了使空间足够用，使用了动态数组，初始化大小为10，用完的时候再申请新的空间，新空间比旧空间大10；
3. 优点是节省空间，缺点有时候需要遍历所有元素更新最小值，效率不是很好，编程也复杂。

解法二比较简单：用标准库stack实现，再用一个额外的stack保存最小值，其它与解法一类似。注意push新元素与最小元素相等时，最小元素栈也要push。

<div style="text-align: right"> 2019/04/24 22:35   </div>