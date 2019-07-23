### 453. 最小移动次数使数组元素相等

> <div class="content__2ebE"><p>给定一个长度为 <em>n</em>
> 的<strong>非空</strong>整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 <em>n</em> - 1
> 个元素增加 1。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> [1,2,3]
> 
> <strong>输出:</strong> 3
> 
> <strong>解释:</strong> 只需要3次移动（注意每次移动会增加两个元素的值）：
> 
> [1,2,3]  =&gt;  [2,3,3]  =&gt;  [3,4,3]  =&gt;  [4,4,4] </pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = nums[0];
        long sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(min > nums[i]) min = nums[i];
            sum += nums[i];
        }
        return sum - min * nums.size();
    }
};
```

题有点绕，想通了之后发现，需要每次固定最大值，对其他值加1。好了，就按这样写出代码，提交——超时错误。。
换一种思路，这个题数字的绝对大小不重要，重要的是相对的大小。可以每次选定一个最大值将其减1（如果有多个最大值，只减其中一个），一直减到所有数字都等于最小元素。
OK，就是以上代码。先求和，顺便找最小元素，然后减去最小值*元素个数即可。
注意sum要设置成long，以免输入INT_MAX时产生溢出。

<div style="text-align: right">     2019/05/07 22:40 </div>
