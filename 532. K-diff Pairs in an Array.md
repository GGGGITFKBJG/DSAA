### 532. 数组中的K-diff数对

> <div class="content__2ebE"><div class="notranslate"><p>给定一个整数数组和一个整数&nbsp;<strong>k</strong>, 你需要在数组里找到<strong>不同的&nbsp;</strong>k-diff 数对。这里将&nbsp;<strong>k-diff</strong>&nbsp;数对定义为一个整数对 (i, j), 其中<strong> i </strong>和<strong> j </strong>都是数组中的数字，且两数之差的绝对值是&nbsp;<strong>k</strong>.</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [3, 1, 4, 1, 5], k = 2
> <strong>输出:</strong> 2
> <strong>解释: </strong>数组中有两个 2-diff 数对, (1, 3) 和 (3, 5)。
> 尽管数组中有两个1，但我们只应返回不同的数对的数量。
> </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong>[1, 2, 3, 4, 5], k = 1
> <strong>输出: </strong>4
> <strong>解释:</strong> 数组中有四个 1-diff 数对, (1, 2), (2, 3), (3, 4) 和 (4, 5)。
> </pre>
> 
> <p><strong>示例 3:</strong></p>
> 
> <pre><strong>输入: </strong>[1, 3, 1, 5, 4], k = 0
> <strong>输出: </strong>1
> <strong>解释:</strong> 数组中只有一个 0-diff 数对，(1, 1)。
> </pre>
> 
> <p><strong>注意:</strong></p>
> 
> <ol>
> 	<li>数对 (i, j) 和数对&nbsp;(j, i) 被算作同一数对。</li>
> 	<li>数组的长度不超过10,000。</li>
> 	<li>所有输入的整数的范围在&nbsp;[-1e7, 1e7]。</li>
> </ol>
> </div></div>

解法一
```cpp
//时间复杂度O(nlogn), 空间复杂度O(1)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, res = 0;
        while(j < nums.size() && nums[j] == nums[i]) j++;
        if(k == 0) {
            while(i < j && j < nums.size()) {
                if(j - i > 1) res++;
                i = j++;
                while(j < nums.size() && nums[j] == nums[i]) j++;
            }
            if(j - i > 1) res++;
        }
        else {
            while(j < nums.size()) {
                if(nums[j] - nums[i] == k) {
                    res++;
                    int temp = nums[i];
                    while(i < nums.size() && nums[i] == temp) i++;
                    temp = nums[j];
                    while(j < nums.size() && nums[j] == temp) j++;
                }
                else if(nums[j] - nums[i] < k) {
                    int temp = nums[j];
                    while(j < nums.size() && nums[j] == temp) j++;
                }
                else {
                    int temp = nums[i];
                    while(i < nums.size() && nums[i] == temp) i++;
                    if(i == j) while(j < nums.size() && nums[j] == nums[i]) j++;
                }
            }
        }
        
        return res;
    }
};
```

解法二
```cpp
//时间复杂度O(nlogn), 空间复杂度O(1)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 0, res = 0, len = nums.size();
        while(i < len) {
            if(j <= i) j = i + 1;
            while(j < len && nums[j] - nums[i] < k) j++;//向后遍历
            if(j < len && nums[j] - nums[i] == k) res++;
            
            int temp = nums[i];
            while(i < len && nums[i] == temp) i++;//i指向下一个不重复的元素
        }
        return res;
    }
};
```

解法三
```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> um;
        for(int num : nums) ++um[num];
        for(auto elem : um) {
            if(k == 0 && elem.second > 1) res++;
            if(k > 0 && um.count(elem.first + k)) res++;
        }
        return res;
    }
};
```

解法一

双指针法，注意处理k为0时的情况。

解法二

参考了别人的答案，发现我写的太丑了。仍是双指针法，思路与解法一类似，细节优化。为了不单独处理k=0时的情况，此解法中j不再跳到下一个不相同元素的位置，而是初始化为i+1，这样也包含了k=0的特殊处理。


解法三
使用哈希表，第一次遍历原数组计数，第二次遍历哈希表，累加res。第二次遍历这里只需要验证num + k是否在哈希表中存在（而不需要额外地验证num - k）即可，因为数对里面总有一个数是较小的。


<div style="text-align: right"> 2019/05/28 11:48 </div>