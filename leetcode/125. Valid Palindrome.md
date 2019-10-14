### 125. 验证回文串

> <div
> class="content__2ebE"><p>给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。</p>
> 
> <p><strong>说明：</strong>本题中，我们将空字符串定义为有效的回文串。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> "A man, a plan, a canal: Panama"
> <strong>输出:</strong> true </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> "race a car" <strong>输出:</strong> false
> </pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    bool isLetter(char c) {
        return c >= 'A' && c <= 'Z' ||
               c >= 'a' && c <= 'z';
    }
    bool isNumber(char c) {
        return c >= '0' && c <= '9';
    }
    bool isPalindrome(string s) {
        int i = 0, j = (int)s.length() - 1;
        while(i < j) {
            while(i < s.length() &&
                  !isLetter(s[i]) && !isNumber(s[i])) i++;
            if(i == s.length()) return true;//全部非字母非数字
            while(j >= 0 && !isLetter(s[j]) && !isNumber(s[j])) j--;
            if(s[i] == s[j] ||
               isLetter(s[i]) && isLetter(s[j]) &&
               abs(s[i] - s[j]) == 'a' - 'A') {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};
```

踩坑经验：
1. 双指针从左、右相向遍历，判断是否相等，直到相遇。
2. 不同的是，此题要求忽略非字母非数字字符，只需每次跳过这些字符，但要注意处理全部为非字母非数字字符（相当于空字符串）。
3. 另外，题目要求字母忽略大小写，判断大小写不能只判断两字符的距离，先要保证两个字符都为字母，因为数字0与字母P相距32，刚好是同一字母大小写的距离。
     
<div style="text-align: right">  2019/04/24 10:38  </div>