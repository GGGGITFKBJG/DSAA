### 461. 汉明距离

> <div class="content__2ebE"><p>两个整数之间的<a
> href="https://baike.baidu.com/item/%E6%B1%89%E6%98%8E%E8%B7%9D%E7%A6%BB">汉明距离</a>指的是这两个数字对应二进制位不同的位置的数目。</p>
> 
> <p>给出两个整数 <code>x</code> 和 <code>y</code>，计算它们之间的汉明距离。</p>
> 
> <p><strong>注意：</strong><br> 0 ≤ <code>x</code>, <code>y</code> &lt;
> 2<sup>31</sup>.</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> x = 1, y = 4
> 
> <strong>输出:</strong> 2
> 
> <strong>解释:</strong> 1   (0 0 0 1) 4   (0 1 0 0)
>        ↑   ↑
> 
> 上面的箭头指出了对应二进制位不同的位置。 </pre> </div>

解法一
```cpp
//时间复杂度O(?), 空间复杂度O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x ^ y, res = 0;
        while(t) {
            t &= t - 1;
            res++;
        }
        return res;
    }
};
```

和第191题类似，不过是多了一个步骤。首先用按位异或运算求出x和y不同的位保存为t，然后再用第191题的方法，计算t中位1的个数。

<div style="text-align: right"> 2019/05/08 19:19  </div>