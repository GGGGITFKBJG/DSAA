### 1. 两数之和

> <html> <div><p>给定一个整数数组 <code>nums</code>&nbsp;和一个目标值
> <code>target</code>，请你在该数组中找出和为目标值的那&nbsp;<strong>两个</strong>&nbsp;整数，并返回他们的数组下标。</p>
> 
> <p>你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre>给定 nums = [2, 7, 11, 15], target = 9
> 
> 因为 nums[<strong>0</strong>] + nums[<strong>1</strong>] = 2 + 7 = 9
> 所以返回 [<strong>0, 1</strong>] </pre> </div> <html>

解法一

```cpp
//穷举法, 时间复杂度O(n^2), 空间复杂度O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] == target - nums[j]) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
```
解法二

```cpp
//使用std::unordered_map, 复杂度为O(n), 空间复杂度为O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;//保存输入数组
        for(int i = 0; i < nums.size(); i++) {
            int count = map.count(target - nums[i]);//查找是否存在target - i
            if(count > 0) {
                return {map.find(target - nums[i])->second, i};
            }
            map[nums[i]] = i;//添加键值对 nums[i], i;
        }
        return {};
    }
};
```
暴力解法
使用哈希表