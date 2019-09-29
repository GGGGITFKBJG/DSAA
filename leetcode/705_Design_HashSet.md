### 705. 设计哈希集合

> <div class="content__2ebE"><p>不使用任何内建的哈希表库设计一个哈希集合</p>
> 
> <p>具体地说，你的设计应该包含以下的功能</p>
> 
> <ul>
> 	<li><code>add(value)</code>：向哈希集合中插入一个值。</li>
> 	<li><code>contains(value)</code> ：返回哈希集合中是否存在这个值。</li>
> 	<li><code>remove(value)</code>：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。</li>
> </ul>
> 
> <p><br>
> <strong>示例:</strong></p>
> 
> <pre>MyHashSet hashSet = new MyHashSet();
> hashSet.add(1); &nbsp; &nbsp; &nbsp; &nbsp; 
> hashSet.add(2); &nbsp; &nbsp; &nbsp; &nbsp; 
> hashSet.contains(1); &nbsp;&nbsp;&nbsp;// 返回 true
> hashSet.contains(3); &nbsp;&nbsp;&nbsp;// 返回 false (未找到)
> hashSet.add(2); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
> hashSet.contains(2); &nbsp;&nbsp;&nbsp;// 返回 true
> hashSet.remove(2); &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
> hashSet.contains(2); &nbsp;&nbsp;&nbsp;// 返回  false (已经被删除)
> </pre>
> 
> <p><br>
> <strong>注意：</strong></p>
> 
> <ul>
> 	<li>所有的值都在&nbsp;<code>[1, 1000000]</code>的范围内。</li>
> 	<li>操作的总数目在<code>[1, 10000]</code>范围内。</li>
> 	<li>不要使用内建的哈希集合库。</li>
> </ul>
> </div>

解法一
```cpp
//时间复杂度O(1), 空间复杂度O(n)
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : hashSet(125000, 0), zero(false) {}
    
    void add(int key) {
        if(key == 0) {
            zero = true;
            return;
        }
        int ind1 = key / 8;
        int ind2 = key % 8;
        if(ind2 == 0) hashSet[ind1 - 1] |= 1 << 7;
        else hashSet[ind1] |= 1 << (ind2 - 1);
    }
    
    void remove(int key) {
        if(key == 0) {
            zero = false;
            return;
        }
        int ind1 = key / 8;
        int ind2 = key % 8;
        if(ind2 == 0) hashSet[ind1 - 1] &= ~(1 << 7);
        else hashSet[ind1] &= ~(1 << (ind2 - 1));
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(key == 0) return zero;
        int ind1 = key / 8;
        int ind2 = key % 8;
        return ind2 == 0 ?
               ( hashSet[ind1 - 1] & (1 << 7) ) == 1 << 7 :
               ( hashSet[ind1] & (1 << (ind2 - 1)) ) == 1 << (ind2 - 1);
    }
private:
    vector<unsigned char> hashSet;
    bool zero;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```

用了1000000个二进制位代表1~1000000的数字，所以添加和删除操作是常数时间。

坑：题目上说从1开始到1000000，但是测试用例里面有0，让我不得不加一个zero处理0的情况。

<div style="text-align: right"> 2019/06/25 12:37 </div>
