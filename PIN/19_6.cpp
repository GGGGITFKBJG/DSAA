//荷兰国旗问题
#include <iostream>
#include <cstdlib>
using namespace std;

void swap_ab(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void reArrange(int *a, int n) {
    int i = -1, j = n, k;
    while (a[++i] == 0);
    while (a[--j] == 2);
    k = i;
    while (k <= j) {
        if (a[k] == 0) {
            if(k != i) swap_ab(a[i], a[k]);//0, 2, 0, 0, 0, 0, 2: 避免不必要的交换
            k++;
            i++;
        }
        else if (a[k] == 2) {//如果进入了, 说明a[j]一定不是2
            swap_ab(a[k], a[j]);//可以直接换
            while (a[j] == 2) j--;//0, 2, 2, 2, 2, 0, 2: 避免不必要的交换
        }
        else k++;//a[k] == 1
    }
}

int main() {
    int a[] = { 0, 2, 2, 2, 2, 0, 2 };//输入应保证只有0, 1, 2三种元素
    int len = sizeof(a) / sizeof(int);
    reArrange(a, len);
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
