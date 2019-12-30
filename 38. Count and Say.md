### 38. 报数

> <div
> class="content__2ebE"><div><p>报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：</p>
> 
> <pre>1.     1
> 2.     11
> 3.     21
> 4.     1211
> 5.     111221 </pre>
> 
> <p><code>1</code>&nbsp;被读作&nbsp;&nbsp;<code>"one
> 1"</code>&nbsp;&nbsp;(<code>"一个一"</code>) ,
> 即&nbsp;<code>11</code>。<br> <code>11</code> 被读作&nbsp;<code>"two
> 1s"</code>&nbsp;(<code>"两个一"</code>）, 即&nbsp;<code>21</code>。<br>
> <code>21</code> 被读作&nbsp;<code>"one 2"</code>, &nbsp;"<code>one
> 1"</code>&nbsp;（<code>"一个二"</code>&nbsp;,&nbsp;&nbsp;<code>"一个一"</code>)&nbsp;,
> 即&nbsp;<code>1211</code>。</p>
> 
> <p>给定一个正整数 <em>n</em>（1 ≤&nbsp;<em>n</em>&nbsp;≤ 30），输出报数序列的第
> <em>n</em> 项。</p>
> 
> <p>注意：整数顺序将表示为一个字符串。</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> 1 <strong>输出:</strong> "1" </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> 4 <strong>输出:</strong> "1211" </pre>
> </div></div>

解法一
```cpp
class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for(int i = 0; i < n - 1; i++) {//执行n - 1次
            string str2;
            char c = str[0];
            int count = 0;
            int j = 0;
            while(true) {
                while(j < str.length() && c == str[j]) {
                    count++;
                    j++;
                }
                str2 += to_string(count) + c;
                if(j >= str.length()) break;
                c = str[j];
                count = 0;
            }
            str = str2;
        }
        return str;
    }
};
```
刚开始题目没看太懂，后来才知道，报数的后一个人，要对上一个人报数字符串的每个字符进行计数，思路就很明白了：
1. 设置一个计数变量count，一个指针j遍历上一个字符串str，新字符串str2保存当前报数字符串；
2. 当j遇到一个新的字符c时，记下，并对其计数，在新字符串str2的尾部添加字符串 [count + 字符c]；
3. 一直进行到str的结尾，此时str2就是当前要报的数；
4. 上述步骤执行n - 1次，就得到第n个人的报数。