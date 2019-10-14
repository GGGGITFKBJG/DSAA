### 459. 重复的子字符串

> <div
> class="content__2ebE"><p>给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> "abab"
> 
> <strong>输出:</strong> True
> 
> <strong>解释:</strong> 可由子字符串 "ab" 重复两次构成。 </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> "aba"
> 
> <strong>输出:</strong> False </pre>
> 
> <p><strong>示例 3:</strong></p>
> 
> <pre><strong>输入:</strong> "abcabcabcabc"
> 
> <strong>输出:</strong> True
> 
> <strong>解释:</strong> 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
> </pre> </div>

解法一
```cpp
//时间复杂度O(n*m), 空间复杂度O(1)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int subLen = s.size() / 2; subLen > 0; subLen--) {
            if(s.size() % subLen != 0) continue;
            int i = subLen;
            while(i < s.size()) {
                if(s[i] != s[i - subLen]) break;
                i++;
            }
            if(i == s.size()) return true;
        }
        return false;
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 0, j = 1, n = s.size();
        vector<int> dp(n + 1, 0);//索引i之前重复子串的长度
        while(j < n) {
            if(s[i] == s[j]) dp[++j] = ++i;
            else if(i == 0) j++;
            else i = dp[i];//这里是关键
        }
        return dp[n] && dp[n] % (n - dp[n]) == 0;
    }
};
```

解法一
看见这个题就只能想到暴力搜索方法了。假设的子串长度subLen从1开始，如果能被字符串s的长度除尽，就开始匹配，匹配到结束位置则返回false，否则增加子串长度；如果到达s长度的一半时，说明它没有重复子串，返回false。
代码是从s.length() / 2开始到1的，思路相似。差别在于，从1开始的方法最先匹配到最小重复子串（如abababab里的ab），而从s.length() / 2开始的方法最先匹配到最大重复子串（如abababab里的abab）。

解法二
这个解法类似KMP算法，使用一个数组记录下来当不匹配时，指针应该移动到的下一位置。
数组dp的意义是，指针 i 所指的元素之前（不包括 dp[i] ）已经（与s[0]开头的字符串相比）匹配的字符个数为 dp[i]，那么在后续指针 i 遇到不匹配的字符时，它需要移动到索引为dp[i] 的位置（因为 i 之前匹配的字符个数为 dp[i]，不需要从头开始浪费不必要的时间）。
最后的 dp[n] 如果不为0，说明它前dp[n]个字符，与s的前n - dp[n]个字符匹配，这时只需要再判断一下已经匹配的字符个数是否为要匹配的整数倍。

<div style="text-align: right">  2019/05/08 13:04  </div>
