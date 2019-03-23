//斐波那契数列第n项值, 递归, 非递归实现
#include <iostream>
#include <cstdlib>
using namespace std;

int fibonacciRecur(int n) {
    if (n < 1) return -1;
    if (n == 1 || n == 2) return 1;
    else {
        return fibonacciRecur(n - 1) + fibonacciRecur(n - 2);
    }
}

int fibonacci(int n) {
    if (n < 1) return -1;
    int i = 1, j = 1, k = 1;
    while (n-- > 2) {
        k = i + j;
        i = j;
        j = k;
    }
    return k;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
    system("pause");
    return 0;
}
