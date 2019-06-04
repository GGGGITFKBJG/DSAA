### 167. 两数之和 II - 输入有序数组

> <div
> class="content__2ebE"><p>给定一个已按照<strong><em>升序排列</em>&nbsp;</strong>的有序数组，找到两个数使得它们相加之和等于目标数。</p>
> 
> <p>函数应该返回这两个下标值<em> </em>index1 和 index2，其中
> index1&nbsp;必须小于&nbsp;index2<em>。</em></p>
> 
> <p><strong>说明:</strong></p>
> 
> <ul> 	<li>返回的下标值（index1 和 index2）不是从零开始的。</li>
> 	<li>你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。</li> </ul>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> numbers = [2, 7, 11, 15], target = 9
> <strong>输出:</strong> [1,2] <strong>解释:</strong> 2 与 7 之和等于目标数 9 。因此
> index1 = 1, index2 = 2 。</pre> </div>


解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while(i < j) {
            if(numbers[i] + numbers[j] > target) j--;
            else if(numbers[i] + numbers[j] < target) i++;
            else if(numbers[i] + numbers[j] == target) return {i + 1, j + 1};
        }
        return {};
    }
};
```

双指针法：指针i，j分别指向第一个和最后一个元素，同时向中间收缩。如果目标值大于两者和，j左移，反之i右移。
这个方法很巧妙，因为数组是有序的，题上说有且只有一个答案，答案一定在两指针之间，所以此法收缩过程中一定会遇到。

<div style="text-align: right"> 2019/04/25 09:38 </div>