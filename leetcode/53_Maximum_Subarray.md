### 53. 最大子序和

> <div class="content__2ebE"><div><p>给定一个整数数组
> <code>nums</code>&nbsp;，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> [-2,1,-3,4,-1,2,1,-5,4],
> <strong>输出:</strong> 6 <strong>解释:</strong>&nbsp;连续子数组&nbsp;[4,-1,2,1]
> 的和最大，为&nbsp;6。 </pre>
> 
> <p><strong>进阶:</strong></p>
> 
> <p>如果你已经实现复杂度为 O(<em>n</em>) 的解法，尝试使用更为精妙的分治法求解。</p> </div></div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0, result = INT_MIN;
        for(int i : nums) {
            currentSum = currentSum > 0 ? currentSum + i : i;//和小于零就放弃，再从i开始计和
            if(currentSum > result) result = currentSum;//记下遍历过程中出现过的最大值
        }
        return result;
    }
};
```

解法二
```cpp
//分治法, 时间复杂度O(nlog(n)), 空间复杂度O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums, int left, int right) {
        if(left == right) return nums[left];//终止条件
        
        int mid = left + (right - left) / 2;
        int r1 = maxSubArray(nums, left, mid);
        int r2 = maxSubArray(nums, mid + 1, right);
        int r3 = INT_MIN, temp = 0;//当前和temp初始化为0
        for(int i = mid; i >= left; i--) {//向左遍历
            temp += nums[i];//一直累加，注意区别解法一的第7行
            if(temp > r3) r3 = temp;//记下遍历过程中出现过的最大值
        }
        temp = r3;//当前和temp置为r3
        for(int i = mid + 1; i <= right; i++) {//向右遍历
            temp += nums[i];
            if(temp > r3) r3 = temp;
        }
        return max(r1, max(r2, r3));
    }
    
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
};
```
解法一：
1. 遍历整个数组，从第0个元素开始计和；
2. 若遇到和小于0，放弃当前和，并从该处重新计和；
3. 变量result记录下全过程中sum的最大值，即是结果。

解法二：
1. 驱动函数直接调用，对整个数组求最大子序列和；
2. 主求解函数将数组划分为左、右两部分，r1保存左部分最大子序列和，r2保存右部分最大子序列和；
3. 除了单独求解左、右子数组还不够，还要考虑跨越两部分的元素；从中间元素开始，向两边遍历计和，记下最大子序列和r3；
4. 返回r1、r2、r3最大者。

其中解法一简单且高效，解法二稍复杂。分治法在有些场合十分精巧，但在此题并不是最合适的。