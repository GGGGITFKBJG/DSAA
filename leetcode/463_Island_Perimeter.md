### 463. 岛屿的周长
> <html>
> <div><p>给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地&nbsp;0 表示水域。</p>
> 
> <p>网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。</p>
> 
> <p>岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。</p>
> 
> <p>&nbsp;</p>
> 
> <p><strong>示例 :</strong></p>
> 
> <pre><strong>输入:</strong>
> [[0,1,0,0],
>  [1,1,1,0],
>  [0,1,0,0],
>  [1,1,0,0]]
> 
> <strong>输出:</strong> 16
> 
> <strong>解释:</strong> 它的周长是下面图片中的 16 个黄色的边：
> 
> <img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/island.png">
> </pre>
> </div><html>

解法一
```cpp
class Solution {
public:
    void getPerimeter(int i, int j, vector<vector<int>>& grid, int& len) {
        int m = grid.size(), n = grid[0].size();
		grid[i][j] = -1;//-1标记访问过的点
        if(i - 1 >= 0 && grid[i - 1][j] == 1) {//上面是未访问过的陆地
            getPerimeter(i - 1, j, grid, len);
        }
        else if(i - 1 < 0 || grid[i - 1][j] == 0) len++;//上面是海
		
        if(i + 1 < m && grid[i + 1][j] == 1) {//下
			getPerimeter(i + 1, j, grid, len);
		}
        else if(i + 1 >= m || grid[i + 1][j] == 0) len++;
		
        if(j - 1 >= 0 && grid[i][j - 1] == 1) {//左
			getPerimeter(i, j - 1, grid, len);
		}
        else if(j - 1 < 0 || grid[i][j - 1] == 0) len++;
		
		if(j + 1 < n && grid[i][j + 1] == 1) {//右
			getPerimeter(i, j + 1, grid, len);
		}
        else if(j + 1 >= n || grid[i][j + 1] == 0) len++;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int i = 0, j;
        int m = grid.size(), n = grid[0].size();
        for(bool landFound = false; i < m; i++) {
            j = 0;
            for(; j < n; j++) {
                if(grid[i][j] == 1) {
                    landFound = true;
                    break;
                }
            }
			if(landFound) break;
        }
        if(i == m && j == n) return 0;
        
		int res = 0;
        getPerimeter(i, j, grid, res);
		return res;
    }
};
```

深度优先搜索。
1. 首先遍历二维数组grid，找到第一块陆地（值为1的元素），其位置为（i, j）；
2. 以（i, j）为起点开始深度优先搜索，首先将（i, j）位置上元素值由1改为-1，代表访问过该位置；
3. 判断位置（i, j）上方是否为未访问过的陆地（未超边界且值为1），若是则访问上方位置；或者是否为海（分两种：①超出了grid边界 ②元素值为0），若是则使计数变量自增1；为-1说明访问过，不予处理；
4. 以步骤3的方式处理下、左、右的元素，直到结束，返回计数变量。

<div style="text-align: right">2019/05/08 22:50 </div>