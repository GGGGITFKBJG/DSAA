### 190. 颠倒二进制位

> <div class="content__2ebE"><p>颠倒给定的 32 位无符号整数的二进制位。</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例 1：</strong></p>
> 
> <pre><strong>输入:</strong> 00000010100101000001111010011100
> <strong>输出:</strong> 00111001011110000010100101000000 <strong>解释:
> </strong>输入的二进制串 <strong>00000010100101000001111010011100
> </strong>表示无符号整数<strong> 43261596</strong><strong>， </strong>     
> 因此返回 964176192，其二进制表示形式为
> <strong>00111001011110000010100101000000</strong>。</pre>
> 
> <p><strong>示例 2：</strong></p>
> 
> <pre><strong>输入：</strong>11111111111111111111111111111101
> <strong>输出：</strong>10111111111111111111111111111111
> <strong>解释：</strong>输入的二进制串
> <strong>11111111111111111111111111111101</strong> 表示无符号整数 4294967293，
> &nbsp;     因此返回 3221225471 其二进制表示形式为
> <strong>10101111110010110010011101101001。</strong></pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>提示：</strong></p>
> 
> <ul> 	<li>请注意，在某些语言（如
> Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。</li>
> 	<li>在 Java 中，编译器使用<a
> href="https://baike.baidu.com/item/二进制补码/5295284">二进制补码</a>记法来表示有符号整数。因此，在上面的&nbsp;<strong>示例
> 2</strong>&nbsp;中，输入表示有符号整数 <code>-3</code>，输出表示有符号整数
> <code>-1073741825</code>。</li> </ul>
> 
> <p>&nbsp;</p>
> 
> <p><strong>进阶</strong>:<br> 如果多次调用这个函数，你将如何优化你的算法？</p> </div></div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int count = 32;
        while(count--) {
            res <<= 1;
            res |= n & 1;
            n >>= 1;
        }
        return res;
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        uint32_t left = 0x80000000, right = 0x00000001;
        int count = 31;
        while(left > right) {
            res |= (left & n) >> count;
            res |= (right & n) << count;
            count -= 2;
            left >>= 1;
            right <<= 1;
        }
        return res;
    }
};
```

解法一反复对n右移，对1求按位与，再与res求按位或。
刚开始没有经验，写的是解法二，用了反转数组的思路，两个额外变量作指针，向内遍历。

 <div style="text-align: right">  2019/04/27 12:19  </div>