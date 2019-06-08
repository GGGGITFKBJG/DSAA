### 169. 求众数

> <div class="content__2ebE"><p>给定一个大小为 <em>n
> </em>的数组，找到其中的众数。众数是指在数组中出现次数<strong>大于</strong>&nbsp;<code>⌊ n/2
> ⌋</code>&nbsp;的元素。</p>
> 
> <p>你可以假设数组是非空的，并且给定的数组总是存在众数。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> [3,2,3] <strong>输出:</strong> 3</pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> [2,2,1,1,1,2,2] <strong>输出:</strong> 2
> </pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = INT_MIN, count = 1;
        for(int num : nums) {
            if(num == maj) count++;
            else count--;
            if(count == 0) {
                maj = num;
                count = 1;
            }
        }
        return maj;
    }
};
```

第一眼看见想到用哈希表，当然有线性的空间需求。
以上的这个解法叫摩尔投票法，可以用一次遍历，O(1)的空间复杂度解法这个问题。前提条件是某个数的个数超过总数的一半。
这个算法首先选定第一个数为候选者，向后遍历。遇到相同的值就把票数加1，不同就减1，当投票数减为0时，就更新当前的值为新的候选者。当遍历结束时，投票最高的即为众数。

<div style="text-align: right"> 2019/04/26 14:11 </div>