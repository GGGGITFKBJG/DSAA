### 389. 找不同

> <div class="content__2ebE"><p>给定两个字符串 <em><strong>s</strong></em> 和
> <em><strong>t</strong></em>，它们只包含小写字母。</p>
> 
> <p>字符串&nbsp;<strong><em>t</em></strong>&nbsp;由字符串&nbsp;<strong><em>s</em></strong>&nbsp;随机重排，然后在随机位置添加一个字母。</p>
> 
> <p>请找出在 <em><strong>t</strong></em> 中被添加的字母。</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre>输入： s = "abcd"    t = "abcde"
> 输出： e
> 解释： 'e' 是那个被添加的字母。 </pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> um;
        for(char c : s) ++um[c];
        for(char c : t) {
            --um[c];
            if(um[c] < 0) return c;
        }
        return '\0';
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0, sum2 = t[t.size() - 1];//int sum = t[t.size() - 1];
        for(int i = 0; i < s.size(); i++) {
            sum1 += s[i];//sum += t[i];
            sum2 += t[i];//sum -= s[i];
        }
        return sum2 - sum1;//return sum;
    }
};
```

解法三
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int diff = t[t.size() - 1];
        for(int i = 0; i < s.size(); i++) {
            diff ^= s[i];
            diff ^= t[i];
        }
        return diff;
    }
};
```

解法一依然是利用哈希表，遍历一次计数，再遍历一次找不同。
解法二比较巧妙，把字符当做整型处理，分别求两个数组的和，用数组2的和减数组1的和，得到的差转为字符，就是答案。优点是省去了额3外的线性空间需求，并且可以一次同时遍历两个数组。缺点是数字如果太大，可能和会溢出。
解法三更巧妙，仍然利用了异或运算的性质，优点是不会溢出。

<div style="text-align: right">2019/05/01 17:59  </div>