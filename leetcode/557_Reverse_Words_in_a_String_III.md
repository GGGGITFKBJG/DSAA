### 557. 反转字符串中的单词 III

> <div class="content__2ebE"><p>给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre>输入: "Let's take LeetCode contest"
> 输出: "s'teL ekat edoCteeL tsetnoc"<strong><strong><strong>&nbsp;</strong></strong></strong>
> </pre>
> 
> <p><strong><strong><strong><strong>注意：</strong></strong></strong></strong>在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。</p>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    string reverseWords(string s) {
        int idx = 0, i, j;
        while(idx < s.size()) {
            i = idx;
            while(idx < s.size() && s[idx++] != ' ');
            if(idx < s.size()) j = idx - 2;
            else j = s.size() - 1;//idx到达右边界
            while(i < j) {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++, j--;
            }
        }
        return s;
    }
};
```

思路：
双指针法，与题541类似。
1. idx始终指向下一个单词的首字母；
2. i、j所指的子串是要反转的单词，i初始化为idx。因为题上说没有多余的空格，所以可以用idx - 2来初始化j。注意处理idx到达右边界时的情况。
3. idx每次向后移一个单词，直到遍历完成，返回s。

<div style="text-align: right"> 2019/05/31 21:18 </div>