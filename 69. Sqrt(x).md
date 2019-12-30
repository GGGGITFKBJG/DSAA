### 69. x的平方根

> <div class="content__2ebE"><div><p>实现&nbsp;<code>int sqrt(int
> x)</code>&nbsp;函数。</p>
> 
> <p>计算并返回&nbsp;<em>x</em>&nbsp;的平方根，其中&nbsp;<em>x </em>是非负整数。</p>
> 
> <p>由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> 4 <strong>输出:</strong> 2 </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> 8 <strong>输出:</strong> 2
> <strong>说明:</strong> 8 的平方根是 2.82842...,  &nbsp;   
> 由于返回类型是整数，小数部分将被舍去。 </pre> </div></div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1), n = 46340
class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = 46340;//sqrt(INT_MAX) = 46340
        int mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(mid * mid < x) low = mid + 1;
            else if(mid * mid > x) high = mid - 1;
            else return mid;
        }
        return high;
    }
};
```

二分法。一开始我把high初始化为x / 2 （还要处理x = 1的特殊情况），出现了溢出问题。为了处理溢出，令high = 46340。