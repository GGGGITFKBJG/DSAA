### 744. 寻找比目标字母大的最小字母

> <div class="content__2ebE"><p>给定一个只包含小写字母的有序数组<code>letters</code>&nbsp;和一个目标字母&nbsp;<code>target</code>，寻找有序数组里面比目标字母大的最小字母。</p>
> 
> <p>数组里字母的顺序是循环的。举个例子，如果目标字母<code>target = 'z'</code> 并且有序数组为&nbsp;<code>letters = ['a', 'b']</code>，则答案返回&nbsp;<code>'a'</code>。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong>
> letters = ["c", "f", "j"]
> target = "a"
> <strong>输出:</strong> "c"
> 
> <strong>输入:</strong>
> letters = ["c", "f", "j"]
> target = "c"
> <strong>输出:</strong> "f"
> 
> <strong>输入:</strong>
> letters = ["c", "f", "j"]
> target = "d"
> <strong>输出:</strong> "f"
> 
> <strong>输入:</strong>
> letters = ["c", "f", "j"]
> target = "g"
> <strong>输出:</strong> "j"
> 
> <strong>输入:</strong>
> letters = ["c", "f", "j"]
> target = "j"
> <strong>输出:</strong> "c"
> 
> <strong>输入:</strong>
> letters = ["c", "f", "j"]
> target = "k"
> <strong>输出:</strong> "c"
> </pre>
> 
> <p><strong>注:</strong></p>
> 
> <ol>
> 	<li><code>letters</code>长度范围在<code>[2, 10000]</code>区间内。</li>
> 	<li><code>letters</code> 仅由小写字母组成，最少包含两个不同的字母。</li>
> 	<li>目标字母<code>target</code> 是一个小写字母。</li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(logn), 空间复杂度O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0, high = letters.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(letters[mid] > target) high = mid - 1;
            else if(letters[mid] < target) low = mid + 1;
            else {
                if(mid == letters.size() - 1 || letters[mid + 1] > target) {
                    low = high = mid;
                    break;
                }
                low = mid + 1;
                high = letters.size() - 1;
            }
        }
        if(high == -1 || low == letters.size()) return letters[0];
        if(low == high) return letters[(low + 1) % letters.size()];
        return letters[low];
    }
};
```

解法二
```cpp
//时间复杂度O(logn, 空间复杂度O(1)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0, high = letters.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(letters[mid] <= target) low = mid + 1;
            else if(letters[mid] > target) high = mid - 1;
        }
        return letters[low % letters.size()];
    }
};
```

二分查找。与普通的二分查找不太一样的地方是，要处理数组中有重复元素的情况，此时应该找到重复元素的最右边的那个元素。

解法二更简洁一些。

<div style="text-align: right"> 2019/06/27 13:54 </div>