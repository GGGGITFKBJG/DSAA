### 70. 爬楼梯
> <div class="content__2ebE"><div><p>假设你正在爬楼梯。需要
> <em>n</em>&nbsp;阶你才能到达楼顶。</p>
> 
> <p>每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？</p>
> 
> <p><strong>注意：</strong>给定 <em>n</em> 是一个正整数。</p>
> 
> <p><strong>示例 1：</strong></p>
> 
> <pre><strong>输入：</strong> 2 <strong>输出：</strong> 2
> <strong>解释：</strong> 有两种方法可以爬到楼顶。
> 1.  1 阶 + 1 阶
> 2.  2 阶</pre>
> 
> <p><strong>示例 2：</strong></p>
> 
> <pre><strong>输入：</strong> 3 <strong>输出：</strong> 3
> <strong>解释：</strong> 有三种方法可以爬到楼顶。
> 1.  1 阶 + 1 阶 + 1 阶
> 2.  1 阶 + 2 阶
> 3.  2 阶 + 1 阶 </pre> </div></div>

解法一
```cpp
//回溯法(低效)
//时间复杂度O(2^n), 空间复杂度O(n)
//树形递归的大小为2^n
class Solution {
public:
    int climb(int step, int havePassed, int n) {//返回以后所有方法的个数
        if(step + havePassed > n) return 0;//该步爬过了，不计数
        if(step + havePassed == n) return 1;//该步爬到楼顶了，返回1
        //返回: 爬1阶+爬2阶
        return climb(1, havePassed + step, n) + climb(2, havePassed + step, n);
    }
   
    int climbStairs(int n) {
        return climb(1, 0, n) + climb(2, 0, n);
    }
};
```

解法二
```cpp
//回溯法(带缓存优化版)
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    Solution() : sol({1, 1}) {}
    int climbStairs(int n) {
        //n是剩余要走的阶数
        if(n < 0) return 0;//走过了，返回0
        if(n < sol.size()) return sol[n];//已经计算过, 直接查表
        int p = climbStairs(n - 1) + climbStairs(n - 2);
        sol.push_back(p);
        return p;//剩余n阶要走，计算解的数目
    }
private:
    vector<int> sol;//记录已计算过的解
};
```

解法三
```cpp
#组合公式, Python代码
#时间复杂度O(n^2), 空间复杂度O(1)
class Solution:
    def combination(self, n, r): #组合数公式C(n, r) = n! / r! / (n - r)!
        t1 = 1
        t2 = 1
        diff = n - r
        while n > diff:
            t1 *= n
            n = n - 1
        while r > 1:
            t2 *= r
            r = r - 1
        return int(t1 / t2)
    def climbStairs(self, n: int) -> int:
        count = 0
        for i in range(math.floor(n / 2) + 1):
            count = count + Solution.combination(self, n - i, i)
        #return combination(8, 0);
        return count
```

解法四
```cpp
//动态规划
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) return 1;
        int* d = new int[n + 1];
        d[0] = 1;
        d[1] = 1;
        for(int i = 2; i <= n; i++) {
            d[i] = d[i - 1] + d[i - 2];
        }
        return d[n];
    }
};
```

解法五
```cpp
//菲波那契公式
class Solution {
public:
    int climbStairs(int n) {
        double temp1 = (1 + sqrt(5)) / 2;
        double temp2 = (1 - sqrt(5)) / 2;
        return (int)( 1 / sqrt(5) * (pow(temp1, n + 1) - pow(temp2, n + 1)) );
    }
};
```

解法一：
穷举所有可能。其递归树是个二叉树，时间复杂度O(2^n)，每层递归空间需求是个常数，共n层，所是空间复杂度为O(n)。采用这种解法，n较小时还可以求解。这是leetcode官方题解上第一种解法，但是效率极低，实际提交甚至都通不过检测（超时错误）。

解法二：
仍是穷举法，使用了一个数组，记录先前的计算结果。优化了解法一，减少了不必要的计算。。

解法三：
用到了排列组合的知识，用Python代码原因是不用考虑计算阶乘时溢出的问题。大体思路是：
1. 对于n阶的楼梯，一次上2阶的步数最小为0，最多为n / 2；
2. 于是就对一次上2阶的步数进行遍历（0到n/2），累加各种情况的解的数目；
3. 对于每个情况，当上2阶的步数为i时，其解的数目为C(n - i, i)。例如C(n, 0) = 1代表上2阶的步数为0，也就是全部用1阶走完整个楼梯，只有一种走法；C(n - 1, 1) = n - 1代表2阶的步数为1，其余都用1阶的方式来走完，有n - 1种走法；依此类推，2阶的步数最多有 n / 2个，也就是C(n / 2, n / 2) = 1，只有1种走法；
4. 对以上遍历结果求和，也就是res = C(n, 0) + C(n - 1, 1) + C(n - 2, 2) + ... + C(n / 2, n / 2)，返回res。

解法四：
动态规划法，需要额外的线性空间来存储状态函数值：
1. 选取状态函数：选取d(i) 为爬i阶楼梯的所有解的数目，n阶楼梯一共有n种状态，此题要求的是d(n)；
2. 状态转移方程：在面对有i阶楼梯的情况下，可以选择迈出1步，剩下i - 1阶也就是有d(i - 1)种可能 ；也可以选择迈出2步也就是有d(i - 2)种可能。两者之和即为i阶情况的解数目。即
d(i) = d(i - 1) + d(i - 2)
3. 看方程，需要初始化前两个状态。我们这里取d(0) = 1（表示没有楼梯可爬，那只有不爬这一种可能），d(1) = 1。
4. 遍历一次，d(n)即是此题的解。

解法五：
第一眼看到解法四的方程怎么感觉这么熟悉呢？没错这就是大名鼎鼎的菲波那契数列的递推公式。爬楼梯问题不一定见过，这个问题一定见过吧，毕竟小学课本上就有。思路如下：
1. 我们可以用递推法求解，省去了状态函数用的数组，用两个临时变量来保存上两步的结果，遍历一次就是我们要的结果；
2. 但是更进一步，我们要站在巨人的肩膀上，这个问题已经有前人给我们总结的现成公式了：
![斐波那契计算公式](https://img-blog.csdnimg.cn/20190526000347337.png)
 <div style="text-align: right">  2019/04/27 19:18 </div>