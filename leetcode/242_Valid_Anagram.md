### 242. 有效的字母异位词

> <div class="content__2ebE"><p>给定两个字符串 <em>s</em> 和 <em>t</em>
> ，编写一个函数来判断 <em>t</em> 是否是 <em>s</em> 的字母异位词。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> <em>s</em> = "anagram", <em>t</em> =
> "nagaram" <strong>输出:</strong> true </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> <em>s</em> = "rat", <em>t</em> = "car"
> <strong>输出: </strong>false</pre>
> 
> <p><strong>说明:</strong><br> 你可以假设字符串只包含小写字母。</p>
> 
> <p><strong>进阶:</strong><br> 如果输入字符串包含 unicode
> 字符怎么办？你能否调整你的解法来应对这种情况？</p> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int rec[26] = {0};//初始化全为0
        for(int i  = 0; i < s.size(); i++) {
            rec[s[i] - 'a'] += 1;
            rec[t[i] - 'a'] -= 1;
        }
        for(int i = 0; i < 26; i++) {
            if(rec[i] != 0) return false;
        }
        return true;
    }
};
```

思路是用两个哈希表保存两字符串中出现过字母的个数，最后对比两字符串中所有字母出现个数是否全都相同。但题上说只有小写字母，那可以用长26整型数组来代替。还可以简化一下，以上解法只用了一个额外的数组：
1. 使用一个数组rec记录字母的个数，索引0-25对应26个字母，初始化全为0；同时遍历s和t；
2. 若在s中遇到字符a，就在数组对应a的位置加1；若在t中遇到字符b，就在数组中对应b的位置减1；
3. 遍历完成后，检查数组rec中是否全为0，是则返回true，否则为false。

<div style="text-align: right"> 2019/04/29 13:03  </div>