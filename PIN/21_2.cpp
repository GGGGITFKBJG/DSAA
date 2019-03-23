//寻找数组中第2大的数
#include <iostream>
#include <cstdlib>
using namespace std;

void swap_ab(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int findSecMax(int *a, int n) {
    if (n < 2) return -1;
    int max = a[0], secMax = a[1];
    if (max < secMax) swap_ab(max, secMax);
    for (int i = 2; i < n; i++) {
        if (a[i] > max) {
            secMax = max;
            max = a[i];
        }
        else if (a[i] > secMax && a[i] < max) {
            secMax = a[i];
        }
    }
    return secMax;
}

int main() {
    int a[] = { 2, 1, 3, 6, 4, 5, 7, 9, 8 };
    int len = sizeof(a) / sizeof(int);
    cout << findSecMax(a, len) << endl;
    system("pause");
    return 0;
}
