### 405. 数字转换为十六进制数

> <div
> class="content__2ebE"><p>给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用&nbsp;<a
> href="https://baike.baidu.com/item/%E8%A1%A5%E7%A0%81/6854613?fr=aladdin">补码运算</a>&nbsp;方法。</p>
> 
> <p><strong>注意:</strong></p>
> 
> <ol> 	<li>十六进制中所有字母(<code>a-f</code>)都必须是小写。</li>
> 	<li>十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符<code>'0'</code>来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。&nbsp;</li>
> 	<li>给定的数确保在32位有符号整数范围内。</li>
> 	<li><strong>不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。</strong></li> </ol>
> 
> <p><strong>示例 1：</strong></p>
> 
> <pre>输入: 26
> 
> 输出: "1a" </pre>
> 
> <p><strong>示例 2：</strong></p>
> 
> <pre>输入: -1
> 
> 输出: "ffffffff" </pre> </div>

解法一
```cpp
class Solution {
public:
	Solution() : table("0123456789abcdef") {}
	string toHex(int num) {
		string res = "";
		int first = (num & 0xf0000000) >> 28;//单独处理符号位
		res += table[first];//最高位

		int mask = 0x0f000000;
		int shift = 24;//移位数
		while (mask != 0) {
			int temp = (num & mask) >> shift;
			res += table[temp];
			shift -= 4;
			mask >>= 4;
		}
		int start = 0;
		while (start < res.length() - 1 && res[start] == '0') start++;
		return res.substr(start);
	}
private:
	string table;
};
```

解法二
```cpp
class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        string table = "0123456789abcdef";
        string res = "";
        while(num != 0 && res.size() != 8) {//两个条件缺一不可
            res = table[num & 0xf] + res;
            num >>= 4;
        }
        return res;
    }
};
```

解法一是我一开始写的。最开始需要对高4位先进行与运算（因为对负数0xf0000000右移是算术右移，得到的是0xff000000，而不是想要的0x0f000000）,然后再从0x0f000000开始，向右依次扫描至最后。因为从高位到低位扫描，字符串里包含了‘0’，所以最后要找到第一个非'0'的字符，截断后输出。
解法二更加紧凑。为了不处理高位的情况，这种解法选择了对输入变量num进行右移（而不是移动mask），而始终对最低4位进行与操作。这样判断条件num != 0处理了高位多余的‘0’，又判断了右移的边界（对正数右移8次之后就会得到0；对于有前导0的正数，又刚好会在合适的地方停止循环），至于负数，循环地右移（是算术右移）最后会得到-1（而不是0），显然不能以-1为判断条件（因为输入的num可能就是-1），所以我们以字符串res的长度8为界限，当字符串长度为8时，说明已经右移32位了，这时候要停下来。

<div style="text-align: right">  2019/05/04 00:48   </div>