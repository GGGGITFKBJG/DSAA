### 1109. 航班预订统计
> <div class="content__2ebE"><p>这里有&nbsp;<code>n</code>&nbsp;个航班，它们分别从 <code>1</code> 到 <code>n</code> 进行编号。</p>
> 
> <p>我们这儿有一份航班预订表，表中第&nbsp;<code>i</code>&nbsp;条预订记录&nbsp;<code>bookings[i] = [i, j, k]</code>&nbsp;意味着我们在从&nbsp;<code>i</code>&nbsp;到&nbsp;<code>j</code>&nbsp;的每个航班上预订了 <code>k</code> 个座位。</p>
> 
> <p>请你返回一个长度为 <code>n</code> 的数组&nbsp;<code>answer</code>，按航班编号顺序返回每个航班上预订的座位数。</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例：</strong></p>
> 
> <pre><strong>输入：</strong>bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
> <strong>输出：</strong>[10,55,45,25,25]
> </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>提示：</strong></p>
> 
> <ul>
> 	<li><code>1 &lt;= bookings.length &lt;= 20000</code></li>
> 	<li><code>1 &lt;= bookings[i][0] &lt;= bookings[i][1] &lt;= n &lt;= 20000</code></li>
> 	<li><code>1 &lt;= bookings[i][2] &lt;= 10000</code></li>
> </ul>
> </div>

解法一
```cpp
//时间复杂度O(n^3), 空间复杂度O(n)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        for(auto rec : bookings) {
            for(int i = rec[0]; i <= rec[1]; i++) {
                res[i - 1] += rec[2];
            }
        }
        return res;
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n + 1, 0);
        for(auto rec : bookings) {//记录每一站点上下车人数
            res[rec[0] - 1] += rec[2];
            res[rec[1]] -= rec[2];
        }
        for(int i = 1; i < n; i++) {//计算每一站内车上的人数
            res[i] += res[i - 1];
        }
        return vector<int>(res.begin(), res.end() - 1);
    }
};
```

这个题是上周末周赛的第二题，开始自然而然的思路是解法一，但是提交不通过（超时错误）。后来看了解答，解法二的想法很巧妙。

为了便于理解，可以把这个题目换一种表述：

一趟公交车一共有n个乘车区间（所以带上终点站共有n + 1个站点），现在给出一个记录列表records及区间数量n。其中records里面的每一条记录record记录了想要在两个区间内乘车的人数。现在要求出返回一个数组，计算出每一个站区间的实时乘车人数。

例如：
<pre>
输入: records = [[1,2,10],[2,3,20],[2,5,25]], n = 5

一共有5个乘车区间。这个records有三条记录，
[1,2,10]表示在第1个站区间到第2个站区间有10人要乘车；
[2,3,20]表示在第2个站区间到第3个站区间有20人要乘车；
[2,5,25]表示在第2个站区间到第5个站区间有25人要乘车。

输出：res = [10,55,45,25,25]

这个输出表示，从1到5的五个区间内，车上的实时的人数为10，55，45，25，25。

</pre>

解法二的思路就是，将上述的records记录转变为每一个站点总的上下车人数。所以

1. 先创建一个站点实时上下车人数数组res，它长为n + 1，初始化全为0，表示所有站点无人上车，无人下车；
```cpp
    vector<int> res(n + 1, 0);
```
2. 然后开始记录每个站点的上下车人数。回想题中的条件，对每条记录，record[0]代表上车站区间，record[1]代表下车前的最后一个区间，record[2]代表人数。所以这一步的做法是，遍历所有记录，将数组res中有上车的站点加上上车的人数，将数组中有下车的站点减去下车人数。
```cpp
    for(auto rec : bookings) {//记录每一站点上下车人数
        res[rec[0] - 1] += rec[2];//记录上车站点及上车人数
        res[rec[1]] -= rec[2];//记录下车站点及下车人数
    }
```
3. 之后遍历每一站，实时地对人数进行加减，就得到每一站的实时人数：
```cpp
    for(int i = 1; i < n; i++) {//计算每一站内车上的人数
        res[i] += res[i - 1];
    }
```
4. 返回res的前n项。

<div style="text-align: right">2019/07/07 00:11  </div>
