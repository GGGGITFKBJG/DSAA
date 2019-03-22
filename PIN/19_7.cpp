//堆排序, 堆中元素i从1开始，索引为i - 1
#include <iostream>
#include <cstdlib>
using namespace std;

void percolateDown(int *a, int n, int i) {//下滤
    int temp = a[i - 1];
    int j = 2 * i;
    while (j <= n) {
        if (j < n && a[j - 1] < a[j]) j++;
        if (temp >= a[j - 1]) break;
        a[i - 1] = a[j - 1];
        i = j;
        j = 2 * i;
    }
    a[i - 1] = temp;
}

inline void swap_ab(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapSort(int *a, int n) {//堆排序
    for (int i = n / 2; i >= 1; i--) {//重排使具有堆序
        percolateDown(a, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(a[0], a[i - 1]);
        percolateDown(a, i - 1, 1);//对长为i - 1的数组a, 对第1个元素进行下滤操作
    }
}

int main() {
    int a[] = { 7, 6, 5, 4, 3, 2 };
    int len = sizeof(a) / sizeof(int);
    heapSort(a, len);
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
