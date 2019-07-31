### 485. 最大连续1的个数
> <div class="content__2ebE"><div><p>给定一个二进制数组， 计算其中最大连续1的个数。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [1,1,0,1,1,1]
> <strong>输出:</strong> 3
> <strong>解释:</strong> 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
> </pre>
> 
> <p><strong>注意：</strong></p>
> 
> <ul>
> 	<li>输入的数组只包含&nbsp;<code>0</code> 和<code>1</code>。</li>
> 	<li>输入数组的长度是正整数，且不超过 10,000。</li>
> </ul>
> </div></div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max = INT_MIN;
        for(int num : nums) {
            if(num == 1) count++;
            else count = 0;
            if(count > max) max = count;
        }
        return max;
    }
};
```

思路：
使用一个计数变量count对连续的1计数，再使用一个变量max对出现过的count的最大值做记录。遍历完成返回max。

<div style="text-align: right"> 2019/05/09 19:47 </div>
