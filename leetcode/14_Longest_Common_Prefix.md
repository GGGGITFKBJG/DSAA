### 14. 最长公共前缀
> <div><p>编写一个函数来查找字符串数组中的最长公共前缀。</p>
> 
> <p>如果不存在公共前缀，返回空字符串&nbsp;<code>""</code>。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入: </strong>["flower","flow","flight"]
> <strong>输出:</strong> "fl" </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入: </strong>["dog","racecar","car"] <strong>
> 输出:</strong> "" <strong>
> 解释:</strong> 输入不存在公共前缀。 </pre>
> 
> <p><strong>说明:</strong></p>
> 
> <p>所有输入只包含小写字母&nbsp;<code>a-z</code>&nbsp;。</p> </div>

解法一
```cpp
//时间复杂度O(m*n), 空间复杂度O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";//如果strs为空, 返回
        for(int i = 0; i < strs[0].length(); i++) {//遍历第一行的每一列
            char c = strs[0][i];//记录第一行元素
            for(int j = 1; j < strs.size(); j++) {//遍历每一行
                if( (i == strs[j].length()) ||
                    (strs[j][i] != c) ) {
                    return strs[0].substr(0, i);
                }//该行到末尾 或 该行字符不相同
            }
        }
        return strs[0];
    }
};
```
大体思路：
1. 根据第一行每一个字符，按列遍历；
2. 如果遇到不相同的字符，或者到达某一字符串的结尾，立即返回。
