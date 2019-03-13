#include <iostream>
using namespace std;
int haveRepeatElem(int* a, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += a[i];
    }
    if (sum == (len + 1) * len / 2) return 0;
    else return 1;
}
int main() {
    int a[] = { 2, 5, 3, 8, 1, 4, 6, 7};
    int b[] = { 2, 5, 3, 8, 3, 5, 8, 8 };
    int len1 = sizeof(a) / sizeof(int);
    int len2 = sizeof(b) / sizeof(int);
    cout << (haveRepeatElem(a, len1) ? "yes" : "no") << endl;
    cout << (haveRepeatElem(b, len2) ? "yes" : "no") << endl;

    getchar();
    return 0;
}