### 118. 杨辉三角

> <div
> class="content__2ebE"><p>给定一个非负整数&nbsp;<em>numRows，</em>生成杨辉三角的前&nbsp;<em>numRows&nbsp;</em>行。</p>
> 
> <p><img
> src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif"
> alt=""></p>
> 
> <p><small>在杨辉三角中，每个数是它左上方和右上方的数的和。</small></p>
> 
> <p><strong>示例:</strong></p>
> 
> <pre><strong>输入:</strong> 5 <strong>输出:</strong> 
> [
>           [1],
>          [1,1],
>         [1,2,1],
>        [1,3,3,1],
>       [1,4,6,4,1] 
> ]</pre> </div>

解法一
```cpp
//时间复杂度O(n^2), 空间复杂度O(n^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for(int i = 0; i < numRows; i++) {
            res[i].resize(i + 1);
            res[i][0] = 1;
            for(int j = 1; j < i; j++) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
            res[i][i] = 1;
        }
        return res;
    }
};
```

此题不难，经典题目。按照题上的意思实现出来即可。

   <div style="text-align: right">   2019/04/23 14:51 </div>