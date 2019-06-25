### 258. 各位相加

> <div class="content__2ebE"><p>给定一个非负整数
> <code>num</code>，反复将各个位上的数字相加，直到结果为一位数。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> <code>38</code> <strong>输出:</strong> 2 
> <strong>解释: </strong>各位相加的过程为<strong>：</strong><code>3 + 8 =
> 11</code>, <code>1 + 1 = 2</code>。 由于&nbsp;<code>2</code> 是一位数，所以返回 2。
> </pre>
> 
> <p><strong>进阶:</strong><br> 你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？</p>
> </div>

解法一
```cpp
class Solution {
public:
    int addDigits(int num) {
        while(true) {
            int sum = 0;
            while(num > 0) {
                sum += num % 10;
                num /= 10;
            }
            if(sum < 10) return sum;
            num = sum;
        }
    }
};


class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
```

解法一，常规思路，按题目要求实现出来即可。
解法二，找规律，对n取9的余（9的倍数对9取余也看作9），这个没什么好说的。

<div style="text-align: right"> 2019/04/29 13:38    </div>