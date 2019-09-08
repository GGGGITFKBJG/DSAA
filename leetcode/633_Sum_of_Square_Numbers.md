### 633. 平方数之和

> <div class="content__2ebE"><p>给定一个非负整数&nbsp;<code>c</code>&nbsp;，你要判断是否存在两个整数 <code>a</code> 和 <code>b</code>，使得&nbsp;a<sup>2</sup> + b<sup>2</sup> = c。</p>
> 
> <p><strong>示例1:</strong></p>
> 
> <pre><strong>输入:</strong> 5
> <strong>输出:</strong> True
> <strong>解释:</strong> 1 * 1 + 2 * 2 = 5
> </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例2:</strong></p>
> 
> <pre><strong>输入:</strong> 3
> <strong>输出:</strong> False
> </pre>
> </div>

解法一
```cpp
//时间复杂度O((c)^0.5), 空间复杂度O(1)
class Solution {
public:
    bool judgeSquareSum(int c) {
        int m = sqrt(c / 2);
        for(int a = 0; a <= m; a++) {
            int b2 = c - a * a;
            int b = sqrt(b2);
            if(b * b == b2) return true;
        }
        return false;
    }
};
```

让a从0开始遍历，求出b = c - a^2，判断其开根号是否为正整数，若是则返回true；遍历完成后都没有，则返回false。

为了节省计算量，让a从0开始，到sqrt(c / 2)结束即可（在此范围若没找到，则后面也不可能再找到了）。

<div style="text-align: right"> 2019/06/12 0:50 </div>