## 438. 找到字符串中所有字母异位词

> <div
> class="content__2ebE"><p>给定一个字符串&nbsp;<strong>s&nbsp;</strong>和一个非空字符串&nbsp;<strong>p</strong>，找到&nbsp;<strong>s&nbsp;</strong>中所有是&nbsp;<strong>p&nbsp;</strong>的字母异位词的子串，返回这些子串的起始索引。</p>
> 
> <p>字符串只包含小写英文字母，并且字符串&nbsp;<strong>s&nbsp;</strong>和
> <strong>p&nbsp;</strong>的长度都不超过 20100。</p>
> 
> <p><strong>说明：</strong></p>
> 
> <ul> 	<li>字母异位词指字母相同，但排列不同的字符串。</li> 	<li>不考虑答案输出的顺序。</li> </ul>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> s: "cbaebabacd" p: "abc"
> 
> <strong>输出:</strong> [0, 6]
> 
> <strong>解释:</strong> 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。 起始索引等于 6
> 的子串是 "bac", 它是 "abc" 的字母异位词。 </pre>
> 
> <p><strong>&nbsp;示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> s: "abab" p: "ab"
> 
> <strong>输出:</strong> [0, 1, 2]
> 
> <strong>解释:</strong> 起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。 起始索引等于 1 的子串是
> "ba", 它是 "ab" 的字母异位词。 起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。 </pre>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> um, um2;
        for(int i = 0; i < p.length(); i++) {
            ++um[p[i]];
            ++um2[s[i]];
        }
        if(um2 == um) res.push_back(0);
        for(int i = 1; i <= (int)(s.length() - p.length()); i++) {
            if(um2[s[i - 1]] == 1) um2.erase(s[i - 1]);
            else --um2[s[i - 1]];
            ++um2[s[i + p.length() - 1]];
            if(um2 == um) res.push_back(i);
        }
        return res;
    }
};
```

使用两个哈希表，um存储字符串p中字母出现的次数，um2存储字符串s的子串中字母出现的次数。首先初始化um和um2，然后遍历字符串s，每次删去前一个字符，增加后一个字符。判断um、um2是否一致，若是存入res。遍历完成后返回res。
此题若采用笨办法，当输入过多时会超时，虽然这样的代码看起来简洁，但存在重复计算：
```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> um;
        for(char c : p) ++um[c];
        for(int i = 0; i <= (int)(s.size() - p.size()); i++) {
            unordered_map<char, int> um2;
            for(int j = 0; j < p.size(); j++) ++um2[s[i + j]];
            if(um2 == um) res.push_back(i);
        }
        return res;
    }
};
```

还是效率第一位。                         
<div style="text-align: right">   2019/05/05 19:05    </div>       
