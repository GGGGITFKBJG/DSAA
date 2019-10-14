### 561. 数组拆分 I

> <div class="content__2ebE"><p>给定长度为&nbsp;<strong>2n&nbsp;</strong>的数组, 你的任务是将这些数分成&nbsp;<strong>n </strong>对, 例如 (a<sub>1</sub>, b<sub>1</sub>), (a<sub>2</sub>, b<sub>2</sub>), ..., (a<sub>n</sub>, b<sub>n</sub>) ，使得从1 到&nbsp;n 的 min(a<sub>i</sub>, b<sub>i</sub>) 总和最大。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [1,4,3,2]
> 
> <strong>输出:</strong> 4
> <strong>解释:</strong> n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
> </pre>
> 
> <p><strong>提示:</strong></p>
> 
> <ol>
> 	<li><strong>n</strong>&nbsp;是正整数,范围在 [1, 10000].</li>
> 	<li>数组中的元素范围在 [-10000, 10000].</li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(nlogn), 空间复杂度O(1)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < nums.size(); i += 2) sum += nums[i];
        return sum;
    }
};
```

思路：

由于数对是取较小者，数组中最大元素肯定取不到，以及最小元素一定会被取到。所以与最小元素配对的一定会被丢弃，所以就选第二小与最小元素配对。相应地，选第二大与最大元素配对。以此类推，按大小相邻的元素配对，就可以得到整体的最大值。所以：

先对数组由小到大排序，对索引为奇数的元素求和，就是答案。

<div style="text-align: right"> 2019/06/02 22:07 </div>