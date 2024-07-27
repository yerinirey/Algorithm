#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int N;
int min_dp[3];
int max_dp[3];
int dp0, dp2; // 갱신하면서 값이 바뀌므로 연산과정을 위해 변수에 저장
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	int a, b, c;
	cin >> a >> b >> c;
	min_dp[0] = max_dp[0] = a;
	min_dp[1] = max_dp[1] = b;
	min_dp[2] = max_dp[2] = c;
	N--;

	while (N--) {
		cin >> a >> b >> c;
		dp0 = min_dp[0], dp2 = min_dp[2];
		min_dp[0] = min(min_dp[0], min_dp[1]) + a;
		min_dp[2] = min(min_dp[1], min_dp[2]) + c;
		min_dp[1] = min(dp0, min(min_dp[1], dp2)) + b;

		dp0 = max_dp[0], dp2 = max_dp[2];
		max_dp[0] = max(max_dp[0], max_dp[1]) + a;
		max_dp[2] = max(max_dp[1], max_dp[2]) + c;
		max_dp[1] = max(dp0, max(max_dp[1], dp2)) + b;
	}
	cout << max(max_dp[0], max(max_dp[1], max_dp[2])) << " ";
	cout << min(min_dp[0], min(min_dp[1], min_dp[2]));
	return 0;
}
