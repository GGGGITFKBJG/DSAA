### 482. 密钥格式化
> <div class="content__2ebE"><div><p>给定一个密钥字符串S，只包含字母，数字以及 '-'（破折号）。N 个 '-' 将字符串分成了 N+1 组。给定一个数字 K，重新格式化字符串，除了第一个分组以外，每个分组要包含 K 个字符，第一个分组至少要包含 1 个字符。两个分组之间用 '-'（破折号）隔开，并且将所有的小写字母转换为大写字母。</p>
> 
> <p>给定非空字符串 S 和数字 K，按照上面描述的规则进行格式化。</p>
> 
> <p><strong>示例 1：</strong></p>
> 
> <pre><strong>输入：</strong>S = "5F3Z-2e-9-w", K = 4
> 
> <strong>输出：</strong>"5F3Z-2E9W"
> 
> <strong>解释：</strong>字符串 S 被分成了两个部分，每部分 4 个字符；
> &nbsp;    注意，两个额外的破折号需要删掉。
> </pre>
> 
> <p><strong>示例 2：</strong></p>
> 
> <pre><strong>输入：</strong>S = "2-5g-3-J", K = 2
> 
> <strong>输出：</strong>"2-5G-3J"
> 
> <strong>解释：</strong>字符串 S 被分成了 3 个部分，按照前面的规则描述，第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符。
> </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>提示:</strong></p>
> 
> <ol>
> 	<li>S 的长度不超过 12,000，K 为正整数</li>
> 	<li>S 只包含字母数字（a-z，A-Z，0-9）以及破折号'-'</li>
> 	<li>S 非空</li>
> </ol>
> 
> <p>&nbsp;</p>
> </div></div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int r = S.size() - 1;//read
        int count = 0;
        string res = "";
        while(r >= 0) {
            while(r >= 0 && S[r] == '-') r--;
            if(r < 0) break;
            if(count == K) {
                res += '-';
                count = 0;
            }
            res += S[r] < 'a' ? S[r--] : S[r--] - 32;
            count++;
        }
        return string(res.rbegin(), res.rend());
    }
};
```

思路：
本题与26题（删除重复元素）类似，只不过不能在原地修改，因为要添加'-'可能会覆盖掉原字符。

使用双指针法，一个指针r，res保存答案。

1. 指针r负责读字符串S中的字符，首先找到第一个非'-'字符，然后看res中是否已经连续写入了K个字符，如果是就在res后追加'-'；否则就对res继续追加字符;
2. 循环步骤1，直到遍历完成；
3. 将res反转，然后返回。
4. 注意判断```if(count == K){...}```的位置，它一定要放在```if(r < 0) break;```之后;

<div style="text-align: right"> 2019/05/09 19:41 </div>
