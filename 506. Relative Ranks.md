### 506. 相对名次
> <div class="content__2ebE"><div><p>给出&nbsp;<strong>N</strong> 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。</p>
> 
> <p>(注：分数越高的选手，排名越靠前。)</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [5, 4, 3, 2, 1]
> <strong>输出:</strong> ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
> <strong>解释:</strong> 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
> 余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。</pre>
> 
> <p><strong>提示:</strong></p>
> 
> <ol>
> 	<li>N 是一个正整数并且不会超过&nbsp;10000。</li>
> 	<li>所有运动员的成绩都不相同。</li>
> </ol>
> </div></div>

解法一
```cpp
//时间复杂度O(nlogn), 空间复杂度O(n)
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> temp(nums);
        sort(temp.rbegin(), temp.rend());
        unordered_map<int, string> um;
        if(temp.size() > 0) um[temp[0]] = "Gold Medal";
        if(temp.size() > 1) um[temp[1]] = "Silver Medal";
        if(temp.size() > 2) um[temp[2]] = "Bronze Medal";
        for(int i = 4; i <= temp.size(); i++) {
            um[temp[i - 1]] = to_string(i);
        }
        vector<string> res;
        for(int num : nums) {
            res.push_back(um[num]);
        }
        return res;
    }
};
```


先对原数组由大到小排序，再使用一个哈希表记录运动员的成绩-名次，最后构建一个res，遍历原数组，从哈希表取出其名次，返回。

<div style="text-align: right"> 2019/05/25 22:13 </div>