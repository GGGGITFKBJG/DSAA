### 172. 阶乘后的零
> <div class="content__2ebE"><p>给定一个整数 <em>n</em>，返回 <em>n</em>!
> 结果尾数中零的数量。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> 3 <strong>输出:</strong> 0
> <strong>解释:</strong>&nbsp;3! = 6, 尾数中没有零。</pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> 5 <strong>输出:</strong> 1
> <strong>解释:</strong>&nbsp;5! = 120, 尾数中有 1 个零.</pre>
> 
> <p><strong>说明:
> </strong>你算法的时间复杂度应为&nbsp;<em>O</em>(log&nbsp;<em>n</em>)<em>&nbsp;</em>。</p>
> </div>

解法一
```cpp
//时间复杂度O(logn), 空间复杂度O(1)
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n > 0) {
            int t = n / 5;
            res += t;
            n = t;
        }
        return res;//n因子中5的个数
    }
};
```

返回n的质因子中5的个数即可。因为对于每个5，总能找到一个因子2与其相乘得10，其它因子都不可能乘得10。故5的个数即为末尾0的个数。
 
<div style="text-align: right"> 2019/04/27 00:58  </div>            