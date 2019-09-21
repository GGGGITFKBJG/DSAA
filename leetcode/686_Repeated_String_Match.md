### 686. 重复叠加字符串匹配

> <div class="content__2ebE"><p>给定两个字符串 A 和 B, 寻找重复叠加字符串A的最小次数，使得字符串B成为叠加后的字符串A的子串，如果不存在则返回 -1。</p>
> 
> <p>举个例子，A = "abcd"，B = "cdabcdab"。</p>
> 
> <p>答案为 3，&nbsp;因为 A 重复叠加三遍后为&nbsp;“abcdabcdabcd”，此时 B 是其子串；A 重复叠加两遍后为"abcdabcd"，B 并不是其子串。</p>
> 
> <p><strong>注意:</strong></p>
> 
> <p>&nbsp;<code>A</code>&nbsp;与&nbsp;<code>B</code>&nbsp;字符串的长度在1和10000区间范围内。</p>
> </div>

解法一
```cpp
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int res = 1, j;
        string Ab = A;
        while(Ab.size() < B.size()) Ab += A, res++;
        int imax = Ab.size() - B.size();
        for(int i = 0; i < Ab.size() - B.size() + 1; i++) {
            for(j = 0; j < B.size(); j++) {
                if(Ab[i + j] != B[j]) break;
            }
            if(j == B.size()) return res;
            if(i == imax) Ab += A, res++;
        }
        return -1;
    }
};
```

解法二
```cpp
class Solution {
public:
    bool kmp(const string& str, const string& pattern) {
        int n = str.size(), m = pattern.size();
        if (m == 0) return false;//保证pattern非空
        vector<int> next(m);
        next[0] = -1;//第一个元素不匹配时，j指针下一个位置始终为索引0

        for (int i = 1; i < m; i++) {//构建next数组
            int j = next[i - 1];
            while (pattern[j + 1] != pattern[i] && j >= 0) j = next[j];//一直左移，直到找到匹配的位置
            if (pattern[j + 1] == pattern[i]) next[i] = j + 1;//找到了
            else next[i] = -1;//j=-1，表示没找到，就从头开始
        }

        int i = 0, j = 0;//开始搜索
        while (i < n) {
            if (str[i] == pattern[j]) {
                i++, j++;
                if (j == m) {
                    return true;
                    j = next[j - 1] + 1;
                }
            }
            else if (j == 0) i++;
            else j = next[j - 1] + 1;
        }
        return false;
    }
    
    int repeatedStringMatch(string A, string B) {
        int n1 = A.size(), n2 = B.size();
        int res = n2 / n1 + (n2 % n1 != 0);
        string Ab = "";
        for(int i = 0; i < res; i++) Ab += A;
        if(kmp(Ab, B)) return res;
        return kmp(Ab + A, B) ? res + 1 : -1;
    }
};
```

解法三
```cpp
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int n1 = A.size(), n2 = B.size();
        int res = n2 / n1 + (n2 % n1 != 0);
        string Ab = "";
        for(int i = 0; i < res; i++) Ab += A;
        if(Ab.find(B) != std::string::npos) return res;
        return string(Ab + A).find(B) != std::string::npos ? res + 1 : -1;
    }
};
```
思路：
1. 由A重复res次得到字符串Ab。首先要确定A串重复的最少次数res，这里它应该等于使Ab.size() >= B.size()的最小整数。
2. 在Ab中寻找子串B，若找到则返回res；
3. 没找到，就使Ab += A，再次寻找，找到返回res + 1，否则返回-1。

第3步的目的是检测B在Ab边界上的情况。例如A = “abcd”，B = “cda”。这时Ab = “ab***cda***bcd”，此时res = 2。

三种解法思路一样，区别是使用了不同的匹配算法。

解法一
普通字串匹配算法。效率极低（756ms）。

解法二
KMP匹配算法。高效（16ms）。

解法三
string自带的find()函数。高效（24ms）。

<div style="text-align: right">创建： 2019/06/20 23:36 </div>
<div style="text-align: right">修改： 2019/06/22 00:29 </div>