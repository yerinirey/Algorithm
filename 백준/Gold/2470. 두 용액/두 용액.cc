#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
pair<int, int> p;
int N;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int lt = 0;
	int rt = N - 1;
	ll res = 2e9;

	while (lt < rt) {
		ll tmp = v[lt] + v[rt];
		if (abs(tmp) < res) {
			p = { lt, rt };
			res = abs(tmp);
		}
		if (tmp < 0) {
			lt++;
		}
		else rt--;
	}
	cout << v[p.first] << " " << v[p.second];
}