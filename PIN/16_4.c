#include <stdio.h>
#include <math.h>
int minabs(int* a, int len) {
    int minabs = 9999;
    int x;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            x = abs(a[i] - a[j]);
            if (minabs > x) minabs = x;
        }
    }
    return minabs;
}

int main() {
    int a[] = { 1, 12, 23, 4, 25, 20, 2 };
    int len = sizeof(a) / sizeof(int);
    int min = minabs(a, len);
    printf("min = %d\n", min);
    getchar();
    return 0;
}