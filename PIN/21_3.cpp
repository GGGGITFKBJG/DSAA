//歌德巴赫猜想: 将大于2的偶数分解为两素数之和
#include <iostream>
#include <cstdlib>
using namespace std;
bool isPrime(int n) {
    if (n % 2 == 0) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void getPrimePair(int n) {
    if (n < 2 || n % 2 != 0) return;//如果不是大于2的偶数, 返回
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) {
            cout << i << ", " << n - i << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    getPrimePair(n);
    system("pause");
    return 0;
}
