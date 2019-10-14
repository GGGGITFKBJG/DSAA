### 20. 有效的括号
> <div class="content__2ebE"><div><p>给定一个只包括
> <code>'('</code>，<code>')'</code>，<code>'{'</code>，<code>'}'</code>，<code>'['</code>，<code>']'</code>&nbsp;的字符串，判断字符串是否有效。</p>
> 
> <p>有效字符串需满足：</p>
> 
> <ol> 	<li>左括号必须用相同类型的右括号闭合。</li> 	<li>左括号必须以正确的顺序闭合。</li> </ol>
> 
> <p>注意空字符串可被认为是有效字符串。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> "()" <strong>
> 输出:</strong> true </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> "()[]{}" <strong>
> 输出:</strong> true </pre>
> 
> <p><strong>示例&nbsp;3:</strong></p>
> 
> <pre><strong>输入:</strong> "(]" <strong>
> 输出:</strong> false </pre>
> 
> <p><strong>示例&nbsp;4:</strong></p>
> 
> <pre><strong>输入:</strong> "([)]" <strong>
> 输出:</strong> false </pre>
> 
> <p><strong>示例&nbsp;5:</strong></p>
> 
> <pre><strong>输入:</strong> "{[]}" <strong>
> 输出:</strong> true</pre>
> </div></div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> um;//保存平衡符号对
        um['('] = ')';
        um['['] = ']';
        um['{'] = '}';
        
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            if(um.count(s[i])) st.push(s[i]);//是开放符号
            else {//是封闭符号
                if(st.empty() || um[st.top()] != s[i]) return false;//栈空或不匹配
                else st.pop();
            }
        }
        return st.empty();//栈空则为true
    }
};
```
这是个经典的平衡符号问题，使用栈，这个问题就变得非常简单：
1. 遍历每一个字符，遇到开放符号（'('、'['、'{'）则入栈；
2. 遇到封闭符号（')'、']'、'}'），对比栈顶元素与该符号是否匹配，匹配则出栈，否则返回false；
3. 到达字符串结尾时，栈空返回true，否则返回false。

题目上说只有这两种符号，所以不用额外的检测。