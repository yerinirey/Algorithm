#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;

int dp[100001];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	dp[0] = dp[1] = -1;
	dp[2] = 1;
	dp[3] = -1;
	dp[4] = 2;
	dp[5] = 1;
	dp[6] = 3;
	dp[7] = 2;
	dp[8] = 4;
	for (int i = 9; i <= N; i++) dp[i] = dp[i - 5] + 1;
	cout << dp[N];
	return 0;
}
