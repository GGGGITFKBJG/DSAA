### 414. 第三大的数
> <div
> class="content__2ebE"><p>给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [3, 2, 1]
> 
> <strong>输出:</strong> 1
> 
> <strong>解释:</strong> 第三大的数是 1. </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> [1, 2]
> 
> <strong>输出:</strong> 2
> 
> <strong>解释:</strong> 第三大的数不存在, 所以返回最大的数 2 . </pre>
> 
> <p><strong>示例 3:</strong></p>
> 
> <pre><strong>输入:</strong> [2, 2, 3, 1]
> 
> <strong>输出:</strong> 1
> 
> <strong>解释:</strong> 注意，要求返回第三大的数，是指第三大且唯一出现的数。 存在两个值为2的数，它们都排第二。
> </pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for(int num : nums) {
            if(num > first) {
                third = second;
                second = first;
                first = num;
            }
            else if(num > second && num < first) {
                third = second;
                second = num;
            }
            else if(num > third && num < second) {
                third = num;
            }
        }
        return third == LONG_MIN ? first : third;
    }
};
```

这道题很简单，但是有坑。注意三个变量用的类型是long，如果用int的话，输入含有INT_MIN时就会出BUG。这里我们用变量等于LONG_MIN来标识该变量是无效的。
题上有要求，如果不存在第三大的数（例如有两个第一名或两个第二名，又或是只有三个以下的输入），需要判断是否存在第三大的数。这里判断third是否有效（third == LONG_MIN），若无效返回first，否则返回third。

<div style="text-align: right"> 2019/05/04 12:58  </div>
