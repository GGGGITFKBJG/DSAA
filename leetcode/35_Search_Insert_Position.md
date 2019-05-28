### 35. 搜索插入位置

> <div
> class="content__2ebE"><div><p>给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。</p>
> 
> <p>你可以假设数组中无重复元素。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [1,3,5,6], 5 <strong>输出:</strong> 2 </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> [1,3,5,6], 2 <strong>输出:</strong> 1 </pre>
> 
> <p><strong>示例 3:</strong></p>
> 
> <pre><strong>输入:</strong> [1,3,5,6], 7 <strong>输出:</strong> 4 </pre>
> 
> <p><strong>示例 4:</strong></p>
> 
> <pre><strong>输入:</strong> [1,3,5,6], 0 <strong>输出:</strong> 0 </pre>
> </div></div>

解法一
```cpp
//时间复杂度O(log(n)), 空间复杂度O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        int mid;
        while(low <= high) {//注意这里的等号
            mid = low + (high - low) / 2;
            if(target < nums[mid]) high = mid - 1;
            else if(target > nums[mid]) low = mid + 1;
            else return mid;
        }
        return low;//此时low > high, 返回大的
    }
};
```
使用二分查找，注意：
1. 判断条件是 low <= high；
2. 若找到直接返回。未找到，考虑两种情况，插入位置 i) 在中间； ii) 在左边界； iii) 在右边界。
  i) 未找到且target小于数组最大值且大于最小值，此时low > high，且target介于两者之间，要返回大者，刚好是low；
  ii) 未找到且target大于数组最大值（这时应返回数组长度），在这里low = length，high = length - 1，返回low；
  iii) 未找到且target小于数组最小值（这时应返回0），在这里low = 0，high = -1，返回low；
3. 综上，找到则返回；未找到则返回low。