### 628. 三个数的最大乘积

> <div class="content__2ebE"><p>给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [1,2,3]
> <strong>输出:</strong> 6
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> [1,2,3,4]
> <strong>输出:</strong> 24
> </pre>
> 
> <p><strong>注意:</strong></p>
> 
> <ol>
> 	<li>给定的整型数组长度范围是[3,10<sup>4</sup>]，数组中所有的元素范围是[-1000, 1000]。</li>
> 	<li>输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。</li>
> </ol>
> </div>

解法一
```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3],
                   nums[0] * nums[1] * nums[n - 1]);
    }
};
```

解法二
```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN, n1 = INT_MAX, n2 = INT_MAX;
        for(int num : nums) {
            if(num > m3) {
                m1 = m2;
                m2 = m3;
                m3 = num;
            }
            else if(num <= m3 && num > m2) {
                m1 = m2;
                m2 = num;
            }
            else if(num <= m2 && num > m1) m1 = num;
            if(num < n2) {
                n1 = n2;
                n2 = num;
            }
            else if(num >= n2 && num < n1) n1 = num;
        }
        return max(m1 * m2 * m3, m3 * n2 * n1);
    }
};
```

想要得到最大乘积，不仅要考虑因子的绝对值，但也要同时考虑正负号。考虑几种情况：
1. 数组元素全为负。三数之积已经注定是负数了，那此时要选绝对值最小的前三个元素（也就是最大的三个负数）作为因子；
2. 数组元素全为正。三数之积必定为正数，那此时要选绝对值最大的前三个元素（也就是最大的三个正数）作为因子；
3. 数组有正有负，此时稍复杂。

先考虑对数组按从小到大排序,

假设有序序列为a1，a2，a3，...，an-2，an-1，an。最大乘积只会在以下两种情况中出现：
1. an-2 * an-1 * an；
2. a1 * a2 * an。

取较大者返回即可。
解法一对数组排序，但其实没有必要。我们只需要找到最大的三个元素及最小的两个元素就足够，也就是解法二。

<div style="text-align: right"> 2019/06/12 23:46 </div>