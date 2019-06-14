### 204. 计数质数

> <div
> class="content__2ebE"><p>统计所有小于非负整数&nbsp;<em>n&nbsp;</em>的质数的数量。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> 10 <strong>输出:</strong> 4
> <strong>解释:</strong> 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。 </pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        int res = 0;
        int sq = sqrt(n);
        for(int i = 2; i <= sq; i++) {
            if(!isPrime[i]) continue;
            for(int j = 2; i * j < n; j++) {//如果i是质数, 排除i的倍数
                isPrime[i * j] = false;
            }
        }
        for(int i = 2; i < n; i++) {
            if(isPrime[i]) res++;
        }
        return res;
    }
};
```

一开始用常规的搜索方法O(n^2)，没有通过测试（超时错误）。解法一用的是埃拉托斯特尼筛法：
1. 维护一个长为n的数组，用来标记元素i是否是质数，初始化都为true；
2. 从2开始遍历，找到第一个质数，将所有其倍数的标志设为false；
3. 找下一个质数，反复进行2的操作；
4. 遍历完后，统计数组true的个数，即是质数的个数。

<div style="text-align: right">  2019/04/27 23:19  </div>