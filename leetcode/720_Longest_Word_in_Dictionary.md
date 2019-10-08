### 720. 词典中最长的单词

> <div class="content__2ebE"><p>给出一个字符串数组<code>words</code>组成的一本英语词典。从中找出最长的一个单词，该单词是由<code>words</code>词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。</p>
> 
> <p>若无答案，则返回空字符串。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> 
> words = ["w","wo","wor","worl", "world"]
> <strong>输出:</strong> "world"
> <strong>解释:</strong> 
> 单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> 
> words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
> <strong>输出:</strong> "apple"
> <strong>解释:</strong> 
> "apply"和"apple"都能由词典中的单词组成。但是"apple"得字典序小于"apply"。
> </pre>
> 
> <p><strong>注意:</strong></p>
> 
> <ul>
> 	<li>所有输入的字符串都只包含小写字母。</li>
> 	<li><code>words</code>数组长度范围为<code>[1,1000]</code>。</li>
> 	<li><code>words[i]</code>的长度范围为<code>[1,30]</code>。</li>
> </ul>
> </div>

解法一
```cpp
//时间复杂度O(nlogn), 空间复杂度O(n)
class Solution {
public:
    string longestWord(vector<string>& words) {
        string res = "";
        sort(words.begin(), words.end());
        unordered_set<string> us;
        for(string word : words) {
            if(word.size() == 1 || us.count(word.substr(0, word.size() - 1))) {
                us.insert(word);
                if(word.size() > res.size()) res = word;
            }
        }
        return res;
    }
};
```

先对输入字符串数组按增序排序，再遍历排序后的数组。使用一个哈希表保存满足递进要求的单词。

在遍历过程中只要判断当前字符串去掉最末尾的字符的子串是否在哈希表中即可（因为遍历的数组是有序的，且是从长度1开始逐步增加的）。用res记录下哈希表中出现过的长度最长的字符串。最后返回。

<div style="text-align: right"> 2019/06/27 13:39 </div>