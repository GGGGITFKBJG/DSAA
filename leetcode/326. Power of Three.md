### 326. 3的幂

> <div class="content__2ebE"><p>给定一个整数，写一个函数来判断它是否是 3&nbsp;的幂次方。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> 27 <strong>
> 输出:</strong> true </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> 0 <strong>
> 输出:</strong> false</pre>
> 
> <p><strong>示例 3:</strong></p>
> 
> <pre><strong>输入:</strong> 9 <strong>
> 输出:</strong> true</pre>
> 
> <p><strong>示例 4:</strong></p>
> 
> <pre><strong>输入:</strong> 45 <strong>
> 输出:</strong> false</pre>
> 
> <p><strong>进阶：</strong><br> 你能不使用循环或者递归来完成本题吗？</p> </div>

解法一
```cpp
//时间复杂度O(log3(n)), 空间复杂度O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n % 3 == 0) n /= 3;
        return n == 1;
    }
};
```

解法二
```cpp
//时间复杂度O(1), 空间复杂度O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n == 1 ? true : n > 1 && 1162261467 % n == 0;
    }
};
```

解法三
```cpp
//时间复杂度O(1), 空间复杂度O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        return int(log10(n) / log10(3)) == log10(n) / log10(3);
    }
};
```

解法一，很直接；（缺点就是慢，O(log3(n))，虽然不是常数时间，但看起来也可以接受）；
解法二，把int范围内最大的3的幂拿出来，判断是否能整除n，能则是，否则不是（弊端是如果int存储大小变了代码也要改）；
解法三，用了数学库函数，求幂的对数，判断是否为整数，时间复杂度同为O(1)（但没有算使用库函数的开销，说不定更大呢？）。

<div style="text-align: right"> 2019/04/30 22:59  </div>