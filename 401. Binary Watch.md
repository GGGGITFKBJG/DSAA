### 401. 二进制手表

> <div class="content__2ebE"><p>二进制手表顶部有 4 个 LED
> 代表<strong>小时（0-11）</strong>，底部的 6 个 LED
> 代表<strong>分钟（0-59）</strong>。</p>
> 
> <p>每个 LED 代表一个 0 或 1，最低位在右侧。</p>
> 
> <p><img style="height:300px"
> src="https://upload.wikimedia.org/wikipedia/commons/8/8b/Binary_clock_samui_moon.jpg"></p>
> 
> <p>例如，上面的二进制手表读取 “3:25”。</p>
> 
> <p>给定一个非负整数 <em>n&nbsp;</em>代表当前 LED 亮着的数量，返回所有可能的时间。</p>
> 
> <p><strong>案例:</strong></p>
> 
> <pre> 输入: n = 1
>  返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02",
> "0:04", "0:08", "0:16", "0:32"]</pre>
> 
> <p>&nbsp;</p>
> 
> <p><strong>注意事项:</strong></p>
> 
> <ul> 	<li>输出的顺序没有要求。</li> 	<li>小时不会以零开头，比如 “01:00”&nbsp;是不允许的，应为
> “1:00”。</li> 	<li>分钟必须由两位数组成，可能会以零开头，比如 “10:2”&nbsp;是无效的，应为
> “10:02”。</li> </ul> </div>

解法一
```cpp
class Solution {
public:
    Solution() : th(4, vector<int>()), tm(6, vector<int>()) {//构建数组
        for(int i = 0; i < 12; i++) {
            th[numOfOne(i)].push_back(i);
        }
        for(int i = 0; i < 60; i++) {
            tm[numOfOne(i)].push_back(i);
        }
    }
    int numOfOne(int n) {//统计亮灯数
        int count = 0;
        while(n) {
            n &= n - 1;
            count++;
        }
        return count;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> vs;
        for(int i = 0; i < 4; i++) {
            if(num - i < 0) break;
            if(num - i > 5) continue;
            for(int hour : th[i]) {
                for(int minute : tm[num - i]) {
                    string temp = ":";
                    if(minute < 10) temp += "0";
                    vs.push_back(to_string(hour) + temp + to_string(minute));
                }
            }
        }
        return vs;
    }
private:
    vector<vector<int>> th, tm;
};
```

解法二
```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (bitset<10>((h << 6) + m).count() == num) {
                    res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                }
            }
        }
        return res;
    }
};
```

解法一，思路是把所有可能的时间遍历一次，将亮灯数存入两个二维数组里，第一维是亮灯的个数，第二维是时间（时或者分）。然后对于一个输入n，遍历两个二维数组，找出和为n的组合即可。
其中构建数组里，用到了统计位为1的个数，是之前第191题遇到过的问题（关键点在于n &= n - 1）。
解法二，用了C++标准库里的bitset，这里它没有事先建表，而是对每一次输入，都从头开始计算亮灯的个数，代码更简洁。

<div style="text-align: right"> 2019/05/03 21:49  </div>