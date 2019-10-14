### 541. 反转字符串 II

> <div class="content__2ebE"><p>给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> s = "abcdefg", k = 2
> <strong>输出:</strong> "bacdfeg"
> </pre>
> 
> <p><strong>要求:</strong></p>
> 
> <ol>
> 	<li>该字符串只包含小写的英文字母。</li>
> 	<li>给定字符串的长度和 k 在[1, 10000]范围内。</li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    string reverseStr(string s, int k) {
        int idx = 0;
        while(idx < s.size()) {
            int i = idx;
            int j = idx + k - 1 < s.size() ? idx + k - 1 : s.size() - 1;
            for(; i < j; i++, j--) {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
            idx += 2 * k;
        }
        return s;
    }
};
```

解法一
双指针法：
1. 指针 i，j 分别指向子串的头和尾，负责交换要反转的子串。i 每次初始化为idx，j 如果超过了原字符串的右边界，则初始化为指向最后一个元素，否则它指向idx + k - 1；
2. idx负责找到第2k个位置，每次向后移动2k，直到idx超出右边界。


<div style="text-align: right"> 2019/05/31 19:32 </div>