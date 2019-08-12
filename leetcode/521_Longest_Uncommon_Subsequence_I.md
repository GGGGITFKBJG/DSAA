### 521. 最长特殊序列 Ⅰ
> <div class="content__2ebE"><div><p>给定两个字符串，你需要从这两个字符串中找出最长的特殊序列。最长特殊序列定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。</p>
> 
> <p><strong>子序列</strong>可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。</p>
> 
> <p>输入为两个字符串，输出最长特殊序列的长度。如果不存在，则返回 -1。</p>
> 
> <p><strong>示例 :</strong></p>
> 
> <pre><strong>输入:</strong> "aba", "cdc"
> <strong>输出:</strong> 3
> <strong>解析:</strong> 最长特殊序列可为 "aba" (或 "cdc")
> </pre>
> 
> <p><strong>说明:</strong></p>
> 
> <ol>
> 	<li>两个字符串长度均小于100。</li>
> 	<li>字符串中的字符仅含有&nbsp;'a'~'z'。</li>
> </ol>
> </div></div>

解法一
```cpp
//时间复杂度O(1), 空间复杂度O(1)
class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.size(), b.size());
    }
};
```

这个题目初看很复杂，其实答案很简单：
1. 如果两字符串相等，没有特殊子序列，返回-1；
2. 不相等，特殊子序列就是较长的字符串，返回max(a.size(), b.size())。

<div style="text-align: right"> 2019/05/28 9:29 </div>