#include <iostream>
using namespace std;
//时间复杂度O( max(len1, len2) );
int getInterSection(int* a1, int* a2, int len1, int len2, int* b) {
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (a1[i] < a2[j]) i++;
        else if (a1[i] > a2[j]) j++;
        else {
            b[k++] = a1[i];
            i++;
            j++;
        }
    }
    return k;
}
int main() {
    int a1[] = { 2, 5, 6, 8, 9 };
    int a2[] = { 1, 5, 6, 7, 8 };
    int len1 = sizeof(a1) / sizeof(int);
    int len2 = sizeof(a2) / sizeof(int);
    int b[5];
    int len = getInterSection(a1, a2, len1, len2, b);
    for (int i = 0; i < len; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    getchar();
    return 0;
}