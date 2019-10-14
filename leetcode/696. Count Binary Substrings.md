### 696. 计数二进制子串

> <div class="content__2ebE"><p>给定一个字符串&nbsp;<code>s</code>，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。</p>
> 
> <p>重复出现的子串要计算它们出现的次数。</p>
> 
> <p><strong>示例 1 :</strong></p>
> 
> <pre><strong>输入:</strong> "00110011"
> <strong>输出:</strong> 6
> <strong>解释:</strong> 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。
> 
> 请注意，一些重复出现的子串要计算它们出现的次数。
> 
> 另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
> </pre>
> 
> <p><strong>示例 2 :</strong></p>
> 
> <pre><strong>输入:</strong> "10101"
> <strong>输出:</strong> 4
> <strong>解释:</strong> 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
> </pre>
> 
> <p><strong>注意：</strong></p>
> 
> <ul>
> 	<li><code>s.length</code>&nbsp;在1到50,000之间。</li>
> 	<li><code>s</code>&nbsp;只包含“0”或“1”字符。</li>
> </ul>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    //#define b(i) (s[i] - '0') //int 0 or 1
    int countBinarySubstrings(string s) {
        int res = 0;
        unordered_map<int, int> um;//bit, count
        um[(s[0] - '0')]++;
        for(int i = 1; i < s.size(); i++) {
            um[(s[i] - '0')]++;
            if(s[i] != s[i - 1]) um[(s[i] - '0')] = 1;
            if(um[(s[i] - '0')] <= um[!(s[i] - '0')]) res++;
        }
        return res;
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur = 1, last = 0, res = 0;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != s[i - 1]) last = cur, cur = 1;
            else cur++;
            if(cur <= last) res++;
        }
        return res;
    }
};
```

思路：

遍历二进制串，使用两个变量对位0和位1计数，一个res记录要返回的值。在遍历过程中，

1. 如果遇到的字符与上一个相同，就对当前字符的计数加1；
2. 如果当前字符与上一个不同，就使反位字符（也就是与当前字符二进制位相反的字符）的计数等于当前字符计数，再使当前字符的计数置1。
3. 在循环的每一步里，检查是否当前字符计数小于反位字符的计数，若是则对res加1。

这样只需要一次遍历即可求出。

解法一与解法二思路相同，解法二使用int变量作计数，更高效一些。

<div style="text-align: right"> 2019/06/22 19:15 </div>