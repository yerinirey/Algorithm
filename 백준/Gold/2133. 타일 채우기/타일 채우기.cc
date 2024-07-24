#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int N;
int dp[31];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	// dp[k] = dp[k-2]*dp[2] + dp[k-4]*2 + dp[k-6]*2 + ... + dp[0] * 2
	for (int i = 4; i <= N; i += 2) {
		dp[i] = dp[i-2] * dp[2];
		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}
	cout << dp[N];
	return 0;
}
