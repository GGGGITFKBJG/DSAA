### 303. 区域和检索 - 数组不可变

> <div class="content__2ebE"><p>给定一个整数数组
> &nbsp;<em>nums</em>，求出数组从索引&nbsp;<em>i&nbsp;</em>到&nbsp;<em>j&nbsp;&nbsp;</em>(<em>i</em>&nbsp;≤&nbsp;<em>j</em>)
> 范围内元素的总和，包含&nbsp;<em>i,&nbsp; j&nbsp;</em>两点。</p>
> 
> <p><strong>示例：</strong></p>
> 
> <pre>给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
> 
> sumRange(0, 2) -&gt; 1 
> sumRange(2, 5) -&gt; -1 
> sumRange(0, 5) -&gt; -3</pre>
> 
> <p><strong>说明:</strong></p>
> 
> <ol> 	<li>你可以假设数组不可变。</li>
> 	<li>会多次调用&nbsp;<em>sumRange</em>&nbsp;方法。</li> </ol> </div>
解法一
```cpp
class NumArray {
public:
    NumArray(vector<int>& nums) : sum(nums.size() + 1, 0) {//和数组比原数组长度多1
        if(nums.size() > 0) sum[1] = nums[0];//和数组索引i(从0开始))代表原数组前i项(从1开始)和
        for(int i = 2; i < sum.size(); i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```

常规思路每次需要O(n)的时间，题上有个条件是数组内容不会改变，那么在初始化阶段，我们就可以把累积和计算并保存，要求输出的时候直接求两指针所指元素之差即可，只需要常数时间。为了避免边界问题，对累积和数组最左端加入额外的一个位置。

<div style="text-align: right"> 2019/04/30 22:48  </div>