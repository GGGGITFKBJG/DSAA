//约瑟夫环, 循环数组实现
#include <iostream>
using namespace std;

void josephSolve(int n, int m) {
    int alive = n;//剩余人数
    int index = 0;//下标索引
    int count = 0;//报数
    int *circle = new int[n]();//初始化为0， 1表示出列

    while (alive) {
        count += 1 - circle[index];//开始报数
        if (count == m) {//报到第m个时
            cout << index + 1 << " ";
            circle[index] = 1;//出列
            count = 0;//重置计数
            alive--;
        }
        index = (index + 1) % n;//索引指向下一个人
    }
    cout << endl;

    delete[] circle;
}

int main() {
    int n, m;
    cin >> n >> m;
    josephSolve(n, m);
    getchar();
    getchar();
    return 0;
}