#include <iostream>
using namespace std;

//重排使左边为奇，右边为偶，不改变先后顺序，空间复杂度为O(1)，时间复杂度为O(n^2)
bool reArrange(int* a, int len) {
    if (len < 1) return false;
    int first = 0;
    int temp;
    while (first < len && a[first] % 2 != 0) first++;
    for (int i = first + 1; i < len; i++) {
        if (a[i] % 2 != 0) {
            temp = a[i];
            for (int j = i; j > first; j--) {
                a[j] = a[j - 1];
            }
            a[first++] = temp;
        }
    }

    return true;
}
int main() {
    int a[] = { 1, 2, 3, 4, 5, -6, -7, 8, 9, 10 };
    int len = sizeof(a) / sizeof(int);
    if(!reArrange(a, len)) return 0;
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    getchar();
    return 0;
}