#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int N;
int arr[100001], dp[100001];
int scoreCnt(int k);
void solve() {
	dp[0] = dp[1] = 0;
	if (N >= 2) {
		dp[2] = scoreCnt(arr[1] ^ arr[2]);
		if (N >= 3) dp[3] = scoreCnt(arr[1] ^ arr[2] ^ arr[3]);
		if (N >= 4) dp[4] = dp[2] + scoreCnt(arr[3] ^ arr[4]);
	}
	for (int i = 5; i <= N; i++) {
		int twoSet = scoreCnt(arr[i] ^ arr[i - 1]);
		int threeSet = scoreCnt(arr[i] ^ arr[i - 1] ^ arr[i - 2]);
		dp[i] = max(twoSet + dp[i - 2], threeSet + dp[i - 3]);
	}
	cout << dp[N];
}
int scoreCnt(int k) {
	int cnt = 0;
	while (k > 0) {
		cnt += k & 1;
		k >>= 1;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	solve();
	return 0;
}