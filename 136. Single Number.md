### 136. 只出现一次的数字

> <div
> class="content__2ebE"><p>给定一个<strong>非空</strong>整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。</p>
> 
> <p><strong>说明：</strong></p>
> 
> <p>你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [2,2,1] <strong>输出:</strong> 1 </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> [4,1,2,1,2] <strong>输出:</strong> 4</pre>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};
```

此题第一印象是用一个unordered_set来保存首次遇到的数字，再次遇到就删除，直到最后留在set里的数字就是结果。
但题上要求用空间复杂度O(1)，解法很巧妙，用到了按位异或运算的性质。

异或是一种基于二进制的位运算，用符号XOR或者 ^ 表示，其运算法则是对运算符两侧数的每一个二进制位，同值取0，异值取1。

性质

> 1、交换律 a^b = b^a 
> 2、结合律（即(a^b)^c == a^(b^c)） 
> 3、对于任何数x，都有x^x=0，x^0=x
> 4、自反性 A XOR B XOR B = A xor  0 = A
> ----摘自https://www.cnblogs.com/suoloveyou/archive/2012/04/25/2470292.html

1. 对于此题，假设有n个数，[a1, a2, a3, ... , an]，
2. 令res = a1 ^ a2 ^ a3 ^ ... ^ an；
3. 根据交换律和结合律，我们可以把出现两次的数字相邻放置，res = a1 ^ a1' ^ a2 ^ a2' ^... ^ am ^ am' ^ ak，假设ak是只出现1次的数字；
4. 由性质3知道，两个相同的数字异或结果为0；res = 0 ^ ak = ak，返回ak即可。

<div style="text-align: right">2019/04/24 10:56  </div>