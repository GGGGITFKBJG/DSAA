### 661. 图片平滑器

> <div class="content__2ebE"><p>包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度&nbsp;(向下舍入) ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong>
> [[1,1,1],
>  [1,0,1],
>  [1,1,1]]
> <strong>输出:</strong>
> [[0, 0, 0],
>  [0, 0, 0],
>  [0, 0, 0]]
> <strong>解释:</strong>
> 对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
> 对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
> 对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
> </pre>
> 
> <p><strong>注意:</strong></p>
> 
> <ol>
> 	<li>给定矩阵中的整数范围为 [0, 255]。</li>
> 	<li>矩阵的长和宽的范围均为&nbsp;[1, 150]。</li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(m*n), 空间复杂度O(m*n)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int count = 1, sum = M[i][j];
                if(i > 0) {
                    sum += M[i - 1][j];
                    count++;
                }
                if(i < m - 1) {
                    sum += M[i + 1][j];
                    count++;
                }
                if(j > 0) {
                    sum += M[i][j - 1];
                    count++;
                }
                if(j < n - 1) {
                    sum += M[i][j + 1];
                    count++;
                }
                if(i > 0 && j > 0) {
                    sum += M[i - 1][j - 1];
                    count++;
                }
                if(i > 0 && j < n - 1) {
                    sum += M[i - 1][j + 1];
                    count++;
                }
                if(i < m - 1 && j > 0) {
                    sum += M[i + 1][j - 1];
                    count++;
                }
                if(i < m - 1 && j < n - 1) {
                    sum += M[i + 1][j + 1];
                    count++;
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};
```

```cpp
//时间复杂度O(m*n), 空间复杂度O(m*n)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int count = 0, sum = 0;
                int x1 = i > 0 ? i - 1 : i;
                int y1 = j > 0 ? j - 1 : j;
                int x2 = i < m - 1 ? i + 1 : i;
                int y2 = j < n - 1 ? j + 1 : j;
                for(int x = x1; x <= x2; x++) {
                    for(int y = y1; y <= y2; y++) {
                        sum += M[x][y];
                        count++;
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};
```

常规思路，创建一个新矩阵用来存放结果，遍历旧矩阵，分别求平均放入新矩阵中。要处理边界情况。

解法一

按思路走，分别测试周围8个是否有效并求和，再求平均存入res。

解法二

上一个解法有一些重复的计算，因为它总是对同一条件测试了两次，解法二改进了这一点。它使用了两对坐标，记录当前元素周围有效元素的范围，并对这个范围内 的元素计数并求和，以此更新res。

实测证明解法一要364ms，解法二需要204ms，快了许多。

<div style="text-align: right"> 2019/06/15 11:01 </div>