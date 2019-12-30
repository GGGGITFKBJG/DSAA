### 448. 找到所有数组中消失的数字

> <div class="content__2ebE"><p>给定一个范围在&nbsp; 1 ≤ a[i] ≤ <em>n</em>
> (&nbsp;<em>n</em> = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。</p>
> 
> <p>找到所有在 [1, <em>n</em>] 范围之间没有出现在数组中的数字。</p>
> 
> <p>您能在不使用额外空间且时间复杂度为<em>O(n)</em>的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> [4,3,2,7,8,2,3,1]
> 
> <strong>输出:</strong> [5,6] </pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        vector<int> rec(nums.size(), 0);
        for(int num : nums) {
            rec[num - 1] = 1;
        }
        for(int i = 0; i < rec.size(); i++) {
            if(rec[i] == 0) res.push_back(i + 1);
        }
        return res;
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int num : nums) {
            if(nums[abs(num) - 1] > 0) nums[abs(num) - 1] = -nums[abs(num) - 1];
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};
```

类似的题出现过，连续的整数，求没有满足要求的数字，有几种思路：①用公式求和再减去数组和（连续数字中只缺一个）；②使用按位异或运算（出现奇数/偶数次的数字）；③使用哈希表（万能解法）。
解法一用了一个数组（哈希表）来记录是否出现过某一数字，记录完成后遍历一次数组，没有访问过的就要所求的缺失的数字；
解法二与解法一思路相同，只是这里不再用一个额外数组了，而是在当前数组上作记录。为了在作记录的同时不改变数字，这里采用了取反的操作，读的时间统一按正数读（abs()） ，而访问过的数字，就将其数置为负。最后遍历一次，找出大于为的元素，其下标 + 1就是要求的缺失的数字。

<div style="text-align: right">    2019/05/05 22:27  </div>