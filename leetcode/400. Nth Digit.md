### 400. 第N个数字

> <div class="content__2ebE"><p>在无限的整数序列&nbsp;1, 2, 3, 4, 5, 6, 7, 8, 9,
> 10, 11, ...中找到第&nbsp;<em>n&nbsp;</em>个数字。</p>
> 
> <p><strong>注意:</strong><br>
> <em>n&nbsp;</em>是正数且在32为整形范围内&nbsp;(&nbsp;<em>n</em> &lt;
> 2<sup>31</sup>)。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> 3
> 
> <strong>输出:</strong> 3 </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> 11
> 
> <strong>输出:</strong> 0
> 
> <strong>说明:</strong> 第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...
> 里是<strong>0</strong>，它是10的一部分。 </pre> </div>

解法一
```cpp
class Solution {
public:
    int findNthDigit(int n) {
        int count = 9, i = 1, sum = 0, start = 1;//count是位数为i的所有数字的个数, sum是位数小于i的所有数字个数之和
        while (i < 9 && n - sum > i * count) {
            sum += i * count;
            count *= 10;
            i++;
            start *= 10;
        }
        int target = (n - sum - 1) / i + start;//此时一定有 n - sum > 0(因为=0的情况会被锁定在上一区间)
        return to_string(target)[(n - sum - 1) % i] - '0';
    }
};
```

这个题表述很简单，求解起来细节较多。如下：
1. 先找下规律：
           i       |    count   |    start                  |         sum+=   i * count  
位数为1的数字有9个：     【1，9】 ，区间内总数字位数 = 1 * 9；
位数为2的数字有90个： 【10，99】，区间内总数字位数 = 2 * 90；
位数为3的数字有900个： 【100，999】，区间内总数字位数 = 3 * 900；
... ...
位数为 i 的数字有 9 * 10^(i - 1) 个： 【10^(i - 1) ，10^i - 1】，区间内总数字位数 = i * 9 * 10^(i - 1) ；
... ...
位数为8的数字有 9 * 10, 000, 000个：【10, 000, 000，99, 999, 999】，区间内总数字位数 = 8 * 9 * 10, 000, 000 < INT_MAX；
位数为9的数字有 9 * 100, 000, 000个：【100, 000, 000，999, 999, 999】，区间内总数字位数 = 9 * 9 * 100, 000, 000 > INT_MAX；
... ...
2. 规律也很清晰，我们就设置一个变量 i 记录当前区间单个数字的位数，count记录当前区间的数字个数，start记录当前区间左端点，sum记录当前区间之前的数字位数和，初始时sum为区间【1，9】之前的位数和（也就是0）。
3. 输入n，我们先判断它与sum之差是否小于count * i（当前区间数字位数和）。若小于，说明当前i所代表的区间就包含n；否则更新i、count、start、sum这几个参数到下一区间。
4. 满足以上条件后，我们已经锁定了n的区间，下一步是要确定目标数字target。区间内所有数字位数都为i，所以我们可以用n与sum之差对i 作整数除法，来获得target与左端点start的偏移。其中n - sum - 1中减1的目的是将元素的次序转化为下标。所以
int target = (n - sum - 1) / i + start;

5. 目标数字找到了，n就在其中。用n对i取余，就是n在target中的偏移 (n - sum - 1) % i。首先将target转为字符串，有了偏移，就可以以下标方式访问到答案了！最后别忘了返回类型是int，所以要求其与 '0' 的差。

<div style="text-align: right"> 2019/05/01 20:06   </div>
