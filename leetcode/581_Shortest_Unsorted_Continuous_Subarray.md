### 581. 最短无序连续子数组

> <div class="content__2ebE"><p>给定一个整数数组，你需要寻找一个<strong>连续的子数组</strong>，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。</p>
> 
> <p>你找到的子数组应是<strong>最短</strong>的，请输出它的长度。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [2, 6, 4, 8, 10, 9, 15]
> <strong>输出:</strong> 5
> <strong>解释:</strong> 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
> </pre>
> 
> <p><strong>说明 :</strong></p>
> 
> <ol>
> 	<li>输入的数组长度范围在&nbsp;[1, 10,000]。</li>
> 	<li>输入的数组可能包含<strong>重复</strong>元素&nbsp;，所以<strong>升序</strong>的意思是<strong>&lt;=。</strong></li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(nlogn), 空间复杂度O(n)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if(nums[i] != temp[i] && nums[j] != temp[j]) break;
            if(nums[i] == temp[i]) i++;
            if(nums[j] == temp[j]) j--;
        }
        return i >= j ? 0 : j - i + 1;
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int max = nums[0], min = nums[len - 1];
        int start = 1, end = 0;
        for(int i = 1; i < len; i++) {
            if(nums[i] >= max) max = nums[i];//等于号不可少
            else end = i;//当max > nums[i]
            if(nums[len - 1 - i] <= min) min = nums[len - 1 - i];
            else start = len - 1 - i;
        }
        return end - start + 1;
    }
};
```

思路：

解法一，先构造一个相同的数组，排序，再从两端开始向中间遍历，比较与原数组不同的地方。

解法二，这个解法确实厉害。一开始有些难理解，建议找个例子人脑调试一下就懂了。

循环体内从左、右两端开始同时遍历，只看其中从左至右这一个方向的话，这个循环所做的，就是就标记end向右推到最终**合适的位置**（“合适”是指该标记右侧所有元素都大于其左侧元素，且右侧元素为增序）；同理，反向是把标记start向左推。最终得到一个不合法序列的范围，返回其长度。

要注意的是，对于一个从小到大的有序序列，它不会修改两个标记，这时应该让其返回1，这是我们让start = 1, end = 0的原因。

<div style="text-align: right"> 2019/06/03 21:58 </div>