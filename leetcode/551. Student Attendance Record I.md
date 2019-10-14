### 551. 学生出勤记录 I

> <div class="content__2ebE"><p>给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：</p>
> 
> <ol>
> 	<li><strong>'A'</strong> : Absent，缺勤</li>
> 	<li><strong>'L'</strong> : Late，迟到</li>
> 	<li><strong>'P'</strong> : Present，到场</li>
> </ol>
> 
> <p>如果一个学生的出勤记录中不<strong>超过一个'A'(缺勤)</strong>并且<strong>不超过两个连续的'L'(迟到)</strong>,那么这个学生会被奖赏。</p>
> 
> <p>你需要根据这个学生的出勤记录判断他是否会被奖赏。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> "PPALLP"
> <strong>输出:</strong> True
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> "PPALLL"
> <strong>输出:</strong> False
> </pre>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    bool checkRecord(string s) {
        int abasent = 0, late = 0;
        for(char r : s) {
            if(r == 'L') late++;
            else late = 0;
            if(r == 'A') abasent++;
            if(abasent == 2 || late == 3) return false;
        }
        return true;
    }
};
```

思路：
变量abasent记录字符'A'出现的总次数，变量late记录字符'L'连续出现的次数，对原字符串遍历，如果abasent到达2，或者late到3，返回false。否则遍历完成返回true。

<div style="text-align: right"> 2019/05/31 20:56 </div>