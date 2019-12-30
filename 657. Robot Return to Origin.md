### 657. 机器人能否返回原点

> <div class="content__2ebE"><p>在二维平面上，有一个机器人从原点 (0, 0) 开始。给出它的移动顺序，判断这个机器人在完成移动后是否在<strong>&nbsp;(0, 0) 处结束</strong>。</p>
> 
> <p>移动顺序由字符串表示。字符 move[i] 表示其第 i 次移动。机器人的有效动作有&nbsp;<code>R</code>（右），<code>L</code>（左），<code>U</code>（上）和 <code>D</code>（下）。如果机器人在完成所有动作后返回原点，则返回 true。否则，返回 false。</p>
> 
> <p><strong>注意：</strong>机器人“面朝”的方向无关紧要。 “R” 将始终使机器人向右移动一次，“L” 将始终向左移动等。此外，假设每次移动机器人的移动幅度相同。</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> "UD"
> <strong>输出:</strong> true
> <strong>解释：</strong>机器人向上移动一次，然后向下移动一次。所有动作都具有相同的幅度，因此它最终回到它开始的原点。因此，我们返回 true。</pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> "LL"
> <strong>输出:</strong> false
> <strong>解释：</strong>机器人向左移动两次。它最终位于原点的左侧，距原点有两次 “移动” 的距离。我们返回 false，因为它在移动结束时没有返回原点。</pre>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(char c : moves) {
            if(c == 'U') y++;
            else if(c == 'D') y--;
            else if(c == 'L') x--;
            else x++;
        }
        return !x & !y;
    }
};
```

解法一

使用x、y记录下机器人坐标，计算每次移动后的坐标，遍历完成后检查是否在原点。

<div style="text-align: right"> 2019/06/15 10:03 </div>