### 171. Excel表列序号

> <div class="content__2ebE"><p>给定一个Excel表格中的列名称，返回其相应的列序号。</p>
> 
> <p>例如，</p>
> 
> <pre>    A -&gt; 1
>     B -&gt; 2
>     C -&gt; 3
>     ...
>     Z -&gt; 26
>     AA -&gt; 27
>     AB -&gt; 28 
>     ... </pre>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> "A" <strong>输出:</strong> 1 </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入: </strong>"AB" <strong>输出:</strong> 28 </pre>
> 
> <p><strong>示例&nbsp;3:</strong></p>
> 
> <pre><strong>输入: </strong>"ZY" <strong>输出:</strong> 701</pre>
> 
> <p><strong>致谢：</strong><br> 特别感谢&nbsp;<a
> href="http://leetcode.com/discuss/user/ts">@ts</a>&nbsp;添加此问题并创建所有测试用例。</p>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int titleToNumber(string s) {
        int temp = s.length() - 1;
        int res = 0;
        for(char c : s) {
            res += (c - 'A' + 1) * pow(26, temp--);
        }
        return res;
    }
};
```

此题比同系列168题容易得多，只需按权值求其字母和即可。

<div style="text-align: right"> 2019/04/27 00:581 </div>