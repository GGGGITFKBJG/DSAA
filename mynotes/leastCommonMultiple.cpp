#include <iostream>

using namespace std;

inline void swapAB(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int maxCommonFactor(int a, int b) {//辗转相除法求最大公因数
    if(a < b) swapAB(a, b);
    
    int mod = -1;
    while(mod != 0) {
        mod = a % b;
        if(mod == 0) return b;
        a = b;
        b = mod;
    }
    return 0;
}

int LeastCommonMultiple(int a, int b) {//公式法求最小公倍数
    return a * b / maxCommonFactor(a, b);
}

int main()
{
    int a, b;
    while(cin >> a >> b) {
        cout << maxCommonFactor(a, b) << endl;
        cout << LeastCommonMultiple(a, b) << endl;
    }

    return 0;
}

