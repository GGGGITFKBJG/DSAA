//矩阵中的相邻数, DFS
#include <iostream>
#include <cstdlib>
using namespace std;

int a[5][5] = { {1, 1, 5, 5, 1},
                {5, 5, 5, 1, 1},
                {1, 1, 5, 5, 1},
                {1, 1, 5, 1, 1},
                {5, 1, 1, 1, 5} };

int p[5][5] = { {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {0, 0, 0, 0, 0} };

int cnt = 0;

bool isValid(int i, int j) {
    if (i < 0 || i > 4 || j < 0 || j > 4 || p[i][j] == 1) return false;
    return true;
}

void adjacentNumber(int i, int j, int k) {
    p[i][j] = 1;
    if (isValid(i - 1, j)) {//上
        if (a[i - 1][j] == k) {
            cnt++;
            adjacentNumber(i - 1, j, k);
        }
    }
    if (isValid(i + 1, j)) {//下
        if (a[i + 1][j] == k) {
            cnt++;
            adjacentNumber(i + 1, j, k);
        }
    }
    if (isValid(i, j - 1)) {//左
        if (a[i][j - 1] == k) {
            cnt++;
            adjacentNumber(i, j - 1, k);
        }
    }
    if (isValid(i, j + 1)) {//右
        if (a[i][j + 1] == k) {
            cnt++;
            adjacentNumber(i, j + 1, k);
        }
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int i, j, k;
    cin >> i >> j >> k;
    adjacentNumber(i, j, k);
    cout << cnt << endl;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
