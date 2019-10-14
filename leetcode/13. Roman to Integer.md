###  13. 罗马数字转整数
> <html>
> <div><p>罗马数字包含以下七种字符:&nbsp;<code>I</code>，&nbsp;<code>V</code>，&nbsp;<code>X</code>，&nbsp;<code>L</code>，<code>C</code>，<code>D</code>&nbsp;和&nbsp;<code>M</code>。</p>
> 
> <pre><strong>字符</strong>          <strong>数值</strong>
> I             1
> V             5 
> X             10 
> L             50 
> C             100 
> D             500 
> M             1000</pre>
> 
> <p>例如， 罗马数字 2 写做&nbsp;<code>II</code>&nbsp;，即为两个并列的 1。12
> 写做&nbsp;<code>XII</code>&nbsp;，即为&nbsp;<code>X</code>&nbsp;+&nbsp;<code>II</code>&nbsp;。
> 27 写做&nbsp;&nbsp;<code>XXVII</code>,
> 即为&nbsp;<code>XX</code>&nbsp;+&nbsp;<code>V</code>&nbsp;+&nbsp;<code>II</code>&nbsp;。</p>
> 
> <p>通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4
> 不写做&nbsp;<code>IIII</code>，而是&nbsp;<code>IV</code>。数字 1 在数字 5
> 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9
> 表示为&nbsp;<code>IX</code>。这个特殊的规则只适用于以下六种情况：</p>
> 
> <ul> 	<li><code>I</code>&nbsp;可以放在&nbsp;<code>V</code>&nbsp;(5)
> 和&nbsp;<code>X</code>&nbsp;(10) 的左边，来表示 4 和 9。</li>
> 	<li><code>X</code>&nbsp;可以放在&nbsp;<code>L</code>&nbsp;(50)
> 和&nbsp;<code>C</code>&nbsp;(100) 的左边，来表示 40 和&nbsp;90。&nbsp;</li>
> 	<li><code>C</code>&nbsp;可以放在&nbsp;<code>D</code>&nbsp;(500)
> 和&nbsp;<code>M</code>&nbsp;(1000) 的左边，来表示&nbsp;400 和&nbsp;900。</li>
> </ul>
> 
> <p>给定一个罗马数字，将其转换成整数。输入确保在 1&nbsp;到 3999 的范围内。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong>&nbsp;"III" <strong>输出:</strong> 3</pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong>&nbsp;"IV" <strong>输出:</strong> 4</pre>
> 
> <p><strong>示例&nbsp;3:</strong></p>
> 
> <pre><strong>输入:</strong>&nbsp;"IX" <strong>输出:</strong> 9</pre>
> 
> <p><strong>示例&nbsp;4:</strong></p>
> 
> <pre><strong>输入:</strong>&nbsp;"LVIII" <strong>输出:</strong> 58
> <strong>解释:</strong> L = 50, V= 5, III = 3. </pre>
> 
> <p><strong>示例&nbsp;5:</strong></p>
> 
> <pre><strong>输入:</strong>&nbsp;"MCMXCIV" <strong>输出:</strong> 1994
> <strong>解释:</strong> M = 1000, CM = 900, XC = 90, IV = 4.</pre> </div>
> </html>

解法一

```cpp
//时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;//保存结果
        for(int i = 0; i < s.length(); i++) {//遍历每一个字符
            switch (s[i]) {
                case 'I':
                    if(i != s.length() - 1 &&
                       (s[i + 1] == 'V') ||
                       (s[i + 1] == 'X')) sum -= 1;//若I在X或V左边, -1
                    else sum += 1;//否则+1
                    break;
                case 'V':
                    sum += 5;
                    break;
                case 'X':
                    if(i != s.length() - 1 &&
                       (s[i + 1] == 'L') ||
                       (s[i + 1] == 'C')) sum -= 10;//若X在L或C左边, -10
                    else sum += 10;//否则+10
                    break;
                case 'L':
                    sum += 50;
                    break;
                case 'C':
                    if(i != s.length() - 1 &&
                       (s[i + 1] == 'D') ||
                       (s[i + 1] == 'M')) sum -= 100;//若C在D或M左边, -100
                    else sum += 100;//否则+100
                    break;
                case 'D':
                    sum += 500;
                    break;
                case 'M':
                    sum += 1000;
                    break;
                default:
                    return 0;
            }
        }
        return sum;
    }
};
```
总结：
这道题不难，只要想明白其中隐含的逻辑关系：
1. I，V，X如果放在右侧表示加相应的权值，且最多相连出现3个；
2. I，V，X如果放在左侧表示减，且I 只能放在 V (5) 和 X (10) 的左边，X 只能放在 L (50) 和 C (100) 的左边，C 只能放在 D (500) 和 M (1000) 的左边；
3. 剩下的数字V，L，D，M只能出现在右侧且最多1个。
4. 不符合上述规则的不是罗马数字。

解题思路就很明白了：
1. 大体上，我们需要求每个字符的带权和， 其中I = 1，V = 5，X = 10，... ，M = 1000。
2. 但是有三个例外，I，X，C这三个字符如果分别出现在V或X，L或C，D或M左边，那么就表示减去相应的权值。
3. 题上没有要求我们判断输入是否为合法的罗马数字，只需输出结果即可。