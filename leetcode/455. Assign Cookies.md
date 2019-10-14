### 455. 分发饼干

> <div
> class="content__2ebE"><p>假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。对每个孩子
> i ，都有一个胃口值&nbsp;g<sub>i ，</sub>这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j ，都有一个尺寸
> s<sub>j&nbsp;</sub>。如果 s<sub>j</sub> &gt;=
> g<sub>i&nbsp;</sub>，我们可以将这个饼干 j 分配给孩子 i
> ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。</p>
> 
> <p><strong>注意：</strong></p>
> 
> <p>你可以假设胃口值为正。<br> 一个小朋友最多只能拥有一块饼干。</p>
> 
> <p><strong>示例&nbsp;1:</strong></p>
> 
> <pre><strong>输入:</strong> [1,2,3], [1,1]
> 
> <strong>输出:</strong> 1
> 
> <strong>解释:</strong>  你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
> 虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。 所以你应该输出1。 </pre>
> 
> <p><strong>示例&nbsp;2:</strong></p>
> 
> <pre><strong>输入:</strong> [1,2], [1,2,3]
> 
> <strong>输出:</strong> 2
> 
> <strong>解释:</strong>  你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
> 你拥有的饼干数量和尺寸都足以让所有孩子满足。 所以你应该输出2. </pre> </div>

解法一
```cpp
//时间复杂度O(nlogn), 空间复杂度O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0, j = 0, res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(i < g.size() && j < s.size()) {
            if(g[i] <= s[j]) {
                res++;
                i++;
                j++;
            }
            else j++;
        }
        return res;
    }
};
```

双指针法。先对两个数组排序，再使用两个指针 i 和 j 分别遍历数组g（胃口）和s（饼干）；
以上思路说得形象一点就是，如果可以满足当前小孩的胃口（g[i] <= s[j]），就分配给他饼干（res++），否则挑下一个更大的饼干给他（j++）。
满足不了任何小孩的小饼干，那就扔掉吧。
很棒的家长。

<div style="text-align: right">  2019/05/07 23:08    </div>
      