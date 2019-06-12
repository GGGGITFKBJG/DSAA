### 191. 位1的个数

> <div class="content__2ebE"><p>编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为
> ‘1’&nbsp;的个数（也被称为<a
> href="https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E9%87%8D%E9%87%8F">汉明重量</a>）。</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例 1：</strong></p>
> 
> <pre><strong>输入：</strong>00000000000000000000000000001011
> <strong>输出：</strong>3 <strong>解释：</strong>输入的二进制串
> <code><strong>00000000000000000000000000001011</strong>&nbsp;中，共有三位为
> '1'。</code> </pre>
> 
> <p><strong>示例 2：</strong></p>
> 
> <pre><strong>输入：</strong>00000000000000000000000010000000
> <strong>输出：</strong>1 <strong>解释：</strong>输入的二进制串
> <strong>00000000000000000000000010000000</strong>&nbsp;中，共有一位为 '1'。
> </pre>
> 
> <p><strong>示例 3：</strong></p>
> 
> <pre><strong>输入：</strong>11111111111111111111111111111101
> <strong>输出：</strong>31 <strong>解释：</strong>输入的二进制串
> <strong>11111111111111111111111111111101</strong> 中，共有 31 位为
> '1'。</pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>提示：</strong></p>
> 
> <ul> 	<li>请注意，在某些语言（如
> Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。</li>
> 	<li>在 Java 中，编译器使用<a
> href="https://baike.baidu.com/item/二进制补码/5295284">二进制补码</a>记法来表示有符号整数。因此，在上面的&nbsp;<strong>示例
> 3</strong>&nbsp;中，输入表示有符号整数 <code>-3</code>。</li> </ul>
> 
> <p>&nbsp;</p>
> 
> <p><strong>进阶</strong>:<br> 如果多次调用这个函数，你将如何优化你的算法？</p> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};
```

解法二
```cpp
//时间复杂度O(m), 空间复杂度O(1), m是1的个数
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n) {
            res++;
            n &= n - 1;
        }
        return res;
    }
};
```

解法一很常规，挨个统计，输出和即可。
解法二比较巧妙，
1. 循环条件里判断的是n是否为0；
2. 每一步将n与它自身减1取按位与，再赋值给n。这是最关键的一步，它的意义是，这个操作始终会将n低位的1变为0，而高位的1不变。例如1111 & 1110 = 1110，而1110 & 1101 = 1100。
3. 第2步的每一次操作都会使n中的位为1的个数减少1，执行m次以后，n就等于0，返回m即可。
 
 <div style="text-align: right"> 2019/04/27 12:19  </div>