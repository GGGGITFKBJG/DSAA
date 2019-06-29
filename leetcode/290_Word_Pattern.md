### 290. 单词模式

> <div class="content__2ebE"><p>给定一种规律
> <code>pattern</code>&nbsp;和一个字符串&nbsp;<code>str</code>&nbsp;，判断
> <code>str</code> 是否遵循相同的规律。</p>
> 
> <p>这里的&nbsp;<strong>遵循&nbsp;</strong>指完全匹配，例如，&nbsp;<code>pattern</code>&nbsp;里的每个字母和字符串&nbsp;<code>str</code><strong>&nbsp;</strong>中的每个非空单词之间存在着双向连接的对应规律。</p>
> 
> <p><strong>示例1:</strong></p>
> 
> <pre><strong>输入:</strong> pattern = "abba", str = "dog cat cat dog" <strong>
> 输出:</strong> true</pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong>pattern = "abba", str = "dog cat cat fish" <strong>
> 输出:</strong> false</pre>
> 
> <p><strong>示例 3:</strong></p>
> 
> <pre><strong>输入:</strong> pattern =  "aaaa", str = "dog cat cat dog" <strong>
> 输出:</strong> false</pre>
> 
> <p><strong>示例&nbsp;4:</strong></p>
> 
> <pre><strong>输入:</strong> pattern = "abba", str = "dog dog dog dog" <strong>
> 输出:</strong> false</pre>
> 
> <p><strong>说明:</strong><br>
> 你可以假设&nbsp;<code>pattern</code>&nbsp;只包含小写字母，&nbsp;<code>str</code>&nbsp;包含了由单个空格分隔的小写字母。&nbsp;
> &nbsp;&nbsp;</p> </div>

解法一
```cpp
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream iss(str);
        unordered_map<char, string> um;
        string temp;
        for(char c : pattern) {
            if(iss.eof()) return false;
            iss >> temp;
            if(um.count(c)) {//pattern字符出现过
                if(temp.compare(um[c]) != 0) return false;//比较字符串str
            }
            else {//pattern字符没有出现过
                for(auto it = um.begin(); it != um.end(); it++) {
                    if(temp.compare(it->second) == 0) return false;//检查str字符串是否出现过
                }
                um[c] = temp;//也没出现过, 将键值存入um
            }
        }
        return iss.eof();
        
    }
};
```

1. 使用一个哈希表，存储的键值分别记录pattern（单个字符c）和 str（分割后的单词temp）。
2. 遍历pattern中的每一个字符，若过程中遇到temp为空（str的istringstream流提前到达结尾），说明单词个数小于pattern的字符数，返回false；
3. 若字符c没有在哈希表中出现过，检查c对应的单词temp是否在哈希表中出现过，若出现过，说明一个单词对应两个c，返回false；
4. 若字符c出现过，检查对应的单词是否与哈希表中记录的一致，若不一致说明一个c对应了两个单词，返回false；
5. 其他情况继续向后遍历pattern，直到遍历结束，检查temp是否为空（str的istringstream是否到达结尾）；若到结尾说明pattern和单词个数对应上了，返回true。

检查temp是否在哈希表中出现过，需要对um一次遍历，比较低效。改进的方法是使用两个哈希表，分别以patterns和words为键，存储两组映射，这样检查只需要常数时间，代价是空间需求加倍。

<div style="text-align: right"> 2019/04/30 13:07 </div>