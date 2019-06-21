#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void kmp(const string& str, const string& pattern) {//KMP字符串匹配
	int n = str.size(), m = pattern.size();
	if (m == 0) return;//保证pattern非空
	vector<int> next(m);
	next[0] = -1;//第一个元素不匹配时，j指针下一个位置始终为索引0

	for (int i = 1; i < m; i++) {//构建next数组
		int j = next[i - 1];
		while (pattern[j + 1] != pattern[i] && j >= 0) j = next[j];//一直左移，直到找到匹配的位置
		if (pattern[j + 1] == pattern[i]) next[i] = j + 1;//找到了
		else next[i] = -1;//j=-1，表示没找到，就从头开始
	}

	int i = 0, j = 0;//开始搜索
	while (i < n) {
		if (str[i] == pattern[j]) {
			i++, j++;
			if (j == m) {
				cout << i - m << endl;//记录匹配的索引
				j = next[j - 1] + 1;
			}
		}
		else if (j == 0) i++;
		else j = next[j - 1] + 1;
	}
}
int main() {
	string str, pattern;
	cin >> str >> pattern;
	kmp(str, pattern);
	system("pause");
	return 0;
}