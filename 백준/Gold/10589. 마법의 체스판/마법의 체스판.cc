#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
#include <vector>
#include <tuple>
int main() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, int, int>> ans;
	for (int i = 2; i <= n; i += 2) {
		ans.push_back({ i, 1, i, m });
	}
	for (int i = 2; i <= m; i += 2) {
		ans.push_back({ 1,i,n,i });
	}
	cout << ans.size() << "\n";
	for (auto cur : ans) {
		int a, b, c, d;
		tie(a, b, c, d) = cur;
		cout << a << " " << b << " " << c << " " << d << "\n";
	}
}
