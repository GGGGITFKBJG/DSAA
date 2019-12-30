### 189. 旋转数组

> <div
> class="content__2ebE"><p>给定一个数组，将数组中的元素向右移动&nbsp;<em>k&nbsp;</em>个位置，其中&nbsp;<em>k&nbsp;</em>是非负数。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> <code>[1,2,3,4,5,6,7]</code> 和 <em>k</em> =
> 3 <strong>输出:</strong> <code>[5,6,7,1,2,3,4]</code>
> <strong>解释:</strong> 向右旋转 1 步: <code>[7,1,2,3,4,5,6]</code> 向右旋转 2 步:
> <code>[6,7,1,2,3,4,5] </code>向右旋转 3 步: <code>[5,6,7,1,2,3,4]</code>
> </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> <code>[-1,-100,3,99]</code> 和 <em>k</em> = 2
> <strong>输出:</strong> [3,99,-1,-100] <strong>解释:</strong>  向右旋转 1 步:
> [99,-1,-100,3] 向右旋转 2 步: [3,99,-1,-100]</pre>
> 
> <p><strong>说明:</strong></p>
> 
> <ul> 	<li>尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。</li>
> 	<li>要求使用空间复杂度为&nbsp;O(1) 的原地算法。</li> </ul> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 1 || k == 0) return;
        int temp1 = nums[0], temp2;
        int i = 0, flag = i;
        for(int j = 0; j < nums.size(); j++) {
            int next = (i + k) % nums.size();
            if(next == i) return;//是整数倍, 直接返回
            temp2 = nums[next];//保存要改变的位置的原始值
            nums[next] = temp1;//更改
            temp1 = temp2;//备份值递进
            i = next;//索引递进
            if(i == flag) {//循环回了起点
                i++;
                temp1 = nums[i];
                flag = i;
            }
        }
    }
};
```

解法二
```cpp
//反转数组
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    void reverse(vector<int>& nums, int i, int j) {
        while(i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {//反转前n-k个字符, 和后k个字符, 再整体反转
        if(nums.size() < 2 || k == 0) return;
        int n = nums.size();
        reverse(nums, 0, n - k % n - 1);
        reverse(nums, n - k % n, n - 1);
        reverse(nums, 0, n - 1);
    }
};
```

解法一，用了两个变量做缓存，temp1备份上一个值，temp2备份当前要改变的值。设置flag是为了防止死循环，文字说不清，直接看代码吧。
解法二，这个比上个更好理解，也很容易实现。思路是先对n - k（如果k > nums.size()，就先取余）个字符原地反转，再对着后k个字符原地反转，最后对整个字符串反转，就是正确结果。

<div style="text-align: right"> 2019/04/27 01:35  </div>