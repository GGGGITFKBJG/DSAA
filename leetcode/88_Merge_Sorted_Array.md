### 88. 合并两个有序数组

> <div class="content__2ebE"><div><p>给定两个有序整数数组&nbsp;<em>nums1 </em>和
> <em>nums2</em>，将 <em>nums2
> </em>合并到&nbsp;<em>nums1&nbsp;</em>中<em>，</em>使得&nbsp;<em>num1
> </em>成为一个有序数组。</p>
> 
> <p><strong>说明:</strong></p>
> 
> <ul> 	<li>初始化&nbsp;<em>nums1</em> 和 <em>nums2</em>
> 的元素数量分别为&nbsp;<em>m</em> 和 <em>n</em>。</li>
> 	<li>你可以假设&nbsp;<em>nums1&nbsp;</em>有足够的空间（空间大小大于或等于&nbsp;<em>m +
> n</em>）来保存 <em>nums2</em> 中的元素。</li> </ul>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> nums1 = [1,2,3,0,0,0], m = 3 nums2 =
> [2,5,6],       n = 3
> 
> <strong>输出:</strong>&nbsp;[1,2,2,3,5,6]</pre> </div></div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m + n);
        int i = 0, j = 0, k = 0;
        while(i < m && j < n) {
            temp[k++] = nums1[i] <= nums2[j] ? nums1[i++] : nums2[j++];
        }
        int l;
        if(i == m) {
            for(int t = 1; t <= n - j; t++) {
                nums1[m + n - t] = nums2[n - t];
            }
            l = m + j;
        }
        else if(j == n) {
            for(int t = 1; t <= m - i; t++) {
                nums1[m + n - t] = nums1[m - t];
            }
            l = n + i;
        }
        for(int t = 0; t < l; t++) {
            nums1[t] = temp[t];
        }
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 && j >= 0) {
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        if(i == -1) {
            for(int t = 0; t <= j; t++) {
                nums1[t] = nums2[t];
            }
        }
    }
};
```

解法一，设置了一个额外的临时数组temp，两个指针：i指向nums1，j指向nums2，从头开始遍历两个数组。比较i和j两指针所指元素，取较小者放入临时数组中，并更新指针位置。直至两指针其一达到末尾，把有剩余的数组元素复制到nums1的末尾，再把临时数组temp中已放入的元素复制到nums1的前面，完成。
解法二，后来看了别人的解法，发现其实可以不用临时数组，只需要从后往前遍历即可，而且此解法代码简洁。