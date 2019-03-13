#include <iostream>
using namespace std;
int binserch(int* a, int len, int elem) {
    int low = 0, high = len - 1;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (a[mid] > elem) high = mid - 1;
        else if (a[mid] < elem) low = mid + 1;
        else return mid;
    }
    return -1;
}
//len1远小于len2时，采用遍历a1对a2对分查找，时间复杂度O( len1 * log(len2) )
int getInterSection(int* a1, int* a2, int len1, int len2, int* b) {
    int k = 0;
    for (int i = 0; i < len1; i++) {
        int j = binserch(a2, len2, a1[i]);
        if (j != -1) b[k++] = a2[j];
    }
    return k;
}
int main() {
    int a1[] = { 1, 2, 3, 6, 7, 22 };
    int a2[] = { -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    int len1 = sizeof(a1) / sizeof(int);
    int len2 = sizeof(a2) / sizeof(int);
    int b[3];
    int len = getInterSection(a1, a2, len1, len2, b);
    for (int i = 0; i < len; i++) {
        cout << " " << b[i];
    }
    cout << endl;
    getchar();
    return 0;
}