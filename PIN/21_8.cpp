//丢蕃图的墓志铭
#include <iostream>
#include <cstdlib>
using namespace std;

double getDiophantusAge() {//!!!一定要用浮点数
    for (double x = 20; x < 120; x++) {
        if (x / 6 + x / 12 + x / 7 + 5 + x / 2 + 4 == x) {
            return x;
        }
    }
    return -1;
}

int main() {
    cout << getDiophantusAge() << endl;
    system("pause");
    return 0;
}
