### 703. 数据流中的第K大元素

> <div class="content__2ebE"><p>设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。</p>
> 
> <p>你的&nbsp;<code>KthLargest</code>&nbsp;类需要一个同时接收整数&nbsp;<code>k</code> 和整数数组<code>nums</code>&nbsp;的构造器，它包含数据流中的初始元素。每次调用&nbsp;<code>KthLargest.add</code>，返回当前数据流中第K大的元素。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre>int k = 3;
> int[] arr = [4,5,8,2];
> KthLargest kthLargest = new KthLargest(3, arr);
> kthLargest.add(3);&nbsp; &nbsp;// returns 4
> kthLargest.add(5);&nbsp; &nbsp;// returns 5
> kthLargest.add(10);&nbsp; // returns 5
> kthLargest.add(9);&nbsp; &nbsp;// returns 8
> kthLargest.add(4);&nbsp; &nbsp;// returns 8
> </pre>
> 
> <p><strong>说明: </strong><br>
> 你可以假设&nbsp;<code>nums</code>&nbsp;的长度≥&nbsp;<code>k-1</code>&nbsp;且<code>k</code> ≥&nbsp;1。</p>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : lst(nums.begin(), nums.end()) {
        lst.sort();//增序
        it = lst.cend();
        while(--k) it--;//it指向第 k - 1 大的元素
    }
    
    int add(int val) {
        bool flag = false;
        auto p = lst.cbegin();
        while(p != lst.cend()) {
            if(val <= *p) {
                lst.insert(p, val);
                break;
            }
            if(p == it) flag = true;//插入位置在it右边，我们需要调整it的指向
            p++;
        }
        if(p == lst.cend()) lst.insert(p, val);//如果val是最大元素
        auto temp = it;
        return flag ? *it++ : *(--temp);
    }
private:
    list<int> lst;
    list<int>::const_iterator it;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

解法二
```cpp
//时间复杂度O(logk), 空间复杂度O(k)
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for(int num : nums) {
            if(pq.size() < k) pq.push(num);
            else if(num > pq.top()) {//pq.size() = k，且num > pq.top()时
                pq.pop();
                pq.push(num);
            }
        }
    }
    
    int add(int val) {
        if(pq.size() == k && val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        else if(pq.size() == k - 1) pq.push(val);
        return pq.top();
    }
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;//小顶堆
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

解法一

用了一个双向链表lst来存储元素，及一个迭代器it，指向了第 k - 1 大的元素（如果k = 1，则是尾后迭代器）。

初始化时将元素按增序排序，以后每次调用add就遍历一次链表，插入到合适的位置，并返回it的前一个元素。

解法二

解法一维护一个有序链表，实际上除了最后k个元素以外，其他元素都是没有必要记录的。可以只记录最大的k个元素来优化其效率。但因为我们只关心这k个元素的最小值，并不关心它们的排序，所以最好是使用堆（优先队列）。

解法二里，我们使用一个小顶堆pq来记录前k大的元素。此后每次add时，检查val是否大于堆顶元素，若是则先出堆，再将val入堆，返回堆顶；否则直接返回堆顶。

<div style="text-align: right"> 2019/06/25 11:43 </div>