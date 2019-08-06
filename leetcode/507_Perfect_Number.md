### 507. 完美数
> <div class="content__2ebE"><div><p>对于一个&nbsp;<strong>正整数</strong>，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。</p>
> 
> <p>给定一个&nbsp;<strong>正整数&nbsp;</strong><code>n</code>，&nbsp;如果他是完美数，返回&nbsp;<code>True</code>，否则返回&nbsp;<code>False</code></p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例：</strong></p>
> 
> <pre><strong>输入:</strong> 28
> <strong>输出:</strong> True
> <strong>解释:</strong> 28 = 1 + 2 + 4 + 7 + 14
> </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>注意:</strong></p>
> 
> <p>输入的数字&nbsp;<strong><code>n</code></strong> 不会超过 100,000,000. (1e8)</p>
> </div></div>

解法一
```cpp
//时间复杂度O(sqrt(n)), 空间复杂度O(1)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1) return false;
        int sum = 0;
        int factor = sqrt(num);
        while(factor > 0) {
            if(num % factor == 0) sum += (factor + num / factor);
            factor--;
        }
        return num == sum / 2;
    }
};
```

本题与之前求因数的思路类似，只不过多了个累加的过程。从sqrt(num)开始（而不是从num - 1开始）是为了尽量节省计算量。

<div style="text-align: right"> 2019/05/25 22:14 </div>