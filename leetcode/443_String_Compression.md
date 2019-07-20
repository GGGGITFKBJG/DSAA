### 443. 压缩字符串

> <div class="content__2ebE"><p>给定一组字符，使用<a
> href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95">原地算法</a>将其压缩。</p>
> 
> <p>压缩后的长度必须始终小于或等于原数组长度。</p>
> 
> <p>数组的每个元素应该是长度为1&nbsp;的<strong>字符</strong>（不是 int 整数类型）。</p>
> 
> <p>在完成<a
> href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95">原地</a><strong>修改输入数组</strong>后，返回数组的新长度。</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>进阶：</strong><br> 你能否仅使用O(1) 空间解决问题？</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例 1：</strong></p>
> 
> <pre><strong>输入：</strong> ["a","a","b","b","c","c","c"]
> 
> <strong>输出：</strong> 返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]
> 
> <strong>说明：</strong> "aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。 </pre>
> 
> <p><strong>示例 2：</strong></p>
> 
> <pre><strong>输入：</strong> ["a"]
> 
> <strong>输出：</strong> 返回1，输入数组的前1个字符应该是：["a"]
> 
> <strong>说明：</strong> 没有任何字符串被替代。 </pre>
> 
> <p><strong>示例 3：</strong></p>
> 
> <pre><strong>输入：</strong>
> ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
> 
> <strong>输出：</strong> 返回4，输入数组的前4个字符应该是：["a","b","1","2"]。
> 
> <strong>说明：</strong> 由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
> 注意每个数字在数组中都有它自己的位置。 </pre>
> 
> <p><strong>注意：</strong></p>
> 
> <ol> 	<li>所有字符都有一个ASCII值在<code>[35, 126]</code>区间内。</li> 	<li><code>1
> &lt;= len(chars) &lt;= 1000</code>。</li> </ol> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, p = 0;
        while(i < chars.size()) {
            char c = chars[i];
            int begin = i;
            while(i < chars.size() && chars[i] == c) i++;
            int len = i - begin;
            chars[p++] = c;
            if(len > 1) for(char temp : to_string(len)) chars[p++] = temp;
        }
        return p;
    }
};
```

此题通常的思路是遍历一次，对连续出现的字符数量作记录，然后从前至后构建一个新的字串。但是题上要求空间需求为O(1)。
仔细想一想，字符连续出现一次，不需要在其后加数字字符；字符连续出现10个以下，需要加个一个数字字符；超过10但小于100，需要加两个数字字符；总之，连续字符的长度，总是比要追加的数字字符的长度要长，这为我们原地（不开辟新的空间）改变数组提供了基础。
1. 我们使用两个指针，i 表示遍历过程中要读取字符的指针，p表示将要写入字符的指针，刚开始两者都为0， 但后面 i 始终在p的前面；
2. 每次i遇到一个新的字符，先将其字符及位置记录下来（c和begin），再次移动 i ，遍历到非c的字符时停下；
3. 这时记录i走过的长度len，这是出现的连续字符的长度；
4. 在p的位置上首先写入字符c，再写入字符c的个数，同时向前移动p；
5. 再次启动 i 向后遍历，重复上述操作直到 i 到达结尾，返回的p即新构建字符串的长度。

<div style="text-align: right">   2019/05/05 20:49  </div>
