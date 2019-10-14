### 202. 快乐数

> <div class="content__2ebE"><p>编写一个算法来判断一个数是不是“快乐数”。</p>
> 
> <p>一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为
> 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。</p>
> 
> <p><strong>示例:&nbsp;</strong></p>
> 
> <pre><strong>输入:</strong> 19 <strong>输出:</strong> true <strong>解释: 
> </strong>1<sup>2</sup> + 9<sup>2</sup> = 82 8<sup>2</sup> +
> 2<sup>2</sup> = 68 6<sup>2</sup> + 8<sup>2</sup> = 100 1<sup>2</sup> +
> 0<sup>2</sup> + 0<sup>2</sup> = 1 </pre> </div>

解法一
```cpp
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us = {n};
        while(true) {
            int res = 0;
            while(n > 0) {
                int temp = n % 10;
                res += temp * temp;
                n /= 10;
            }
            if(res == 1) return true;
            if(us.count(res)) return false;
            us.insert(res);
            n = res;
        }
    }
};
```

关键在于用一个哈希表存储已经计算得到的和。若等于1返回true，若重复返回false，否则继续循环。

<div style="text-align: right"> 2019/04/27 20:23  </div>