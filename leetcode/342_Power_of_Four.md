### 342. 4的幂

> <div class="content__2ebE"><p>给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是
> 4&nbsp;的幂次方。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入: </strong>16 <strong>输出: </strong>true </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入: </strong>5 <strong>输出: </strong>false</pre>
> 
> <p><strong>进阶：</strong><br> 你能不使用循环或者递归来完成本题吗？</p> </div>


解法一
```cpp
//时间复杂度O(1), 空间复杂度O(1)
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && ((num & (num - 1)) == 0) && ((num & 0x55555555) == num);
    }
};
```

可以用第326题（3的幂）的思路，直接计算、对数法、整除法。
但由于数据存储都是二进制，使得4的幂跟2的幂都有些特别，2的幂所有二进制位中位为1的个数是1，而4的幂（肯定也是2的幂）除此之外另有特点，它的1的位总是出现在奇数位上（从低位算起，1D = 0000 0001B, 4D = 0000 0100B, 16D = 0001 0000B）。
针对这个特点，我们可以用一个“筛子”过滤一下，0x5555 5555 它的二进制表是为 01010101 01010101 01010101 01010101B，用它与原数进行按位与运算，如果结果不变，结合之前它是2的幂的判断，说明是；否则不是。

<div style="text-align: right"> 2019/04/30 23:08  </div>