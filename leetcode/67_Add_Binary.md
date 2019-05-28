### 67. 二进制求和

> <div class="content__2ebE"><div><p>给定两个二进制字符串，返回他们的和（用二进制表示）。</p>
> 
> <p>输入为<strong>非空</strong>字符串且只包含数字&nbsp;<code>1</code>&nbsp;和&nbsp;<code>0</code>。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> a = "11", b = "1" <strong>输出:</strong>
> "100"</pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> a = "1010", b = "1011" <strong>输出:</strong>
> "10101"</pre> </div></div>

解法一
```cpp
//时间复杂度O(n^2), 空间复杂度O(n), n = max( a.length(), b.length() )
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res;
        for(int i = 1; i <= a.length() || i <= b.length(); i++) {
            int temp = carry;
            if(i <= a.length()) temp += a[a.length() - i] - '0';
            if(i <= b.length()) temp += b[b.length() - i] - '0';
            res.insert(0, to_string(temp % 2));
            carry = temp / 2;
        }
        if(carry > 0) res.insert(0, "1");
        return res;
    }
};
```

和66题类似，时间复杂度O(n^2)，主要低效在于往string头部插入元素。