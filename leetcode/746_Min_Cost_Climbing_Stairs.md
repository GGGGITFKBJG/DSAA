### 746. 使用最小花费爬楼梯

> <div class="content__2ebE"><p>数组的每个索引做为一个阶梯，第&nbsp;<code>i</code>个阶梯对应着一个非负数的体力花费值&nbsp;<code>cost[i]</code>(索引从0开始)。</p>
> 
> <p>每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。</p>
> 
> <p>您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> cost = [10, 15, 20]
> <strong>输出:</strong> 15
> <strong>解释:</strong> 最低花费是从cost[1]开始，然后走两步即可到阶梯顶，一共花费15。
> </pre>
> 
> <p><strong>&nbsp;示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
> <strong>输出:</strong> 6
> <strong>解释:</strong> 最低花费方式是从cost[0]开始，逐个经过那些1，跳过cost[3]，一共花费6。
> </pre>
> 
> <p><strong>注意：</strong></p>
> 
> <ol>
> 	<li><code>cost</code>&nbsp;的长度将会在&nbsp;<code>[2, 1000]</code>。</li>
> 	<li>每一个&nbsp;<code>cost[i]</code> 将会是一个Integer类型，范围为&nbsp;<code>[0, 999]</code>。</li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    int climb(int i, int step, const vector<int>& cost, vector<int>& rec) {
        if(i + step > cost.size()) return 0;
        if(rec[i + step - 1] != -1) return rec[i + step - 1];
        int s1 = climb(i + step, 1, cost, rec);
        int s2 = climb(i + step, 2, cost, rec);
        rec[i + step - 1] = min(s1, s2) + cost[i + step - 1];
        return rec[i + step - 1];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> rec(cost.size(), -1);
        int s1 = climb(0, 1, cost, rec);//i 当前已走0阶, step 下一步要上1阶
        int s2 = climb(0, 2, cost, rec);
        return min(s1, s2);
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int rec[n + 1];
        rec[n] = 0;
        rec[n - 1] = cost[n - 1];
        for(int i = n - 2; i >= 0; i--) rec[i] = cost[i] + min(rec[i + 1], rec[i + 2]);
        return min(rec[0], rec[1]);
    }
};
```

解法三
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int r1 = cost[n - 1], r2 = 0, r0;
        for(int i = n - 2; i >= 0; i--) {
            r0 = cost[i] + min(r1, r2);
            r2 = r1;
            r1 = r0;
        }
        return min(r1, r2);
    }
};
```

解法一

空间优化递归。建立一个表rec[n]记录踩上第i阶**之后**的总花费（第i阶及以后台阶的cost和）。climb函数的形参i代表当前已走过的台阶数；step代表下一步要上的台阶数。

1. 在主函数中调用climb，迈出第一步（上1阶或上2阶），返回花费较小的选择的cost。
2. 在递归函数climb中，先查表rec看当前所在的台阶（索引i + step - 1）是否已经计算过最小花费，若是直接返回；否则继续调用climb，并保存下计算过的结果到rec中。
3. 递归终止条件是已爬到最高阶（i + step > n），或者该阶及其后的最小花费已计算过（在表rec中有记录）。

解法二

迭代法。明白解法一的思路之后，发现可以倒序地构建rec数组而不使用递归。也就是
<pre>
    rec[n] = 0;//rec长度为n + 1
    rec[n - 1] = cost[n - 1];
    rec[i] = cost[i] + min(rec[i + 1], rec[i + 2]);
</pre>

最后返回min(rec[0], rec[1])即可。

解法三

思路和解法二一样，只是用了三个变量避免了rec数组的使用。

<div style="text-align: right"> 2019/06/29 14:23 </div>