#include <stdio.h>
#include <string.h>
void reverse(int* a, int len) {
    int temp;
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main() {
    int a[] = { 1,2,3,4,5,6,7,8,9 };
    int len = sizeof(a) / sizeof(int);
    reverse(a, len);
    for (int i = 0; i < len; i++) {
        printf("%d", a[i]);
    }
    getchar();
    return 0;
}