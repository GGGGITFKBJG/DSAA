412. Fizz Buzz

> <div class="content__2ebE"><p>写一个程序，输出从 1 到 <em>n</em> 数字的字符串表示。</p>
> 
> <p>1. 如果&nbsp;<em>n&nbsp;</em>是3的倍数，输出“Fizz”；</p>
> 
> <p>2. 如果&nbsp;<em>n&nbsp;</em>是5的倍数，输出“Buzz”；</p>
> 
> <p>3.如果&nbsp;<em>n&nbsp;</em>同时是3和5的倍数，输出 “FizzBuzz”。</p>
> 
> <p><strong>示例：</strong></p>
> 
> <pre>n = 15,
> 
> 返回: [
>     "1",
>     "2",
>     "Fizz",
>     "4",
>     "Buzz",
>     "Fizz",
>     "7",
>     "8",
>     "Fizz",
>     "Buzz",
>     "11",
>     "Fizz",
>     "13",
>     "14",
>     "FizzBuzz" ] </pre> </div>

解法一
```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for(int i = 1; i <= n; i++) {
            if(i % 3 != 0 && i % 5 != 0) res.push_back(to_string(i));
            else {
                string temp = "";
                if(i % 3 == 0) temp += "Fizz";
                if(i % 5 == 0) temp += "Buzz";
                res.push_back(temp);
            }
        }
        return res;
    }
};
```

体力劳动。
   <div style="text-align: right"> 2019/05/04 01:31  </div>
