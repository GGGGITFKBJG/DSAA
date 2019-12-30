### 475. 供暖器
> <div class="content__2ebE"><div><p>冬季已经来临。&nbsp;你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。</p>
> 
> <p>现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。</p>
> 
> <p>所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。</p>
> 
> <p><strong>说明:</strong></p>
> 
> <ol>
> 	<li>给出的房屋和供暖器的数目是非负数且不会超过 25000。</li>
> 	<li>给出的房屋和供暖器的位置均是非负数且不会超过10^9。</li>
> 	<li>只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。</li>
> 	<li>所有供暖器都遵循你的半径标准，加热的半径也一样。</li>
> </ol>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [1,2,3],[2]
> <strong>输出:</strong> 1
> <strong>解释:</strong> 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
> </pre>
> 
> <p><strong>示例 2:</strong></p>
> 
> <pre><strong>输入:</strong> [1,2,3,4],[1,4]
> <strong>输出:</strong> 1
> <strong>解释:</strong> 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
> </pre>
> </div></div>

解法一
```cpp
//时间复杂度O(m*nlogn), 空间复杂度O(1)
class Solution {
public:
    int findClosest(vector<int>& heaters, int house) {//二分查找
        int low = 0, high = heaters.size() - 1, mid;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(heaters[mid] > house) high = mid - 1;
            else if(heaters[mid] < house) low = mid + 1;
            else return 0;
        }
        if(high < 0) return heaters[0] - house;
        else if(low >= heaters.size()) return house - heaters[heaters.size() - 1];
        else return min(abs(house - heaters[low]), abs(house - heaters[high]));
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int minRadius = INT_MIN;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        for(int i = 0; i < houses.size(); i++) {
            int need = findClosest(heaters, houses[i]);
            if(need > minRadius) minRadius = need;
        }
        return minRadius;
    }
};
```

思路：
1. 首先对房子和热源按升序排序；
2. 遍历需要供暖的房子，在热源中寻找（二分法）最近的那个，计算最小的需求距离need；
3. 找出最大的那个need，返回即可。

此题看题目都是连续的房子，数组也是有序的，一开始本人以为这是条件，试了几次发现题上没有明确说明这些条件，试了下果然是没有。


<div style="text-align: right"> 2019/05/09 14:44 </div>
