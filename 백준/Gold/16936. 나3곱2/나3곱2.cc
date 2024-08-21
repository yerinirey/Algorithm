#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
ll arr[101];
int N;
vector<ll> solve(ll startNum, int cnt, vector<ll> tmpres) {
	ll n2 = startNum * 2;
	ll n3 = startNum / 3;
	if (cnt == N) {
		return tmpres;
	}
	for (int i = 0; i < N; i++) {
		if (n2 == arr[i]) {
			tmpres.push_back(n2);
			return solve(n2, cnt + 1, tmpres);
		}
		else if (!(startNum % 3) && n3 == arr[i]) {
			tmpres.push_back(n3);
			return solve(n3, cnt + 1, tmpres);
		}
	}
	return {};
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		vector<ll> v;
		v.push_back(arr[i]);
		v = solve(arr[i], 1, v);
		if (v.size() == N) {
			for (auto c : v) cout << c << " ";
			return 0;
		}
	}
}