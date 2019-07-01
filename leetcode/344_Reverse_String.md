### 344. 反转字符串

> <div class="content__2ebE"><p>编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组
> <code>char[]</code> 的形式给出。</p>
> 
> <p>不要给另外的数组分配额外的空间，你必须<strong><a
> href="https://baike.baidu.com/item/原地算法">原地</a>修改输入数组</strong>、使用 O(1)
> 的额外空间解决这一问题。</p>
> 
> <p>你可以假设数组中的所有字符都是 <a
> href="https://baike.baidu.com/item/ASCII">ASCII</a> 码表中的可打印字符。</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例 1：</strong></p>
> 
> <pre><strong>输入：</strong>["h","e","l","l","o"]
> <strong>输出：</strong>["o","l","l","e","h"] </pre>
> 
> <p><strong>示例 2：</strong></p>
> 
> <pre><strong>输入：</strong>["H","a","n","n","a","h"]
> <strong>输出：</strong>["h","a","n","n","a","H"]</pre> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};
```

呃，此题很单纯。

<div style="text-align: right"> 2019/04/30 23:12   </div>