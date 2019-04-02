//递归寻找数组最大值
#include <iostream>
#include <cstdlib>
using namespace std;
int getMax(int *a, int n) {
    if (a == nullptr) return -1;
    if (n == 1) return a[0];//终止条件
    
    int temp = getMax(a + 1, n - 1);
    return a[0] > temp ? a[0] : temp;
}
int main() {
    int a[] = { 2, 1, 3, 4, 6, 5, 8, 7, 9 };
    int len = sizeof(a) / sizeof(int);
    cout << getMax(a, len) << endl;
    system("pause");
    return 0;
}
