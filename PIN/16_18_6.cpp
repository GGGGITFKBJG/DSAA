//约瑟夫环递归实现
#include <iostream>
using namespace std;

int josephSolve(int n, int m, int k) {
    if (k == 1) return (n + m - 1) % n;
    return (josephSolve(n - 1, m, k - 1) + m) % n;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cout << josephSolve(n, m, i) << " ";
    }
    cout << endl;
    getchar();
    getchar();
    return 0;
}