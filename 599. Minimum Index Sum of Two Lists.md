### 599. 两个列表的最小索引总和

> <div class="content__2ebE"><p>假设Andy和Doris想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。</p>
> 
> <p>你需要帮助他们用<strong>最少的索引和</strong>找出他们<strong>共同喜爱的餐厅</strong>。 如果答案不止一个，则输出所有答案并且不考虑顺序。 你可以假设总是存在一个答案。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong>
> ["Shogun", "Tapioca Express", "Burger King", "KFC"]
> ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
> <strong>输出:</strong> ["Shogun"]
> <strong>解释:</strong> 他们唯一共同喜爱的餐厅是“Shogun”。
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong>
> ["Shogun", "Tapioca Express", "Burger King", "KFC"]
> ["KFC", "Shogun", "Burger King"]
> <strong>输出:</strong> ["Shogun"]
> <strong>解释:</strong> 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
> </pre>
> 
> <p><strong>提示:</strong></p>
> 
> <ol>
> 	<li>两个列表的长度范围都在&nbsp;[1, 1000]内。</li>
> 	<li>两个列表中的字符串的长度将在[1，30]的范围内。</li>
> 	<li>下标从0开始，到列表的长度减1。</li>
> 	<li>两个列表都没有重复的元素。</li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(n^2), 空间复杂度O(1)
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int sum = 0, len1 = list1.size(), len2 = list2.size();
        vector<string> res;
        while(sum <= len1 + len2 - 2) {
            for(int i = sum, j = 0; i >= j; i--, j++) {//在索引和为sum的字符对中寻找
                if(i < len1 && j < len2 && list1[i] == list2[j]) res.push_back(list1[i]);
                if(i != j && j < len1 && i < len2 && list1[j] == list2[i]) res.push_back(list1[j]);
            }
            if(res.size() > 0) return res;
            sum++;
        }
        return {};
    }
};
```

思路：

按照索引和从大到小遍历。每个循环内，对索引和为sum的所有字符对进行比较，直到比完所有和为sum的字符对，检查结果数组res是否非空，若是，则返回；否则继续查找和为sum + 1的字符对。

<div style="text-align: right"> 2019/06/09 01:33 </div>