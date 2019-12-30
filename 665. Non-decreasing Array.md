### 665. 非递减数列

> <div class="content__2ebE"><p>给定一个长度为&nbsp;<code>n</code>&nbsp;的整数数组，你的任务是判断在<strong>最多</strong>改变&nbsp;<code>1</code> 个元素的情况下，该数组能否变成一个非递减数列。</p>
> 
> <p>我们是这样定义一个非递减数列的：&nbsp;对于数组中所有的&nbsp;<code>i</code> (1 &lt;= i &lt; n)，满足&nbsp;<code>array[i] &lt;= array[i + 1]</code>。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [4,2,3]
> <strong>输出:</strong> True
> <strong>解释:</strong> 你可以通过把第一个4变成1来使得它成为一个非递减数列。
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> [4,2,1]
> <strong>输出:</strong> False
> <strong>解释:</strong> 你不能在只改变一个元素的情况下将其变为非递减数列。
> </pre>
> 
> <p><strong>说明:&nbsp;&nbsp;</strong><code>n</code> 的范围为 [1, 10,000]。</p>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return true;
        int count = 0, last = INT_MIN;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] < nums[i]) {
                if(nums[i + 1] >= last) nums[i] = nums[i + 1];
                else nums[i + 1] = nums[i];
                count++;
                if(count == 2) return false;
            }
            last = nums[i];
        }
        return true;
    }
};
```

这个问题有些复杂，需要理下思路。我们只用考虑连续三个元素的关系，对于以下的子序列：

<pre>
        ..., an-1, an, an+1, ...
</pre>

1. 我们从索引i = 0开始遍历到i = n - 1，遍历过程中，an是当前元素；
2. 设置一个变量last，记录an - 1；一个变量count，记录不满足（不严格）增序的数对个数，也就是说，如果an > an+1，就对count加1；
3. 遍历过程中顺便修正数组使其满足增序，如果遇到 ***an > an+1*** 时，分两种情况进行修改：①如果 ***an+1 >= last*** ，我们需要使 ***an = an+1***；②如果 ***an+1 < last***，此时需要让 ***an+1 = an***；
4. 如果发现计数count达到2，说明不能只修改一次，返回false；
5. 遍历完成，返回true。

<div style="text-align: right"> 2019/06/16 21:26 </div>