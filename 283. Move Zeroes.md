### 283. 移动零

> <div class="content__2ebE"><p>给定一个数组 <code>nums</code>，编写一个函数将所有
> <code>0</code> 移动到数组的末尾，同时保持非零元素的相对顺序。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> <code>[0,1,0,3,12]</code>
> <strong>输出:</strong> <code>[1,3,12,0,0]</code></pre>
> 
> <p><strong>说明</strong>:</p>
> 
> <ol> 	<li>必须在原数组上操作，不能拷贝额外的数组。</li> 	<li>尽量减少操作次数。</li> </ol> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        while(i < nums.size() && nums[i] != 0) i++;
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[j] != 0) nums[i++] = nums[j];
        }
        while(i < nums.size()) nums[i++] = 0;
    }
};
```

双指针法。
1. i 先指向第一个0元素，j从i + 1开始向后遍历；
2. j 遇到非0元素时，就把nums[i]更新，并将i自增。
3. 遍历完成后，将后面的元素都改为0。

<div style="text-align: right">    2019/04/29 19:32  </div>
