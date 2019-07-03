### 350. 两个数组的交集 II

> <div class="content__2ebE"><p>给定两个数组，编写一个函数来计算它们的交集。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入: </strong>nums1 = [1,2,2,1], nums2 = [2,2] <strong>
> 输出: </strong>[2,2] </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入: </strong>nums1 = [4,9,5], nums2 = [9,4,9,8,4]
> <strong>输出: </strong>[4,9]</pre>
> 
> <p><strong>说明：</strong></p>
> 
> <ul> 	<li>输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。</li>
> 	<li>我们可以不考虑输出结果的顺序。</li> </ul>
> 
> <p><strong><strong>进阶:</strong></strong></p>
> 
> <ul> 	<li>如果给定的数组已经排好序呢？你将如何优化你的算法？</li>
> 	<li>如果&nbsp;<em>nums1&nbsp;</em>的大小比&nbsp;<em>nums2&nbsp;</em>小很多，哪种方法更优？</li>
> 	<li>如果&nbsp;<em>nums2&nbsp;</em>的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？</li>
> </ul> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        vector<int> res;
        for(int num : nums1) {
            if(um.count(num)) um[num] += 1;
            else um[num] = 1;
        }
        for(int num : nums2) {
            if(um.count(num)) {
                res.push_back(num);
                um[num] -= 1;
                if(um[num] == 0) um.erase(num);
            }
        }
        return res;
    }
};
```

与349题类似，使用一个额外的哈希表。
1. 遍历num1将所有元素及其个数存入；
2. 再遍历num2，若遇到在数组1中出现过的元素，存入res，再对其哈希表中的计数减1，减至0时将其删除。
3. 遍历结束后，返回res。

进阶问题：
1. 若数组已排序，可以用两个指针分别遍历两个数组，根据两数组元素的大小移动指针，向后遍历，相同则存入res。线性时间和常量空间需求。
2. 若nums1小很多，先对nums1排序。再遍历数组nums2，对每一个元素，用二分法查找nums1中相同的元素，数组2很小的话，接近线性时间。
3. 太大了就分块，一次遍历是不可避免的。

<div style="text-align: right">  2019/05/01 00:33    </div>