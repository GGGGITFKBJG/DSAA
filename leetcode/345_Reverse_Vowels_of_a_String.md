### 345. 反转字符串中的元音字母

> <div class="content__2ebE"><p>编写一个函数，以字符串作为输入，反转该字符串中的元音字母。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入: </strong>"hello" <strong>输出: </strong>"holle" </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入: </strong>"leetcode" <strong>输出:
> </strong>"leotcede"</pre>
> 
> <p><strong>说明:</strong><br> 元音字母不包含字母"y"。</p> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    Solution() : vowel({'a','e','i','o','u','A','E','I','O','U'}) {}
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            while(i < j && !vowel.count(s[i])) i++;
            while(i < j && !vowel.count(s[j])) j--;
            if(i == j) break;
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return s;
    }
private:
    unordered_set<char> vowel;
};
```

和344很像，循环体内添加两行，先使指针指向下一个元音字母，再交换。

<div style="text-align: right"> 2019/04/30 23:15   </div>