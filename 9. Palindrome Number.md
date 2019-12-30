### 9. 回文数

> <html>
> <div><p>判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> 121 <strong>输出:</strong> true </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> -121 <strong>输出:</strong> false
> <strong>解释:</strong> 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。 </pre>
> 
> <p><strong>示例 3:</strong></p>
> 
> <pre><strong>输入:</strong> 10 <strong>输出:</strong> false
> <strong>解释:</strong> 从右向左读, 为 01 。因此它不是一个回文数。 </pre>
> 
> <p><strong>进阶:</strong></p>
> 
> <p>你能不将整数转为字符串来解决这个问题吗？</p> </div></html>

解法一
```cpp
//输化为字符串, 从两头遍历
//输入整数为n，其长度转化为字符串的位数占{log10(n)向下取整 + 1}
//时间复杂度O(log10(n)), 空间复杂度O(log10(n))
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        ostringstream oss;
        oss << x;
        string s = oss.str();
        int i = 0, j = s.length() - 1;
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
```
解法二
```cpp
//不转为字符串
//为了防止溢出, 只反转一半位数
//例如输入 x = 12321
// temp              y       x
//   1(<x)           1      1232
//  12(<x)           12     123
//  123(=x, break)
//此时 x = 123, y = 12
// return (x == y) || (y * 10 + x % 10 == x); 返回真

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x >= 10 && x % 10 == 0)) return false;//负数和大于9的个位为0的数都排除
        int y = 0;
        while(x != 0) {
            int temp = y * 10 + x % 10;
            if(temp >= x) break;//temp >= x时表示已经反转一半的数量
            y = temp;
            x = x / 10;
        }
        //这时y一定小于等于x, 等于则返回真; 小于则给y补末位, 再判断
        return (x == y) || (y * 10 + x % 10 == x);
    }
};
```
解法三
```cpp
//leetcode官方题解
public class Solution {
    public bool IsPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber/10;
    }
}
```
总结：
一、解法一最简单，时间复杂度为O(log10(n))，同时有空间需求O(log10(n))；但进阶提问要求不使用转换为字符串；
二、可以用一个队列，将x从低到高入队，再依次出队从高到低构建一个y，返回y == x，此法没有使用转化字符串，但空间复杂度仍为O(log10(n))，而且要处理溢出问题；
三、解法二、解法三思路一样，为了避免溢出，只反转一半数字。时间复杂度为O(log10(n))，空间复杂度为O(1)，效率最高，思考略微复杂。容易错的地方在特殊情况判断那里：
1. 负数一定不是回文数；
2. 结尾为0的一定不是回文数，但0除外