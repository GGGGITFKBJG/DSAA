### 434. 字符串中的单词数
> <div class="content__2ebE"><p>给定一个 N 叉树，返回其节点值的<em>层序遍历</em>。
> (即从左到右，逐层遍历)。</p>
> 
> <p>例如，给定一个&nbsp;<code>3叉树</code>&nbsp;:</p>
> 
> <p>&nbsp;</p>
> 
> <p><img style="width: 100%; max-width: 300px;"
> src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/narytreeexample.png"></p>
> 
> <p>&nbsp;</p>
> 
> <p>返回其层序遍历:</p>
> 
> <pre>[
>      [1],
>      [3,2,4],
>      [5,6] 
> ] </pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>说明:</strong></p>
> 
> <ol> 	<li>树的深度不会超过&nbsp;<code>1000</code>。</li>
> 	<li>树的节点总数不会超过&nbsp;<code>5000</code>。</li> </ol></div>

解法一
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        istringstream iss(s);
        while(!iss.eof()) {
            string temp;
            iss >> temp;
            if(!temp.empty()) count++;
        }
        return count;
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int countSegments(string s) {
        int i = 0, count = 0;
        while(i < s.length()) {
            while(i < s.length() && s[i] == ' ') i++;
            if(i < s.length()) count++;
            while(i < s.length() && s[i] != ' ') i++;
        }
        return count;
    }
};
```

解法一偷了个懒，使用了字符串流，利用了字符串流以空格为分割符的特点。计数前之所以要判断temp是否为空，是因为如果剩余字符都是空格，这时iss.eof()仍是true，不判断的话会使计数多1。弊端就是不灵活，如果分割符换成其他字符，就不能用这种方法了。
解法二是比较常规的做法，对空格和非空格循环遍历，每交替一次计数加1。优点是速度快，而且不依赖输入输出流。

<div style="text-align: right">2019/05/04 18:38  </div>