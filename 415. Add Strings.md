### 415. 字符串相加

> <div class="content__2ebE"><p>给定两个字符串形式的非负整数&nbsp;<code>num1</code>
> 和<code>num2</code>&nbsp;，计算它们的和。</p>
> 
> <p><strong>注意：</strong></p>
> 
> <ol> 	<li><code>num1</code> 和<code>num2</code>&nbsp;的长度都小于 5100.</li>
> 	<li><code>num1</code> 和<code>num2</code>
> 都只包含数字&nbsp;<code>0-9</code>.</li> 	<li><code>num1</code>
> 和<code>num2</code> 都不包含任何前导零。</li> 	<li><strong>你不能使用任何內建 BigInteger
> 库，&nbsp;也不能直接将输入的字符串转换为整数形式。</strong></li> </ol> </div>

解法一
```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int carry = 0;
        for(int i = 1; i <= num1.size() || i <= num2.size(); i++) {
            int sum = carry;
            if(i <= num1.size()) sum += num1[num1.size() - i] - '0';
            if(i <= num2.size()) sum += num2[num2.size() - i] - '0';
            res += (char)(sum % 10 + '0');//res = (char)(sum % 10 + '0') + res;
            carry = sum / 10;
        }
        if(carry > 0) res += '1';
        return string(res.rbegin(), res.rend());
    }
};
```

和链表数字相加类似，设置两个指针，从后往前同时遍历，res记下进位，carry记录余数。最后别忘了检查最高位的进位是否为0。
第10行对于res字符串的构建，此解法选择了先对res顺序追加，最后再进行反转。个人感觉要比头插运行速度快（因为对于线性结构，反转需要线性时间，头插需要二次的时间；另外，头插的这种写法可能会产生临时的string对象，空间需求也可能会有增加）。
<pre>
res += (char)(sum % 10 + '0');//快
res = (char)(sum % 10 + '0') + res;//慢
</pre>

实测效果（速度慢的是头插方式）：

<div class="submissions__1CMU"><div><div class="ant-table-wrapper table__1_IV css-nlnqsv-override"><div class="ant-spin-nested-loading"><div class="ant-spin-container"><div class="ant-table ant-table-default ant-table-scroll-position-left"><div class="ant-table-content"><div class="ant-table-body"><table class=""><colgroup><col><col><col><col><col></colgroup><thead class="ant-table-thead"><tr><th class="time-column__yRxK"><span>提交时间</span></th><th class="status-column__2fhn"><span>提交结果</span></th><th class="runtime-column__3F_8"><span>执行用时</span></th><th class="memory-column__3--q"><span>内存消耗</span></th><th class="lang-column__1J97"><span>语言</span></th></tr></thead><tbody class="ant-table-tbody"><tr class="custom-tr__3Ryf" data-row-key="18134910"><td class="custom-td__1SeH"><span class="ant-table-row-indent indent-level-0" style="padding-left: 0px;"></span>2 个月前</td><td class="custom-td__1SeH"><a class="ac__g_mU">通过</a></td><td class="custom-td__1SeH">12 ms</td><td class="custom-td__1SeH">9.1 MB</td><td class="custom-td__1SeH">Cpp</td></tr><tr class="custom-tr__3Ryf" data-row-key="18134665"><td class="custom-td__1SeH"><span class="ant-table-row-indent indent-level-0" style="padding-left: 0px;"></span>2 个月前</td><td class="custom-td__1SeH"><a class="ac__g_mU">通过</a></td><td class="custom-td__1SeH">60 ms</td><td class="custom-td__1SeH">57.9 MB</td><td class="custom-td__1SeH">Cpp</td></tr><tr class="custom-tr__3Ryf" data-row-key="18134583"><td class="custom-td__1SeH"><span class="ant-table-row-indent indent-level-0" style="padding-left: 0px;"></span>2 个月前</td><td class="custom-td__1SeH"><a class="ac__g_mU">通过</a></td><td class="custom-td__1SeH">60 ms</td><td class="custom-td__1SeH">58 MB</td><td class="custom-td__1SeH">Cpp</td></tr></tbody></table></div></div></div></div></div></div></div></div>
<div style="text-align: right">  2019/05/04 13:33   </div>