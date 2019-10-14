### 383. 赎金信
> <div class="content__2ebE"><p>给定一个赎金信 (ransom)
> 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回
> true ；否则返回 false。</p>
> 
> <p>(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)</p>
> 
> <p><strong>注意：</strong></p>
> 
> <p>你可以假设两个字符串均只含有小写字母。</p>
> 
> <pre>canConstruct("a", "b") -&gt; false canConstruct("aa", "ab") -&gt;
> false canConstruct("aa", "aab") -&gt; true </pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> um;
        for(char c : ransomNote) ++um[c];
        for(char c : magazine) {
            if(um.count(c)) um[c] -= 1;
            if(um[c] == 0) um.erase(c);
        }
        return um.empty();
    }
};
```

再次使用万能的哈希表，将时间降低到线性。
第6行访问一个不存在的键，会直接创建它，并将value的int初始化为0，省去了条件判断。
这个代码提交反馈表示运行速度比较慢（5%），讨论区贴出的一个暴力搜索（O(N^2)）却超过90%，只是因为测试用例的字符串太短了，不要怀疑自己。

<div style="text-align: right">2019/05/01 17:18 </div>