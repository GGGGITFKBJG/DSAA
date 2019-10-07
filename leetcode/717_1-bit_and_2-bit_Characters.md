### 717. 1比特与2比特字符

> <div class="content__2ebE"><p>有两种特殊字符。第一种字符可以用一比特<code>0</code>来表示。第二种字符可以用两比特(<code>10</code>&nbsp;或&nbsp;<code>11</code>)来表示。</p>
> 
> <p>现给一个由若干比特组成的字符串。问最后一个字符是否必定为一个一比特字符。给定的字符串总是由0结束。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> 
> bits = [1, 0, 0]
> <strong>输出:</strong> True
> <strong>解释:</strong> 
> 唯一的编码方式是一个两比特字符和一个一比特字符。所以最后一个字符是一比特字符。
> </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> 
> bits = [1, 1, 1, 0]
> <strong>输出:</strong> False
> <strong>解释:</strong> 
> 唯一的编码方式是两比特字符和两比特字符。所以最后一个字符不是一比特字符。
> </pre>
> 
> <p><strong>注意:</strong></p>
> 
> <ul>
> 	<li><code>1 &lt;= len(bits) &lt;= 1000</code>.</li>
> 	<li><code>bits[i]</code> 总是<code>0</code> 或&nbsp;<code>1</code>.</li>
> </ul>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int p = 0, n = bits.size();
        while(p != n - 1 && p != n) {
            if(bits[p] == 1) p += 2;
            else p++;
        }
        return p == n - 1;
    }
};
```

设置一个指针p，从头向后遍历。如果遇到的是1，则向后移动两个位置；如果遇到0，就向后移一个位置。

判断最后是否指向最后一个元素，是则返回true；否则false。

<div style="text-align: right"> 2019/06/27 13:26 </div>