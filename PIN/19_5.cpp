//插入排序, 冒泡排序, 选择排序, 希尔排序
#include <iostream>
#include <cstdlib>
using namespace std;

void insertSort(int *a, int n) {//插入排序
    if (a == nullptr || n == 0) return;
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        temp = a[i + 1];
        for (j = i + 1; j > 0 && temp < a[j - 1]; j--) {
            a[j] = a[j - 1];
        }
        a[j] = temp;
    }
}

void bubbleSort(int *a, int n) {//冒泡排序
    if (a == nullptr || n == 0) return;
    int temp, flag;
    for (int i = n - 1; i > 0; i--) {
        flag = 0;//标志为0时表示该趟没有交换元素
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) break;
    }
}

void selectSort(int *a, int n) {//选择排序
    if (a == nullptr || n == 0) return;
    int minIdx, temp;
    for (int i = 0; i < n - 1; i++) {
        minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[minIdx] > a[j]) minIdx = j;
        }
        if (minIdx == i) continue;
        temp = a[minIdx];
        a[minIdx] = a[i];
        a[i] = temp;
    }
}

void shellSort(int *a, int n) {//希尔排序
    int i, j, inc;
    int temp;
    for (inc = n / 2; inc > 0; inc /= 2) {//增量递减
        for (i = inc; i < n; i++) {//对每一个子序列的每一趟排序
            //对i所在序列进行 一趟 插入排序
            temp = a[i];
            for (j = i; j >= inc; j -= inc) {
                if (temp < a[j - inc]) a[j] = a[j - inc];
                else break;
            }
            a[j] = temp;
        }
    }
}

int main() {
    int a[] = { 1, 2, 3, 6, -1, 5, 4, 3 };
    int len = sizeof(a) / sizeof(int);
    shellSort(a, len);
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
