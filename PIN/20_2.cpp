//统计有序数组中某元素的个数
#include <iostream>
#include <cstdlib>
using namespace std;

int binSearch(int *a, int n, int key, int flag) {
    int left = 0, right = n - 1, mid;
    int last = -1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] > key) right = mid - 1;
        else if (a[mid] < key) left = mid + 1;
        else {//如果找到了, 继续往边界上查找, 并记录下最后一次找到的位置, 直到left > right
            last = mid;
            if (flag == 0) right = mid - 1;
            else left = mid + 1;
        }
    }
    return last;
}

int getNumCount(int *a, int n, int key) {
    if (a == nullptr || n < 1) return -1;
    int left = binSearch(a, n, key, 0);
    int right = binSearch(a, n, key, 1);
    if (left != -1 && right != -1) return right - left + 1;
    else return 0;
}

int main() {
    int a[] = { 0, 1, 2, 2, 2, 2, 2, 2, 3, 4, 5 };
    int len = sizeof(a) / sizeof(int);
    int i = getNumCount(a, len, 2);
    cout << i << endl;
    system("pause");
    return 0;
}
