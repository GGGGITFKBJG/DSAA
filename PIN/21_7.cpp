//渔夫捕鱼
#include <iostream>
#include <cstdlib>
using namespace std;
int getFishCount() {
    int i = 0, j;
    int s;
    while (true) {
        i++;
        s = 1 + 5 * i;
        for (j = 0; j < 4; j++) {
            if (s % 4 != 0) break;
            s = s / 4 * 5 + 1;
        }
        if (j == 4) return s;
    }
}

int main() {
    cout << getFishCount() << endl;
    system("pause");
    return 0;
}
