### 697. 数组的度

> <div class="content__2ebE"><p>给定一个非空且只包含非负数的整数数组&nbsp;<code>nums</code>, 数组的度的定义是指数组里任一元素出现频数的最大值。</p>
> 
> <p>你的任务是找到与&nbsp;<code>nums</code>&nbsp;拥有相同大小的度的最短连续子数组，返回其长度。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [1, 2, 2, 3, 1]
> <strong>输出:</strong> 2
> <strong>解释:</strong> 
> 输入数组的度是2，因为元素1和2的出现频数最大，均为2.
> 连续子数组里面拥有相同度的有如下所示:
> [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
> 最短连续子数组[2, 2]的长度为2，所以返回2.
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> [1,2,2,3,1,4,2]
> <strong>输出:</strong> 6
> </pre>
> 
> <p><strong>注意:</strong></p>
> 
> <ul>
> 	<li><code>nums.length</code>&nbsp;在1到50,000区间范围内。</li>
> 	<li><code>nums[i]</code>&nbsp;是一个在0到49,999范围内的整数。</li>
> </ul>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), res = 0;
        unordered_map<int, vector<int>> um;//<value, <count, first, last> >
        for(int i = 0; i < n; i++) {
            if(!um.count(nums[i])) um[nums[i]] = {1, i, i};
            else {
                um[nums[i]][0]++;
                um[nums[i]][2] = i;
            }
        }
        
        int maxCount = 0;
        for(auto p : um) {
            if(p.second[0] > maxCount) {
                maxCount = p.second[0];
                res = p.second[2] - p.second[1] + 1;
            }
            else if(p.second[0] == maxCount)
                res = min(res, p.second[2] - p.second[1] + 1);
        }
        return res;
    }
};
```

思路：

思路很直白，对每一个数字，记录其出现次数，第一个及最后一个出现的位置，用一个哈希表um表示，其中um的键是数字，值是个长为3的列表（count, firstIndex, endIndex）。

首选遍历一次，记录元素的信息，存入um。然后遍历um，找出其中***出现次数最多***且***last - first最小***的元素，返回其last - first + 1，这个值就是拥有相同大小的度的最短连续子数组的长度。

<div style="text-align: right"> 2019/06/23 13:44 </div>