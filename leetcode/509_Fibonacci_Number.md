### 509. 斐波那契数
> <div class="content__2ebE"><div><p><strong>斐波那契数</strong>，通常用&nbsp;<code>F(n)</code> 表示，形成的序列称为<strong>斐波那契数列</strong>。该数列由&nbsp;<code>0</code> 和 <code>1</code> 开始，后面的每一项数字都是前面两项数字的和。也就是：</p>
> 
> <pre>F(0) = 0,&nbsp; &nbsp;F(1)&nbsp;= 1
> F(N) = F(N - 1) + F(N - 2), 其中 N &gt; 1.
> </pre>
> 
> <p>给定&nbsp;<code>N</code>，计算&nbsp;<code>F(N)</code>。</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例 1：</strong></p>
> 
> <pre><strong>输入：</strong>2
> <strong>输出：</strong>1
> <strong>解释：</strong>F(2) = F(1) + F(0) = 1 + 0 = 1.
> </pre>
> 
> <p><strong>示例 2：</strong></p>
> 
> <pre><strong>输入：</strong>3
> <strong>输出：</strong>2
> <strong>解释：</strong>F(3) = F(2) + F(1) = 1 + 1 = 2.
> </pre>
> 
> <p><strong>示例 3：</strong></p>
> 
> <pre><strong>输入：</strong>4
> <strong>输出：</strong>3
> <strong>解释：</strong>F(4) = F(3) + F(2) = 2 + 1 = 3.
> </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>提示：</strong></p>
> 
> <ul>
> 	<li>0 ≤ <code>N</code> ≤ 30</li>
> </ul>
> </div></div>

解法一
```cpp
//时间复杂度O(N), 空间复杂度O(1)
class Solution {
public:
    int fib(int N) {
        int t1 = 0, t2 = 1;
        while(N-- > 0) {
            int temp = t1 + t2;
            t1 = t2;
            t2 = temp;
        }
        return t1;
    }
};
```

解法二
```cpp
//时间复杂度O(2^(N-1)), 空间复杂度O(1)
class Solution {
public:
    int fib(int N) {
       if(N == 0) return 0;
       if(N == 1) return 1;
       return fib(N - 1) + fib(N - 2);
    }
};
```

解法三
```cpp
//时间复杂度O(N), 空间复杂度O(N)
class Solution {
public:
    int fib(int N, vector<int>& rec) {
        if(rec[N] == -1) rec[N] = fib(N - 1, rec) + fib(N - 2, rec);
        return rec[N];
    }
    int fib(int N) {
       vector<int> rec(N + 1, -1);
       rec[0] = 0;
       if(N > 0) rec[1] = 1;
       return fib(N, rec);
    }
};
```

解法一
迭代法，使用两个变量，反复地计算两者之和，进行N次得到答案。

解法二
递归解法，优点是编程简单，缺点是当N很大时效率很低，因为递归解会有大量的重复计算。

解法三
记忆优化递归，与解法二唯一不同点在于，它使用了一个数组，避免了对重复子问题的冗余计算。

总得来看，递归法虽然很好用，但是有时需要好好思考一下，相比编码上的轻松，付出运行时间上的代价是否值得。

<div style="text-align: right"> 2019/05/25 22:14 </div>
