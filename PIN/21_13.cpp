//分解质因数
#include <iostream>
#include <cstdlib>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void primeFactor(int n) {
    if (n < 2) return;
    if (isPrime(n)) {//终止条件
        cout << n << endl;
        return;
    }

    int i = 2;
    while (i < n && n % i != 0) i++;
    if (i < n) {
        cout << i << " ";
        primeFactor(n / i);
    }

}

int main() {
    int n;
    while (cin >> n) {
        cout << "the prime factor(s) of " << n << " is/are : " << endl;
        primeFactor(n);
        cout << endl;
    }
    system("pause");
    return 0;
}
