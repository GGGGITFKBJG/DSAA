### 219. 存在重复元素 II

> <div
> class="content__2ebE"><p>给定一个整数数组和一个整数&nbsp;<em>k</em>，判断数组中是否存在两个不同的索引<em>&nbsp;i</em>&nbsp;和<em>&nbsp;j</em>，使得&nbsp;<strong>nums
> [i] = nums [j]</strong>，并且 <em>i</em> 和 <em>j</em>&nbsp;的差的绝对值最大为
> <em>k</em>。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> nums = [1,2,3,1], k<em> </em>= 3
> <strong>输出:</strong> true</pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入: </strong>nums = [1,0,1,1], k<em> </em>=<em> </em>1
> <strong>输出:</strong> true</pre>
> 
> <p><strong>示例 3:</strong></p>
> 
> <pre><strong>输入: </strong>nums = [1,2,3,1,2,3], k<em> </em>=<em></em> 2 
> <strong>输出:</strong> false</pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> um = {};//val, index
        for(int i = 0; i < nums.size(); i++) {
            if(um.count(nums[i]) && i - um[nums[i]] <= k) return true;
            um[nums[i]] = i;
        }
        return false;
    }
};
```

总结：
与上一题类似，同样使用一个哈希表，记录访问过的元素及其索引值。遍历过程中，先检查当前元素有记录，若有说明有重复，检查记录中的索引与当前元素的索引的距离，若距离小于等于k，返回true；否则将更新重复元素的索引记录，直到末尾，返回false，代表没有重复元素。

<div style="text-align: right">    2019/04/28 18:35  </div>