### 409. 最长回文串
> <div class="notranslate"><p>给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。</p>
> 
> <p>在构造过程中，请注意区分大小写。比如&nbsp;<code>"Aa"</code>&nbsp;不能当做一个回文字符串。</p>
> 
> <p><strong>注意:</strong><br>
> 假设字符串的长度不会超过 1010。</p>
> 
> <p><strong>示例 1: </strong></p>
> 
> <pre>输入:
> "abccccdd"
> 
> 输出:
> 7
> 
> 解释:
> 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
> </pre>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> um;
        for(char c : s) ++um[c];
        int count = 0;
        bool odd = false;
        for(auto it = um.begin(); it != um.end(); it++) {
            count += it->second / 2;
            if(!odd && it->second % 2 != 0) odd = true;
        }
        return odd ? count * 2 + 1 : count * 2;
    }
};
```

这个实现方式有很多，但思路都差不多，总体上就是统计字符串中所含的字符对的个数，若有奇数，则结果再加1。首先统计所有字符数量，对每个字符数量除以2的结果求和，和的2倍就是字符对的个数。最后再用一个bool变量来记录是否有奇数数量的字符，有则结果+1。

<div style="text-align: right"> 2019/05/04 01:09 </div>