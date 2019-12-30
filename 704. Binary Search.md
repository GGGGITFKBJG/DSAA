### 704. 二分查找

> <div class="content__2ebE"><p>给定一个&nbsp;<code>n</code>&nbsp;个元素有序的（升序）整型数组&nbsp;<code>nums</code> 和一个目标值&nbsp;<code>target</code> &nbsp;，写一个函数搜索&nbsp;<code>nums</code>&nbsp;中的 <code>target</code>，如果目标值存在返回下标，否则返回 <code>-1</code>。</p>
> 
> <p><br>
> <strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> <code>nums</code> = [-1,0,3,5,9,12], <code>target</code> = 9
> <strong>输出:</strong> 4
> <strong>解释:</strong> 9 出现在 <code>nums</code> 中并且下标为 4
> </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> <code>nums</code> = [-1,0,3,5,9,12], <code>target</code> = 2
> <strong>输出:</strong> -1
> <strong>解释:</strong> 2 不存在 <code>nums</code> 中因此返回 -1
> </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>提示：</strong></p>
> 
> <ol>
> 	<li>你可以假设 <code>nums</code>&nbsp;中的所有元素是不重复的。</li>
> 	<li><code>n</code>&nbsp;将在&nbsp;<code>[1, 10000]</code>之间。</li>
> 	<li><code>nums</code>&nbsp;的每个元素都将在&nbsp;<code>[-9999, 9999]</code>之间。</li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(logn), 空间复杂度O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high) {//注意是 <= 号
            int mid = low + (high - low) / 2;
            if(target > nums[mid]) low = mid + 1;
            else if(target < nums[mid]) high = mid - 1;
            else return mid;
        }
        return -1;
    }
};
```

low和high记录数组的左、右边界，每次取中间的位置与target作对比，相应地调整左、右边界的位置。直接看代码最直观。

注意判断条件是小于等于号。

<div style="text-align: right"> 2019/06/25 11:50 </div>