### 66. 加一

> <div
> class="content__2ebE"><div><p>给定一个由<strong>整数</strong>组成的<strong>非空</strong>数组所表示的非负整数，在该数的基础上加一。</p>
> 
> <p>最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。</p>
> 
> <p>你可以假设除了整数 0 之外，这个整数不会以零开头。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> [1,2,3] <strong>输出:</strong> [1,2,4]
> <strong>解释:</strong> 输入数组表示数字 123。 </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> [4,3,2,1] <strong>输出:</strong> [4,3,2,2]
> <strong>解释:</strong> 输入数组表示数字 4321。 </pre> </div></div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag = true;
        for(int i = digits.size() - 1; i >= 0; i--) {//O(n)
            if(flag == false) return digits;//没有进位就不用进行下去了
            if(digits[i] == 9) {
                digits[i] = 0;
                flag = true;
            }
            else {
                digits[i] += 1;
                flag = false;
            }
        }
        if(flag == true) digits.insert(digits.begin(), 1);//O(n)
        return digits;
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;//代表进位
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(carry == 0) return digits;
            carry = (digits[i] + 1) / 10;//这两行省去了判断
            digits[i] = (digits[i] + 1) % 10;
        }
        if(carry == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

解法一、解法二思路一样，后者优化了一下进位逻辑，代码看起来更清晰。