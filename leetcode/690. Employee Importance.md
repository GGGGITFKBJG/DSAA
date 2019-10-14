### 690. 员工的重要性

> <div class="content__2ebE"><p>给定一个保存员工信息的数据结构，它包含了员工<strong>唯一的id</strong>，<strong>重要度&nbsp;</strong>和 <strong>直系下属的id</strong>。</p>
> 
> <p>比如，员工1是员工2的领导，员工2是员工3的领导。他们相应的重要度为15, 10, 5。那么员工1的数据结构是[1, 15, [2]]，员工2的数据结构是[2, 10, [3]]，员工3的数据结构是[3, 5, []]。注意虽然员工3也是员工1的一个下属，但是由于<strong>并不是直系</strong>下属，因此没有体现在员工1的数据结构中。</p>
> 
> <p>现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。</p>
> 
> <p><strong>示例 1:</strong></p>
> 
> <pre><strong>输入:</strong> [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
> <strong>输出:</strong> 11
> <strong>解释:</strong>
> 员工1自身的重要度是5，他有两个直系下属2和3，而且2和3的重要度均为3。因此员工1的总重要度是 5 + 3 + 3 = 11。
> </pre>
> 
> <p><strong>注意:</strong></p>
> 
> <ol>
> 	<li>一个员工最多有一个<strong>直系</strong>领导，但是可以有多个<strong>直系</strong>下属</li>
> 	<li>员工数量不超过2000。</li>
> </ol>
> </div>

解法一
```cpp
//时间复杂度O(n^2), 空间复杂度O(n)
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        unordered_set<int> us;
        us.insert(id);
        while(!us.empty()) {
            for(Employee* em : employees) {
                if(us.count(em->id)) {
                    res += em->importance;
                    us.erase(em->id);
                    for(int subd : em->subordinates) us.insert(subd);
                }
            }
        }
        return res;
    }
};
```

解法二
```cpp
//时间复杂度O(n), 空间复杂度O(n)
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        unordered_map<int, Employee*> um;//id, Employee*
        for(Employee* em : employees) um[em->id] = em;
        queue<int> q;//id
        q.push(id);
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            res += um[temp]->importance;
            for(int subd : um[temp]->subordinates) q.push(subd);
        }
        return res;
    }
};
```

思路：

使用一个容器记录所求员工的所有直系下属员工，对于每个下属员工，将其重要度累加，并将其直系下属员工放入容器。循环进行上述操作，直到容器内为空。

解法一、解法二思路一样，解法二使用了一个额外的哈希表来避免从头到尾的搜索，因此效率更高。

<div style="text-align: right"> 2019/06/22 13:12 </div>