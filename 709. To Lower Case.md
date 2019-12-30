### 709. 转换成小写字母

> <div class="content__2ebE"><p>实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例 1：</strong></p>
> 
> <pre><strong>输入: </strong>"Hello"
> <strong>输出: </strong>"hello"</pre>
> 
> <p><strong>示例 2：</strong></p>
> 
> <pre><strong>输入: </strong>"here"
> <strong>输出: </strong>"here"</pre>
> 
> <p><strong>示例</strong><strong>&nbsp;3：</strong></p>
> 
> <pre><strong>输入: </strong>"LOVELY"
> <strong>输出: </strong>"lovely"
> </pre>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    string toLowerCase(string str) {
        for(char& c : str) if(c >= 'A' && c <= 'Z') c += 32;
        return str;
    }
};
```

简单。只需一次遍历，将大写字母替换成小写即可。

<div style="text-align: right"> 2019/06/26 21:16 </div>