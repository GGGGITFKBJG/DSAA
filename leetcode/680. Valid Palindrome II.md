### 680. 验证回文字符串 Ⅱ

> <div class="content__2ebE"><p>给定一个非空字符串&nbsp;<code>s</code>，<strong>最多</strong>删除一个字符。判断是否能成为回文字符串。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> "aba"
> <strong>输出:</strong> True
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> "abca"
> <strong>输出:</strong> True
> <strong>解释:</strong> 你可以删除c字符。
> </pre>
> 
> <p><strong>注意:</strong></p>
> 
> <ol>
> 	<li>字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。</li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j && s[i] == s[j]) i++, j--;
        return i >= j;
    }
    
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j && s[i] == s[j]) i++, j--;
        if(i >= j) return true;
        return isPalindrome(s.substr(i, j - i)) || isPalindrome(s.substr(i + 1, j - i));
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j && s[i] == s[j]) i++, j--;
        if(i >= j) return true;
        
        int l = i + 1, r = j;
        while(l < r && s[l] == s[r]) l++, r--;
        if(l >= r) return true;
        
        l = i, r = j - 1;
        while(l < r && s[l] == s[r]) l++, r--;
        return l >= r;
    }
};
```

解法一

1. 函数isPalindrome判断字符串s是否为回文串；
2. 主函数validPalindrome使用指针i和j，从左右两边同时向内遍历，判断s[i]是否等于s[j]，遇到以下情况之一时停止遍历：
***<pre>①i > j；
    ②s[i] != s[j]。</pre>***
3. 之后检查i、j的值，若i >= j，说明已经遍历完整个字符串且是回文串，返回true；
4. 若i < j，说明有不符合回文串规则的字符，此时我们调用isPalindrome，分别检查删掉s[i]和删掉s[j]这两种情况是否能构成回文串，若有返回true；无则返回true。

解法二

不使用额外的辅助函数，效率更好一些。

<div style="text-align: right"> 2019/06/18 23:22 </div>