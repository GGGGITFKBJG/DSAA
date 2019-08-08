### 520. 检测大写字母
> <div class="content__2ebE"><div><p>给定一个单词，你需要判断单词的大写使用是否正确。</p>
> 
> <p>我们定义，在以下情况时，单词的大写用法是正确的：</p>
> 
> <ol>
> 	<li>全部字母都是大写，比如"USA"。</li>
> 	<li>单词中所有字母都不是大写，比如"leetcode"。</li>
> 	<li>如果单词不只含有一个字母，只有首字母大写，&nbsp;比如&nbsp;"Google"。</li>
> </ol>
> 
> <p>否则，我们定义这个单词没有正确使用大写字母。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> "USA"
> <strong>输出:</strong> True
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> "FlaG"
> <strong>输出:</strong> False
> </pre>
> 
> <p><strong>注意:</strong> 输入是由大写和小写拉丁字母组成的非空单词。</p>
> </div></div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int detect(const string& word) {
        char last = word[word.size() - 1];
        bool isCapital = last >= 'A' && last <= 'Z';
        for(int i = 1; i < word.size() - 1; i++) {
            if(isCapital != (word[i] >= 'A' && word[i] <= 'Z')) return 0;
        }
        if(isCapital) return 1;
        return -1;
    }
    bool detectCapitalUse(string word) {
        if(detect(word) == 0) return false;
        if(detect(word) < 0 ) return true;
        return word[0] >= 'A' && word[0] <= 'Z';
    }
};
```

detect函数检测除首元素外的单词，若全为小写返回-1，全大写返回1，否则返回0。这样只用考虑返回值与首元素的关系：
1. detect返回0时始终为false；
2. detect返回1且首元素大写时为true；
3. detect返回-1时始终为true。

<div style="text-align: right"> 2019/05/25 23:48 </div>
