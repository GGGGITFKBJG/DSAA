#include <stdio.h>
void purge(int* a, int* len) {
    for (int i = 0; i < *len - 1; i++) {
        for (int j = i + 1; j < *len; j++) {
            if (a[i] == a[j]) a[j] = -1;
        }
    }
    int i = 0;
    while (a[i] != -1) i++;//------------------------
    for (int j = i + 1; j < *len; j++) {
        if (a[j] != -1) {
            a[i++] = a[j];
        }
    }
    *len = i;
}
int main() {
    int a[] = { 2, 3, 5, 2, 5, 3, 6, 9, 11, 6};
    int len = sizeof(a) / sizeof(int);
    purge(a, &len);
    for (int i = 0; i < len; i++) printf("%d ", a[i]);
    printf("\nlen = %d\n", len);
    getchar();
    return 0;
}