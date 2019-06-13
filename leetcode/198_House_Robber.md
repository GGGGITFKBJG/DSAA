### 198. 打家劫舍

> <div
> class="content__2ebE"><p>你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，<strong>如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警</strong>。</p>
> 
> <p>给定一个代表每个房屋存放金额的非负整数数组，计算你<strong>在不触动警报装置的情况下，</strong>能够偷窃到的最高金额。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [1,2,3,1] <strong>输出:</strong> 4
> <strong>解释:</strong> 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。 &nbsp;   
> 偷窃到的最高金额 = 1 + 3 = 4 。</pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> [2,7,9,3,1] <strong>输出:</strong> 12
> <strong>解释:</strong> 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋
> (金额 = 1)。 &nbsp;    偷窃到的最高金额 = 2 + 9 + 1 = 12 。 </pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int d[nums.size()] = {nums[0], max(nums[0], nums[1])};
        for(int i = 2; i < nums.size(); i++) {
            d[i] = max(nums[i] + d[i - 2], d[i - 1]);
        }
        return d[nums.size() - 1];
    }
};
```

此题就是求数组中互不相邻元素的最大和，使用动态归划两步走：
1. 选取状态函数：d(i)表示遍历到第i个元素时，所能获得的最大和，一共有nums.size()种状态。此题答案即是d(nums.size() - 1)；
2. 状态转移方程：第i个元素处的最大和，最决于前两个状态，及当前元素的值。状态函数关系：
d(i) = max{ nums[i] + d(i - 2), d(i-1) }
3. 看方程，需要初始化前两个状态，d(0) = nums[0]，d(1) = max{ nums[0], nums[1] }；
4. 一次遍历，最后输出d(nums.size() - 1)，即为正确答案。 
如果以前没见过这个题，自已独立想出来不是那么容易。状态转移方程里当前状态只依赖于前两个状态，为什么不是一个、三个或者四个呢？我个人理解，关键是选取求和的任意两元素之间的间隔数不会大于2（要获得最大利益，小偷不可能连续跳过3间房），连续三个元素必定要选取1个或2个，所以就以三个元素为一个阶段。
  
<div style="text-align: right"> 2019/04/27 18:42  </div>