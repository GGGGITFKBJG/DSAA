### 58. 最后一个单词的长度

> <div class="content__2ebE"><div><p>给定一个仅包含大小写字母和空格&nbsp;<code>'
> '</code>&nbsp;的字符串，返回其最后一个单词的长度。</p>
> 
> <p>如果不存在最后一个单词，请返回 0&nbsp;。</p>
> 
> <p><strong>说明：</strong>一个单词是指由字母组成，但不包含任何空格的字符串。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> "Hello World" <strong>输出:</strong> 5 </pre>
> </div></div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int count = 0;
        while(i >= 0 && s[i] == 32) i--;
        while(i >= 0 && s[i--] != 32) count++;
        return count;
    }
};
```

反向遍历，遇到第一个非空格字符开始计数，遇到字格字符停止计数并返回。