//数的分组, 穷举法
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <climits>

using namespace std;

void minDiff(int *a) {
    unsigned int i, j, k, r;//i所有码空间, j掩码, k掩码代表的下标(左0->右9), r代表结果的位码
    int sum1, sum2;//组1, 组2各自的元素和
    int diff = INT_MAX;//两组和之差
    for (i = 0x0001; i < 0x03fe; i++) {//1~1022, 遍历所有位码
        sum1 = 0;
        sum2 = 0;
        for (j = 0x0001, k = 9; j <= 0x0200; j *= 2, k--) {//掩码1, 2, 4, ..., 512, 每次向左移1位
            if (i & j) sum1 += a[k];//位为1归第1组
            else sum2 += a[k];//位为0归第2组
        }
        if (abs(sum1 - sum2) < diff) {
            r = i;
            diff = abs(sum1 - sum2);
        }
    }
    cout << "group1: " << endl;
    for (j = 0x1, k = 9; j <= 0x200; j *= 2, k--) {
        if (j & r) cout << a[k] << " ";
    }
    cout << endl;
    cout << "group2: " << endl;
    for (j = 0x1, k = 9; j <= 0x200; j *= 2, k--) {
        if (!(j & r)) cout << a[k] << " ";
    }
    cout << endl;
    cout << "difference = " << diff << endl;
}

int main() {
    int a[10];
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    minDiff(a);
    system("pause");
    return 0;
}
