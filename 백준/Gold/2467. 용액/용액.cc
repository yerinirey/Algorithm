#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
int val[100001], N;
int ans = 2e9;
pair<int, int > p;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> val[i];
	sort(val, val + N);
	int lt = 0, rt = N - 1;
	while (lt < rt) {
		int cur = val[lt] + val[rt];
		if (abs(cur) < ans) {
			p = { val[lt], val[rt] };
			ans = abs(cur);
		}
		if (cur < 0) {
			lt++;
		}
		else rt--;
	}
	cout << p.first << " " << p.second;
	return 0;
}