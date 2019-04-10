//在大矩阵中寻找K
#include <iostream>
#include <cstdlib>
using namespace std;

int p[4][5] = { {1,  2,  3, 16, 20},
                {5,  8,  9, 17, 21},
                {6, 11, 12, 18, 22},
                {7, 14, 15, 19, 23} };

struct Position {
    int i;
    int j;
};

bool searchK(int i, int j, int s, int t, int k, Position& pos) {
    int i_temp = i, j_temp = j;
    for (; i_temp <= s && j_temp <= t; i_temp++, j_temp++) {
        if (k < p[i][j]) return false;
        if (k == p[i_temp][j_temp] ) {
            pos.i = i_temp;
            pos.j = j_temp;
            return true;
        }
        else if (k < p[i_temp][j_temp]) {
            if (searchK(i, j_temp, i_temp - 1, t, k, pos)) return true;
            if (searchK(i_temp, j, s, j_temp - 1, k, pos)) return true;
        }
    }

    if (i_temp > s && j_temp <= t) {
        if (searchK(i, j_temp, s, t, k, pos)) return true;
    }
    else if(i_temp <= s && j_temp > t) {
        if (searchK(i_temp, j, s, t, k, pos)) return true;
    }
    return false;
}

int main() {
    int k;
    cin >> k;
    
    Position pos;

    if (searchK(0, 0, 3, 4, k, pos)) cout << pos.i << ", " << pos.j << endl;
    else cout << "not found" << endl;

    system("pause");
    return 0;
}
