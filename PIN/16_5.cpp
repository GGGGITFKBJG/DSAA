#include <iostream>
using namespace std;
void reArrange(int* a, int len) {
    int low = 0;
    int high = len - 1;
    int temp;
    while (low < high) {
        if (a[low] % 2 != 0 || a[high] % 2 == 0) {
            if (a[low] % 2 != 0) low++;
            if (a[high] % 2 == 0) high--;
        }
        else {
            temp = a[low];
            a[low] = a[high];
            a[high] = temp;
        }
    }
}
int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(a) / sizeof(int);
    reArrange(a, len);
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    getchar();
    return 0;
}