### 7. 整数反转
> <html>
> <div><p>给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> 123 <strong>输出:</strong> 321 </pre>
> 
> <p><strong>&nbsp;示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> -123 <strong>输出:</strong> -321 </pre>
> 
> <p><strong>示例 3:</strong></p>
> 
> <pre><strong>输入:</strong> 120 <strong>输出:</strong> 21 </pre>
> 
> <p><strong>注意:</strong></p>
> 
> <p>假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为&nbsp;[−2<sup>31</sup>,&nbsp;
> 2<sup>31&nbsp;</sup>− 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。</p> </div></html>

解法一

```cpp
//关键在是否溢出的判断上
//对于int长4字节的情况, INTMAX = 2147483647, INTMIN = -2147483648
//minOfInt = -2147483648; //这一行2147483648先被解析为ulong, 然后-ulong仍是ulong, 再初始化为int, 明显是错的
class Solution {
public:
    int reverse(int x) {//输入的x首先是合法的int
        const int maxOfInt = 2147483647;
        const int minOfInt = -2147483647 - 1;//避免-2147483648被解析为unsigned long
        int result = 0;
        while(x != 0) {//不用判断x的正负
            int temp = x % 10;
            if((result > maxOfInt / 10) ||//前两行对应x为正数的情况
               (result == maxOfInt / 10 && temp > 7) ||
               (result < minOfInt / 10) ||//后两行对应x为负数的情况
               (result == minOfInt / 10 && temp < -8)) return 0;
            result = result * 10 + temp;//对负数取余结果是负数
            x /= 10;
        }
        return result;
    }
};
```
如果不考虑溢出问题，此题会非常简单。
溢出的地方在result = result * 10 + temp 这一行，有一个乘法和一个加法，其中检测了4个条件：
1. x > 0 且 result > maxOfInt / 10; 乘法溢出
2. x > 0 且 result = maxOfInt / 10 且 x % 10 > 7; 乘法不溢出，加法溢出
3. x < 0 且 result < minOfInt / 10;乘法溢出
4. x < 0 且 result < minOfInt / 10 且 x % 10 < -8;乘法不溢出，加法溢出

再多想一想，不检测加法溢出也不会有错。输入的x首先保证是个合法int，要想出现溢出x一定得是个10位整数，作为一个10位的合法int，x的高位必定小于等于2，比如x取1463847413。意味着最后一步x % 10只能是1或2（-1或-2），一定小于7（大于-8），肯定不会产生加法溢出。