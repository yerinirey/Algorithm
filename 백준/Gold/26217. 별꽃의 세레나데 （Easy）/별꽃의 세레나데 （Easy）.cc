#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int N;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	double ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += ((double)N / i);
	}
	cout.precision(10);
	cout << fixed << ans;
	return 0;
}
