### 575. 分糖果

> <div class="content__2ebE"><p>给定一个<strong>偶数</strong>长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。你需要把这些糖果<strong>平均</strong>分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> candies = [1,1,2,2,3,3]
> <strong>输出:</strong> 3
> <strong>解析: </strong>一共有三种种类的糖果，每一种都有两个。
>      最优分配方案：妹妹获得[1,2,3],弟弟也获得[1,2,3]。这样使妹妹获得糖果的种类数最多。
> </pre>
> 
> <p><strong>示例 2 :</strong></p>
> 
> <pre><strong>输入:</strong> candies = [1,1,2,3]
> <strong>输出:</strong> 2
> <strong>解析:</strong> 妹妹获得糖果[2,3],弟弟获得糖果[1,1]，妹妹有两种不同的糖果，弟弟只有一种。这样使得妹妹可以获得的糖果种类数最多。
> </pre>
> 
> <p><strong>注意:</strong></p>
> 
> <ol>
> 	<li>数组的长度为[2, 10,000]，并且确定为偶数。</li>
> 	<li>数组中数字的大小在范围[-100,000, 100,000]内。
> 	<ol>
> 	</ol>
> 	</li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(n)
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int count = candies.size() / 2;
        int i = 0, res = 0;
        unordered_set<int> us;
        while(count--) {
            if(!us.count(candies[i])) {//遇到新元素
                res++;//结果+1
                us.insert(candies[i]);//记录
            }
            else count++;//遇到重复元素直接跳过且不计数
            while(++i < (int)candies.size() && candies[i] == candies[i - 1]);//下一个不重复元素
            if(i == candies.size()) break;//到达末尾
        }
        return res;
    }
};
```

思路：

1. 妹妹能得到的种类数最多是糖果数的一半，用count表示总数的一半；
2. 设置指针 i ，用i访问数组count次；i 每次向右移动到下一个不重复元素的位置；使用哈希表us记录出现过的元素；res记录可获得的种类数目；
3. 遍历过程中，先检查 i 指向的元素是否出现过：①如果出现过，就将count自增1（抵消掉count--，表示此次不占用count的计数），然后i向后移动；②如果是没出现过的元素，就将res计数加1，并将当前元素加入到哈希表us里，然后i向后移动。
4. 指针 i 遇到结尾，或者count计数到达0，返回res结束程序。

<div style="text-align: right"> 2019/06/03 11:48 </div>