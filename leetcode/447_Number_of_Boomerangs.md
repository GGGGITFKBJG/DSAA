### 447. 回旋镖的数量

> <div class="content__2ebE"><p>给定平面上<em>&nbsp;n </em>对不同的点，“回旋镖”
> 是由点表示的元组&nbsp;<code>(i, j,
> k)</code>&nbsp;，其中&nbsp;<code>i</code>&nbsp;和&nbsp;<code>j</code>&nbsp;之间的距离和&nbsp;<code>i</code>&nbsp;和&nbsp;<code>k</code>&nbsp;之间的距离相等（<strong>需要考虑元组的顺序</strong>）。</p>
> 
> <p>找到所有回旋镖的数量。你可以假设<em>&nbsp;n </em>最大为
> <strong>500</strong>，所有点的坐标在闭区间<strong> [-10000, 10000]
> </strong>中。</p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> [[0,0],[1,0],[2,0]]
> 
> <strong>输出:</strong> 2
> 
> <strong>解释:</strong> 两个回旋镖为 <strong>[[1,0],[0,0],[2,0]]</strong> 和
> <strong>[[1,0],[2,0],[0,0]]</strong> </pre> </div>

解法一
```cpp
//时间复杂度O(n^2), 空间复杂度O(n)
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++) {//选择第一个点
            unordered_map<int, int> um;//距离, 个数
            for(int j = 0; j < points.size(); j++) {//选择第二个点
                if(i == j) continue;//如果i和j指向同一点, 跳过
                int dist2 = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + 
                            (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);//计算距离
                ++um[dist2];//保存
            }
            for(auto p : um) {
                res += p.second * (p.second - 1);//累加数量
            }
        }
        return res;
    }
};
```

刚开始一看觉得挺吓人，仔细想想也没有很难，不要被它的表面吓到了。
我的思路是，
1. 遍历每一个点对（ab和ba算两对）；
2. 选定第一个点作为基点，计算其与其他所有点的距离dist2，及距离为dist2的点对的个数n，保存在map里。
3. 当前点所能形成的回旋镖的个数为n(n - 1)，（这个请画到纸上想一想），累加进res。
4. 选定第二个点作为基点，进行上述同样的操作，直到所有点都当过基点，这时返回res就是所有回旋镖的个数。

<div style="text-align: right">   2019/05/05 21:43 </div>
