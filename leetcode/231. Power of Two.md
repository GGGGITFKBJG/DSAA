### 231. 2的幂

> <div class="content__2ebE"><p>给定一个整数，编写一个函数来判断它是否是 2 的幂次方。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> 1 <strong>输出:</strong> true <strong>解释:
> </strong>2<sup>0</sup>&nbsp;= 1</pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> 16 <strong>输出:</strong> true <strong>解释:
> </strong>2<sup>4</sup>&nbsp;= 16</pre>
> 
> <p><strong>示例 3:</strong></p>
> 
> <pre><strong>输入:</strong> 218 <strong>输出:</strong> false</pre> </div>

解法一
```cpp
//时间复杂度O(1), 空间复杂度O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n <= 0 ? false : (n & n - 1)  == 0;
    }
};
```

总结：
1. 这个题第一眼看上去，好像是要把n循环除以2直到1，过程中检查余数是否为0，这种算法时间复杂度为O(log2(n))，可以接受；
2. 但是看二进制表示，2的幂有一个特点，它只有一个位是1，其余位全为0。回想之前的第191题（统计位为1的个数），此题转化为了检查n二进制位中，位为1的个数是否为1，这样复杂度仍为O(log2(n))；
3. 回想191题的解法二，其中不容易发现的特点是，如果n为2的幂，那么一定有 (n & n - 1) = 0。这下用复杂度O(1)就可以解决问题，如上的解法，注意小于1的数都不是2的幂。

<div style="text-align: right"> 2019/04/28 21:41  </div>