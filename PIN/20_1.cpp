//二分查找, 递归, 非递归
#include <iostream>
#include <cstdlib>
using namespace std;

int binSearch(int *a, int n, int target) {
    int left = 0, mid, right = n - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] > target) right = mid - 1;
        else if (a[mid] < target) left = mid + 1;
        else return mid;
    }
    return -1;
}

int binSearchRecur(int *a, int left, int right, int target) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (a[mid] == target) return mid;
    
    int i;
    if (a[mid] > target) i = binSearchRecur(a, left, mid - 1, target);
    else i = binSearchRecur(a, mid + 1, right, target);
    return i;
}

int main() {
    int a[] = { 1, 3, 5, 7, 10, 12, 15, 19, 21, 50 };
    int len = sizeof(a) / sizeof(int);
    //int i = binSearchRecur(a, 0, len - 1, 21);
    int i = binSearch(a, len, 21);
    cout << i << endl;
    system("pause");
    return 0;
}
