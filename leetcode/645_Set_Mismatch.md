### 645. 错误的集合

> <div class="content__2ebE"><p>集合 <code>S</code> 包含从1到&nbsp;<code>n</code>&nbsp;的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。</p>
> 
> <p>给定一个数组 <code>nums</code> 代表了集合 <code>S</code> 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> nums = [1,2,2,4]
> <strong>输出:</strong> [2,3]
> </pre>
> 
> <p><strong>注意:</strong></p>
> 
> <ol>
> 	<li>给定数组的长度范围是&nbsp;[2, 10000]。</li>
> 	<li>给定的数组是无序的。</li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        int n = nums.size();
        vector<int> rec(n, 0);
        for(int num : nums) ++rec[num - 1];
        for(int i = 0; i < n; i++) {
            if(rec[i] == 0) res[1] = i + 1;
            else if(rec[i] == 2) res[0] = i + 1;
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
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res(2, 0);
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                res[0] = nums[i];
                if(res[1]) return res;
            }
            else if(nums[i + 1] - nums[i] != 1) {
                res[1] = nums[i] + 1;
                if(res[0]) return res;
            }
        }
        res[1] = nums[n - 1] == n ? 1 : n;
        return res;
    }
};
```

解法一

很直观，使用一个长为n的数组，先遍历一次对元素计数，再遍历一次找出计数为2和计数为0的元素，就是要找的两个。

解法二

为了不使用额外的空间，先对数组从小到大排序，再遍历一次数组：
1. 检查相邻两元素是否相等，若相等，该元素就是重复元素；
2. 检查相邻两元素之差是否为1，若不是，则说明两者之间的整数是缺失的元素。
3. 遍历过程中，若重复元素和缺失元素都找到了，就直接返回。

如果遍历结束，但是只找到了重复元素（当缺失元素是1或n时，这种情况会出现），需要检查一下最大值和最小值是否为1和n，不是则说明它为缺失元素。返回。

<div style="text-align: right"> 2019/06/14 20:14 </div>