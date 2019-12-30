### 205. 同构字符串

> <div
> class="content__2ebE"><p>给定两个字符串&nbsp;<em><strong>s&nbsp;</strong></em>和&nbsp;<strong><em>t</em></strong>，判断它们是否是同构的。</p>
> 
> <p>如果&nbsp;<em><strong>s&nbsp;</strong></em>中的字符可以被替换得到&nbsp;<strong><em>t&nbsp;</em></strong>，那么这两个字符串是同构的。</p>
> 
> <p>所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> <strong><em>s</em></strong> = <code>"egg",
> </code><strong><em>t = </em></strong><code>"add"</code>
> <strong>输出:</strong> true </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> <strong><em>s</em></strong> = <code>"foo",
> </code><strong><em>t = </em></strong><code>"bar"</code>
> <strong>输出:</strong> false</pre>
> 
> <p><strong>示例 3:</strong></p>
> 
> <pre><strong>输入:</strong> <strong><em>s</em></strong> = <code>"paper",
> </code><strong><em>t = </em></strong><code>"title"</code>
> <strong>输出:</strong> true</pre>
> 
> <p><strong>说明:</strong><br>
> 你可以假设&nbsp;<em><strong>s&nbsp;</strong></em>和 <strong><em>t
> </em></strong>具有相同的长度。</p> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> umc1, umc2;
        for(int i = 0; i < s.size(); i++) {
            if(!umc1.count(s[i])) umc1[s[i]] = t[i];
            else if(t[i] != umc1[s[i]]) return false;
            if(!umc2.count(t[i])) umc2[t[i]] = s[i];
            else if(s[i] != umc2[t[i]]) return false;
        }
        return true;
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0};
        for (int i = 0; i < s.size(); ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};
```

解法一
用两个哈希表保存两个字符串的映射关系。之所以用两个而不是一个，是因为映射关系是单向的，即s->t跟t->的映射表是不一样的，但是都必须是一对一的映射（不能多对一，也不能一对多），思路就很清晰了，如上。
解法二
用两个数组代替哈希表，思路类似。

  <div style="text-align: right">    2019/04/27 23:19  </div>