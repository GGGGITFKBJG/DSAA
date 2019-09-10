### 643. 子数组最大平均数 I

> <div class="content__2ebE"><p>给定 <code>n</code> 个整数，找出平均数最大且长度为 <code>k</code> 的连续子数组，并输出该最大平均数。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [1,12,-5,-6,50,3], k = 4
> <strong>输出:</strong> 12.75
> <strong>解释:</strong> 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
> </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>注意:</strong></p>
> 
> <ol>
> 	<li>1 &lt;= <code>k</code> &lt;= <code>n</code> &lt;= 30,000。</li>
> 	<li>所给数据范围 [-10,000，10,000]。</li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long sum = 0;
        for(int i = 0; i < k; i++) sum += nums[i];
        int m = sum;
        for(int i = k; i < nums.size(); i++) {
            sum += (nums[i] - nums[i - k]);
            if(sum > m) m = sum;
        }
        return (double)m / k;
    }
};
```

按照题目意思求每个子序列的和，记录最大值，最后求平均输出即可。

<div style="text-align: right"> 2019/06/13 21:05 </div>