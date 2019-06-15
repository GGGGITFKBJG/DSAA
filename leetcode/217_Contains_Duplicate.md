### 217. 存在重复元素

> <div class="content__2ebE"><p>给定一个整数数组，判断是否存在重复元素。</p>
> 
> <p>如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [1,2,3,1] <strong>输出:</strong> true</pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入: </strong>[1,2,3,4] <strong>输出:</strong> false</pre>
> 
> <p><strong>示例&nbsp;3:</strong></p>
> 
> <pre><strong>输入: </strong>[1,1,1,3,3,4,3,2,4,2] <strong>输出:</strong>
> true</pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(int num : nums) {
            if(us.count(num)) return true;
            us.insert(num);
        }
        return false;
    }
};
```

解法二
```cpp
//时间复杂度O(nlogn), 空间复杂度O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};
```

解法一
使用一个哈希表，记录访问过的元素。遍历过程中，先检查当前元素有记录，若有说明有重复，返回true；否则将新元素添加记录，直到末尾，返回false，代表没有重复元素。
解法二
解法一需要线性时间和线性空间，如果对空间需求有限制，可以先对数组排序，再遍历，检查相邻两元素是否相等。若有相等，返回true；否则返回false，这样就是常量的空间需求，运行时间取决于排序算法，快排为O(nlogn)。

  <div style="text-align: right"> 2019/04/28 18:30 </div>