#include <iostream>
using namespace std;
int purge(int* a, int len) {
    int i = 0;
    while (i < len && a[i] != -1) i++;

    for (int j = i + 1; j < len; j++) {
        if (a[j] != -1) {
            a[i] = a[j];
            i++;
        }
    }
    return i;
}
//重排使数组左边为奇，右边为偶，且不改变先后顺序，时间复杂度为O(n)，空间复杂度为O(n)
bool reArrange(int* a, int len) {
    if (len < 1) return false;
    int* b = new int[len];
    if (b == nullptr) return false;
    for (int i = 0, j = 0; i < len; i++) {
        if (a[i] % 2 == 0) {
            b[j++] = a[i];
            a[i] = -1;
        }
    }
    int k = purge(a, len);
    for (int i = k, j = 0; i < len; i++) {
        a[i] = b[j++];
    }
    delete[] b;
    return true;
}
int main() {
    int a[] = {1, 2, 3, 4, 5, -6, -7, 8, 9, 10};
    int len = sizeof(a) / sizeof(int);
    if(!reArrange(a, len)) return 0;
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    getchar();
    return 0;
}