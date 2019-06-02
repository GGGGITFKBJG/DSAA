### 119. 杨辉三角 II

> <div class="content__2ebE"><p>给定一个非负索引&nbsp;<em>k</em>，其中
> <em>k</em>&nbsp;≤&nbsp;33，返回杨辉三角的第 <em>k </em>行。</p>
> 
> <p><img
> src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif"
> alt=""></p>
> 
> <p><small>在杨辉三角中，每个数是它左上方和右上方的数的和。</small></p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> 3 <strong>输出:</strong> [1,3,3,1] </pre>
> 
> <p><strong>进阶：</strong></p>
> 
> <p>你可以优化你的算法到 <em>O</em>(<em>k</em>) 空间复杂度吗？</p> </div>

解法一
```cpp
//时间复杂度O(2^n), 空间复杂度O(n)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};//若要求第1层直接返回
        vector<int> res(rowIndex + 1);//至少是第2层
        res[0] = 1;
        res[1] = 1;//第二层存入res
        for(int i = 2; i < rowIndex + 1; i++) {//从第i = 2层开始操作
            //res[0] = 1;
            for(int j = i - 1; j > 0; j--) {
                res[j] += res[j - 1];
            }
            res[i] = 1;//第i + 1层完成
        }
        return res;
    }
};
```

本题要求空间复杂度O(n)，因此只用一个数组作为缓存。
1. 若要求输出第1层（索引0），直接返回 {1}。这样保证了后面的要求至少是第2层（索引为1）；
2. 对res前两个元素初始化为1，代表第二层的两个元素；
3. 对res进行操作，从后往前遍历每一个元素（除了第1个），当前元素值 = 当前元素 + 前一元素值；
4. 遍历结束后，在数组尾追加元素1，此时完成了对第二层元素的操作，得到第三层元素；
5. 对第三层元素同样操作，以此类推，对第n - 1层元素操作后得到第n层元素，完成求解。

<div style="text-align: right"> 2019/04/23 20:30 </div>