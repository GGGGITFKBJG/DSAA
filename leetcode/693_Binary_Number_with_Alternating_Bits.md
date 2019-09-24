### 693. 交替位二进制数

> <div class="content__2ebE"><p>给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> 5
> <strong>输出:</strong> True
> <strong>解释:</strong>
> 5的二进制数是: 101
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> 7
> <strong>输出:</strong> False
> <strong>解释:</strong>
> 7的二进制数是: 111
> </pre>
> 
> <p><strong>示例&nbsp;3:</strong></p>
> 
> <pre><strong>输入:</strong> 11
> <strong>输出:</strong> False
> <strong>解释:</strong>
> 11的二进制数是: 1011
> </pre>
> 
> <p><strong>&nbsp;示例 4:</strong></p>
> 
> <pre><strong>输入:</strong> 10
> <strong>输出:</strong> True
> <strong>解释:</strong>
> 10的二进制数是: 1010
> </pre>
> </div>

解法一
```cpp
//时间复杂度O(logn), 空间复杂度O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag = (n & 1);//0 or 1
        while(n > 0) {
            if(flag != (n & 1)) return false;
            flag = !flag;
            n >>= 1;
        }
        return true;
    }
};
```

解法二
```cpp
//时间复杂度O(1), 空间复杂度O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {// n ^ (n >> 1) 等于0...1111时,true
        int t = exp2((int)log2(n));
        return ( n ^ (n >> 1) ) == ( t | (t - 1) );
    }
};
```

思路：

解法一

按照题意，依次检查每个位是否是交替位，不是则返回false。

解法二

使用按位异或运算符^，如果它是交替二进制位的数字， n ^ (n >> 1)应该是0...001111.1111的形式（从n最高位起，该位及其右所有位为1）。例如n为5时（为了方便书写，假设n是8位整数，32位同理）：
<pre>
    n            0000 0101
    n>>1         0000 0010
    n^(n>>1)     0000 0111
</pre>

那为了检查n^(n>>1)是否是00000111，需要构造一个t，这个t只有n的最高位为1，其余位都为0
```cpp
t = exp2((int)log2(n));
```
n为5时，t等于0000 0100。则n=5时，下列表达式为0000 0111：
```cpp
t | (t - 1)
```
t | (t - 1)表示，从n最高位开始，最高位及右边所有位都为1。可以用它来检查n ^ (n >> 1)。返回二者是否相等。

<div style="text-align: right"> 2019/06/22 18:16 </div>