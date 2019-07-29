### 476. 数字的补数
> <div class="content__2ebE"><div><p>给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。</p>
> 
> <p><strong>注意:</strong></p>
> 
> <ol>
> 	<li>给定的整数保证在32位带符号整数的范围内。</li>
> 	<li>你可以假定二进制数不包含前导零位。</li>
> </ol>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> 5
> <strong>输出:</strong> 2
> <strong>解释:</strong> 5的二进制表示为101（没有前导零位），其补数为010。所以你需要输出2。
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> 1
> <strong>输出:</strong> 0
> <strong>解释:</strong> 1的二进制表示为1（没有前导零位），其补数为0。所以你需要输出0。
> </pre>
> </div></div>

解法一
```cpp
//时间复杂度O(logn), 空间复杂度O(1)
class Solution {
public:
    int findComplement(int num) {
        int m = 0x40000000, count = 30;
        while((num & m) >> count-- == 0) m >>= 1;
        m = m - 1 + m;
        return num ^ m;
    }
};
```

解法二
```cpp
//时间复杂度O(logn), 空间复杂度O(1)
class Solution {
public:
    int findComplement(int num) {
        int temp = num, m = 0;
        while(temp > 0) {
            temp >>= 1;
            m = (m << 1) + 1;
        }
        return num ^ m;
    }
};
```

思路：
解法一和解法二思路类似，都是先对输入的num作计数，统计出其有效的位（有效位是指从第一个非0的位开始到末尾的位），然后对其有效位作按位取反（使用位1进行异或运算）。

<div style="text-align: right"> 2019/05/09 19:08 </div>
