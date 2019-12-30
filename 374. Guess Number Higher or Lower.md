### 374. 猜数字大小

> <div class="content__2ebE"><p>我们正在玩一个猜数字游戏。 游戏规则如下：<br>
> 我从&nbsp;<strong>1</strong>&nbsp;到&nbsp;<em><strong>n</strong></em>&nbsp;选择一个数字。
> 你需要猜我选择了哪个数字。<br> 每次你猜错了，我会告诉你这个数字是大了还是小了。<br>
> 你调用一个预先定义好的接口&nbsp;<code>guess(int num)</code>，它会返回 3
> 个可能的结果（<code>-1</code>，<code>1</code>&nbsp;或 <code>0</code>）：</p>
> 
> <pre>-1 : 我的数字比较小  
>  1 : 我的数字比较大  
>  0 : 恭喜！你猜对了！ </pre>
> 
> <p><strong>示例 :</strong></p>
> 
> <pre><strong>输入: </strong>n = 10, pick = 6 
> <strong>输出: </strong>6</pre> </div>

解法一
```cpp
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(guess(mid) < 0) high = mid - 1;
            else if(guess(mid) > 0) low = mid + 1;
            else return mid;
        }
        return low > n ? n : low;
    }
};
```

二分法。最后一行，如果选定的数字不在范围内，那就返回左或右边界，没有什么意义。

<div style="text-align: right"> 2019/05/01 14:00  </div>
