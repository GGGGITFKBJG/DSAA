### 674. 最长连续递增序列

> <div class="content__2ebE"><p>给定一个未经排序的整数数组，找到最长且<strong>连续</strong>的的递增序列。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [1,3,5,4,7]
> <strong>输出:</strong> 3
> <strong>解释:</strong> 最长连续递增序列是 [1,3,5], 长度为3。
> 尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> [2,2,2,2,2]
> <strong>输出:</strong> 1
> <strong>解释:</strong> 最长连续递增序列是 [2], 长度为1。
> </pre>
> 
> <p><strong>注意：</strong>数组长度不会超过10000。</p>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int res = 0, start = 0, end;
        for(end = 1; end < n; end++) {
            if(nums[end] > nums[end - 1]) continue;
            res = max(end - start, res);
            start = end;
        }
        return max(end - start, res);
    }
};
```

遍历一次，使用start和end记录增序序列的起始位置，用res记录end - start的最大值，遍历完成后返回res即可。注意处理输入元素数为0和1这两种特殊情况。

<div style="text-align: right"> 2019/06/18 22:34 </div>