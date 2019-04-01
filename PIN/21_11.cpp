//图中有多少个三角形
#include <iostream>
#include <cstdlib>
using namespace std;

const char* g[] = { "ab", "ad", "db", 
                    "ah", "ae", "ej", "jh", "aj", "eh",
                    "ai", "af", "fk", "ki", "ak", "fi",
                    "ac", "ag", "gc", 
                    "dg", "de", "ef", "fg", "df", "eg", 
                    "bg", "bj", "jk", "kg", "bk", "jg", 
                    "bc", "bh", "hi", "ic", "bi", "hc" };
const char* lines[] = { "adb", "aejh", "afki", "agc", "defg", "gkjb", "bhic" };

char getCrossPoint(const char *a, const char *b) {//输入保证a, b互异
    if (a[0] == b[0] || a[0] == b[1]) return a[0];
    if (a[1] == b[0] || a[1] == b[1]) return a[1];
    return '\0';
}

bool contain(const char *line, char p) {
    const char *temp = line;
    while (*temp != '\0') {
        if (*temp == p) return true;
        temp++;
    }
    return false;
}

bool isALine(char p, char q, char r) {
    for (int i = 0; i < 7; i++) {
        if (contain(lines[i], p) && contain(lines[i], q) && contain(lines[i], r)) return true;
    }
    return false;
}

bool isTriangle(const char *a, const char *b, const char *c) {//输入保证三条边互异
    char p, q, r;//三条边的交点
    p = getCrossPoint(a, b);
    if (p == '\0') return false;
    q = getCrossPoint(a, c);
    if (q == '\0') return false;
    r = getCrossPoint(b, c);
    if (r == '\0') return false;

    if (p != q && p != r && q != r && !isALine(p, q, r)) return true;
    return false;
}

int getCount() {//遍历3个边的所有组合
    int i = 0, j, k;
    int count = 0;
    while (i < 34) {
        j = i + 1;
        while (j < 35) {
            k = j + 1;
            while (k < 36) {
                if (isTriangle(g[i], g[j], g[k])) count++;
                k++;
            }
            j++;
        }
        i++;
    }
    return count;
}

int main() {
    cout << getCount() << endl;
    system("pause");
    return 0;
}
