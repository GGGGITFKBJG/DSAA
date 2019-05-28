### 26. 删除排序数组中的重复项

> <div class="content__2ebE"><div><p>给定一个排序数组，你需要在<strong><a
> href="http://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95"
> target="_blank">原地</a></strong>删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。</p>
> 
> <p>不要使用额外的数组空间，你必须在<strong><a
> href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95"
> target="_blank">原地</a>修改输入数组</strong>并在使用 O(1) 额外空间的条件下完成。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre>给定数组 <em>nums</em> = <strong>[1,1,2]</strong>, 
> 
> 函数应该返回新的长度 <strong>2</strong>, 并且原数组 <em>nums </em>的前两个元素被修改为
> <strong>1</strong>, <strong>2</strong>。 
> 
> 你不需要考虑数组中超出新长度后面的元素。</pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre>给定<em> nums </em>= <strong>[0,0,1,1,1,2,2,3,3,4]</strong>,
> 
> 函数应该返回新的长度 <strong>5</strong>, 并且原数组 <em>nums </em>的前五个元素被修改为
> <strong>0</strong>, <strong>1</strong>,
> <strong>2</strong>, <strong>3</strong>,
> <strong>4</strong>。
> 
> 你不需要考虑数组中超出新长度后面的元素。 </pre>
> 
> <p><strong>说明:</strong></p>
> 
> <p>为什么返回数值是整数，但输出的答案是数组呢?</p>
> 
> <p>请注意，输入数组是以<strong>“引用”</strong>方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。</p>
> 
> <p>你可以想象内部操作如下:</p>
> 
>```cpp
>// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝 
>int len = removeDuplicates(nums);
> 
> // 在函数里修改输入数组对于调用者是可见的。 
> // 根据你的函数返回的长度,
> 它会打印出数组中该长度范围内的所有元素。 
> for (int i = 0; i < len; i++) {
>     print(nums[i]);
>}
> ```
> </div></div>
> 

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int a = 0, b = 1;
        while(true) {
            while(b < nums.size() && nums[b] == nums[a]) b++;
            if(b == nums.size()) break;
            nums[++a] = nums[b++];
        }
        return a + 1;
    }
};
```
总结：
1. 使用两个指针，a指向第一个出现的元素，b从a + 1处开始向后遍历；
2. 直到b遇到与a所指元素不相等的元素时，停下来；
3. 然后将a指针自增1位，并赋值为b所指元素的值；
4. 继续重步上述步骤，直到b到达数组尽头，返回a + 1。