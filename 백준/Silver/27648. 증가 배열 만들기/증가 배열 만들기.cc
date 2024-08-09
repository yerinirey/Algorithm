#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	if (n + m - 1 > k) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		for (int j = i; j < m+i; j++) {
			cout << j << " ";
		}
		cout << "\n";
	}
	return 0;
}
