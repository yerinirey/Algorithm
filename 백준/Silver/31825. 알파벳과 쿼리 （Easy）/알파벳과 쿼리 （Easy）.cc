#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
char str[201];
int n, q, opt, from, to;

int func_1() {
	int cnt = 0;
	char alpha = '0';
	for (int i = from; i <= to; i++) {
		if (str[i] == alpha) continue;
		alpha = str[i];
		cnt++;
	}
	return cnt;
}

void func_2() {
	for (int i = from; i <= to; i++) {
		str[i] = (str[i] - 'A' + 1) % 26 + 'A';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> str[i];
	while (q--) {
		cin >> opt >> from >> to;
		if (opt == 1) cout << func_1() << "\n";
		else func_2();
	}
	return 0;
}
