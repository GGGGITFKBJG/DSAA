#include <iostream>
using namespace std;
int isContinous(int *a, int len) {
    if (len < 1) return -1;
    int i = 0;
    while (i < len && a[i] == 0) i++;
    if (i == len) return 1;
    int max = a[i], min = a[i];//min不能是0

    for (int i = 0; i < len; i++) {
        if (a[i] == 0) continue;
        if (max < a[i]) max = a[i];
        else if (min > a[i]) min = a[i];
    }
    if (max - min < len) return 1;
    else return 0;
}
int main() {
    int a[] = { 0, 0, 1, 3, 2, 4, 6, 7 };
    int len = sizeof(a) / sizeof(int);
    int flag = isContinous(a, len);
    cout << "is continous ? " << flag << endl;
    getchar();
    return 0;
}