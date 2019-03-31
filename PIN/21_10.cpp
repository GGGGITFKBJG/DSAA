//寻找丑数
#include <iostream>
#include <cstdlib>
using namespace std;

int findNext(int& loc2, int& loc3, int& loc5, int *a, int index) {
    while (a[loc2] * 2 <= a[index]) loc2++;
    while (a[loc3] * 3 <= a[index]) loc3++;
    while (a[loc5] * 5 <= a[index]) loc5++;
    if (a[loc2] * 2 <= a[loc3] * 3) {
        return a[loc2] * 2 < a[loc5] * 5 ? a[loc2] * 2 : a[loc5] * 5;
    }
    else {
        return a[loc3] * 3 < a[loc5] * 5 ? a[loc3] * 3 : a[loc5] * 5;
    }
}

int main() {
    int uglyNums[1000];
    uglyNums[0] = 1;
    int index = 0;
    int loc2 = 0, loc3 = 0, loc5 = 0;
    while (++index < 100) {
        uglyNums[index] = findNext(loc2, loc3, loc5, uglyNums, index - 1);
    }
    for (int i = 0; i < index; i++) {
        cout << uglyNums[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
