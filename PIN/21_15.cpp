//上楼梯问题, 回溯法
#include <iostream>
#include <cstdlib>
using namespace std;

int solutionCount = 0;//记录解的个数

void upstaris(int footStep, int haveDone, int steps, int *p, int k) {
    if (footStep + haveDone > k) return;

    p[steps++] = footStep;//记录当前步大小
    if (footStep + haveDone == k) {
        solutionCount++;
        for (int i = 0; i < steps; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
        return;
    }
    upstaris(1, haveDone + footStep, steps, p, k);
    upstaris(2, haveDone + footStep, steps, p, k);
}

void solveUpstairsProblem(int k) {
    int *p = new int[k];
    upstaris(1, 0, 0, p, k);//左子树
    upstaris(2, 0, 0, p, k);//右子树
    delete[] p;
}

int main() {
    int k;
    cin >> k;
    solveUpstairsProblem(k);
    cout << "The problem has " << solutionCount << " solutions." << endl;
    system("pause");
    return 0;
}
