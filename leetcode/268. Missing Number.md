### 268. 缺失数字

> <div class="content__2ebE"><p>给定一个包含 <code>0, 1, 2, ...,
> n</code>&nbsp;中&nbsp;<em>n</em>&nbsp;个数的序列，找出 0 ..
> <em>n</em>&nbsp;中没有出现在序列中的那个数。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [3,0,1] <strong>输出:</strong> 2 </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> [9,6,4,2,3,5,7,0,1] <strong>输出:</strong> 8
> </pre>
> 
> <p><strong>说明:</strong><br> 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?</p> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;//输入数组的和
        int temp = nums.size() * (nums.size() + 1) / 2;//原数组的和
        return temp - sum;
    }
};
```

解法二
```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = nums.size();//原数组最大值
        for (int i = 0; i < nums.size(); i++){
            s ^= nums[i];
            s ^= i;
        }
        return s;
    }
};
```

解法一
因为输入数组是连续的，其大小比原完整数组的大小小1。对原数组求和（直接用公式），减去输入数组的和，就是答案。

解法二
和之前136题（只出现一次的数字）方法类似，用到了按位异或运算。再把它的性质粘一遍：

异或是一种基于二进制的位运算，用符号XOR或者 ^ 表示，其运算法则是对运算符两侧数的每一个二进制位，同值取0，异值取1。

<pre>
性质
1、交换律 a^b = b^a
2、结合律（即(a^b)^c == a^(b^c)）
3、对于任何数x，都有x^x=0，x^0=x
4、自反性 A XOR B XOR B = A xor  0 = A
</pre>
-----------该片段摘自[异或的性质及运用](https://www.cnblogs.com/suoloveyou/archive/2012/04/25/2470292.html%29)

总结：

1. 初始化 s = 0，整体思路是，①使用s对原数组中的所有元素取按位异或，②再对输入数组中所有元素取按位异或，③最后s就是缺失的数；
2. 先对原数组最大值取按位异或，这时s = nums.size() & 0 = nums.size()（也就是代码中的第一步，nums.size()为原完整数组的最大值）；
3. 再对输入数组所有元素取s的按位异或（s ^= nums[i]），顺便把原始数组剩下的元素取按位异或（s ^= i）；
4. 遍历结束，返回s。

<div style="text-align: right"> 2019/04/29 14:08   </div>