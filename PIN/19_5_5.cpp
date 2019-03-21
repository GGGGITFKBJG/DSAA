//快速排序
#include <iostream>
#include <cstdlib>
using namespace std;

void insertSort(int *a, int n) {
    if (a == nullptr || n < 2) return;
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        for (j = i; j > 0; j--) {
            if (temp < a[j - 1]) a[j] = a[j - 1];
            else break;
        }
        a[j] = temp;
    }
}

inline void swap_ab(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int findPivot(int *a, int left, int right) {//找枢纽元并放置
    int center = (left + right) / 2;
    if (a[left] > a[center]) swap_ab(a[left], a[center]);
    if (a[left] > a[right]) swap_ab(a[left], a[right]);
    if (a[center] > a[right]) swap_ab(a[center], a[right]);
    swap_ab(a[center], a[right - 1]);
    return a[right - 1];
}

void quickSort(int *a, int left, int right) {
    if (right - left < 3) {//终止条件, 当元素少于4个时
        insertSort(a + left, right - left + 1);//注意首地址是a + left
        return;
    }

    int pivot = findPivot(a, left, right);
    int i = left, j = right - 1;
    while (true) {
        while (a[++i] < pivot);//等于pivot时停止
        while (a[--j] > pivot);
        if (i < j) swap_ab(a[i], a[j]);
        else break;
    }
    swap_ab(a[i], a[right - 1]);
    quickSort(a, left, i - 1);
    quickSort(a, i + 1, right);
}

void quickSort_main(int *a, int n) {//快速排序驱动程序
    quickSort(a, 0, n - 1);
}

int main() {
    int a[] = { 2, 3, 2, 5, 6, 7, 8, 1, -1, 0, 1, 11, 333, 23 };
    int len = sizeof(a) / sizeof(int);
    quickSort_main(a, len);
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
