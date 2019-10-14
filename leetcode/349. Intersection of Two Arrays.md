### 349. 两个数组的交集

> <div class="content__2ebE"><p>给定两个数组，编写一个函数来计算它们的交集。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入: </strong>nums1 = [1,2,2,1], nums2 = [2,2] <strong>输出:
> </strong>[2] </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入: </strong>nums1 = [4,9,5], nums2 = [9,4,9,8,4]
> <strong>输出: </strong>[9,4]</pre>
> 
> <p><strong>说明:</strong></p>
> 
> <ul> 	<li>输出结果中的每个元素一定是唯一的。</li> 	<li>我们可以不考虑输出结果的顺序。</li> </ul>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> um;
        vector<int> res;
        for(int num : nums1) {
            um[num] = false;
        }
        for(int num : nums2) {
            if(um.count(num)) um[num] = true;
        }
        for(auto it = um.begin(); it != um.end(); it++) {
            if(it->second) res.push_back(it->first);
        }
        return res;
    }
};
```

解法二
```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), res;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.begin()));
        return vector<int>(res.begin(), res.end());
    }
};
```

解法一
1. 使用一个哈希表，记录数组1所有元素；
2. 再遍历数组2，标记两数组都出现过的元素；
3. 再遍历哈希表，输出交集。

解法二
标准库有求交集的函数set_intersection。类似求差集set_difference，求并集set_union。

<div style="text-align: right"> 2019/04/30 23:46 </div>