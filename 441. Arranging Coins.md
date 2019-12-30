### 441. 排列硬币
> <div
> class="content__2ebE"><p>你总共有&nbsp;<em>n&nbsp;</em>枚硬币，你需要将它们摆成一个阶梯形状，第&nbsp;<em>k&nbsp;</em>行就必须正好有&nbsp;<em>k&nbsp;</em>枚硬币。</p>
> 
> <p>给定一个数字&nbsp;<em>n</em>，找出可形成完整阶梯行的总行数。</p>
> 
> <p><em>n&nbsp;</em>是一个非负整数，并且在32位有符号整型的范围内。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre>n = 5
> 
> 硬币可排列成以下几行: ¤ ¤ ¤ ¤ ¤
> 
> 因为第三行不完整，所以返回2. </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre>n = 8
> 
> 硬币可排列成以下几行: ¤ ¤ ¤ ¤ ¤ ¤ ¤ ¤
> 
> 因为第四行不完整，所以返回3. </pre> </div>

解法一
```cpp
//时间复杂度O(1), 空间复杂度O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        return sqrt(8 * (double)(n) + 1) / 2 - 0.5;
    }
};
```

这个题相当于给定数列1, 2, 3, ... 的前x项和sum，求x。只不过在于给的n不一定刚好是前x项和sum，有可能比sum大，但是这不影响我们使用公式 sum = x (x + 1) / 2。对此方程使用求根公式，取正的解，再转为int返回即可。为了避免溢出，先将n转为double类型再参与运算。

<div style="text-align: right">  2019/05/05 19:42   </div>
