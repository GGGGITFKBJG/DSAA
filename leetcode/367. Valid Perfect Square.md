### 367. 有效的完全平方数

> <div class="content__2ebE"><p>给定一个正整数 <em>num</em>，编写一个函数，如果
> <em>num</em> 是一个完全平方数，则返回 True，否则返回 False。</p>
> 
> <p><strong>说明：</strong>不要使用任何内置的库函数，如&nbsp; <code>sqrt</code>。</p>
> 
> <p><strong>示例 1：</strong></p>
> 
> <pre><strong>输入：</strong>16 
> <strong>输出：</strong>True</pre>
> 
> <p><strong>示例 2：</strong></p>
> 
> <pre><strong>输入：</strong>14 
> <strong>输出：</strong>False </pre> </div>

解法一
```cpp
//时间复杂度O(log(46340)), 空间复杂度O(1)
class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0, high = 46340, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(mid * mid < num) low = mid + 1;
            else if(mid * mid > num) high = mid - 1;
            else return true;
        }
        return false;
    }
};
```

万能的二分法，上限设置为46340（ 46340 = (int)sqrt(INT_MAX) ），O(log2(46340))。
还有个解法利用了完全平方数等于从1开始的连续奇数和，不过我认为还是太慢了。

五一了，第一次过加班3天的五一假期。
祝自己节日快乐，加油！

<div style="text-align: right">   2019/05/01 01:09     </div>