### 387. 字符串中的第一个唯一字符
> <div class="content__2ebE"><p>给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回
> -1。</p>
> 
> <p><strong>案例:</strong></p>
> 
> <pre>s = "leetcode" 返回 0.
> 
> s = "loveleetcode", 返回 2. </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>注意事项：</strong>您可以假定该字符串只包含小写字母。</p> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> um;
        for(char c : s) ++um[c];
        for(int i = 0; i < s.length(); i++) {
            if(um[s[i]] == 1) return i;
        }
        return -1;
    }
};
```

遍历两次字符串。第一次统计字符个数，存储在哈希表中；第二次找首个个数为1的元素，返回。

<div style="text-align: right">2019/05/01 17:37  </div>
