### 594. 最长和谐子序列

> <div class="content__2ebE"><p>和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。</p>
> 
> <p>现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [1,3,2,2,5,2,3,7]
> <strong>输出:</strong> 5
> <strong>原因:</strong> 最长的和谐数组是：[3,2,2,2,3].
> </pre>
> 
> <p><strong>说明:</strong> 输入的数组长度最大不超过20,000.</p>
> </div>

解法一
```cpp
//时间复杂度O(nlogn), 空间复杂度O(1)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size(), res = 0, i = 0, j = 1, next = 0;
        sort(nums.begin(), nums.end());
        while(next < n) {
            i = next;
            while(j < n && nums[j] == nums[i]) j++;
            next = j;
            while(j < n && nums[j] - nums[i] == 1) j++;
            if(j > next) res = max(res, j - i);
        }
        return res;
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> um;
        int res = 0;
        for(int num : nums) ++um[num];
        for(auto p = um.begin(); p != um.end(); p++) {
            if(um.count(p->first + 1)) res = max(res, p->second + um[p->first + 1]);
        }
        return res;
    }
};
```

思路：

解法一：

双指针法。
1. 先对数组由小到大排序，开始一次遍历。
2. 遍历过程中，使用res记录出现过的和谐子序列的最大长度，i指向和谐子序列的最小元素，j指向和谐子序列的最大元素的下一个位置，next指向下一个i要移动到的位置；
3. 在一次循环体内，如果j == next，说明这个子序列最大值 - 最小值之差为0（即这个子序列不是和谐子序列），此时不需要更新res；
4. 当next （j）到达结尾时，返回res。

解法二：
使用一个哈希表unorder_map，记录每个元素的值和出现的次数，然后遍历哈希表，遍历过程中向上查找大1的元素，（当前元素个数） + （当前元素 + 1的元素的个数）是潜在的最大值，若此值大于res，就更新res。

<div style="text-align: right"> 2019/06/04 21:32 </div>