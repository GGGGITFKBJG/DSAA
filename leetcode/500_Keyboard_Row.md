### 500. 键盘行
> <div class="content__2ebE"><div><p>给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。</p>
> 
> <p>&nbsp;</p>
> 
> <p><img alt="American keyboard" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/keyboard.png" style="width: 100%; max-width: 600px"></p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例：</strong></p>
> 
> <pre><strong>输入:</strong> ["Hello", "Alaska", "Dad", "Peace"]
> <strong>输出:</strong> ["Alaska", "Dad"]
> </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>注意：</strong></p>
> 
> <ol>
> 	<li>你可以重复使用键盘上同一字符。</li>
> 	<li>你可以假设输入的字符串将只包含字母。</li>
> </ol></div></div>

解法一
```cpp
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> us1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> us2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> us3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        vector<string> res;
        for(string word : words) {
            bool print = true;
            if(word.size() == 0) continue;
            unordered_set<char> temp;
            if(us1.count(word[0]) || us1.count(word[0] + 32)) temp = us1;
            else if(us2.count(word[0]) || us2.count(word[0] + 32)) temp = us2;
            else temp = us3;
            for(char c : word) {
                if(!temp.count(c) && !temp.count(c + 32)) {
                    print = false;
                    break;
                }
            }
            if(print) res.push_back(word);
        }
        return res;
    }
};
```

用三个哈希表存下键盘三行的字母，依次判断每一个单词，如果可以完全用一行的元素表示，就把它存入res中。
<div style="text-align: right"> 2019/05/14 23:45 </div>