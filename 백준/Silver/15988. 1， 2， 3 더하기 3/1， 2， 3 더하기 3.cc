#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;
const int DIV = 1000000009;
ll dp[1000001];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (t--) {
		int N;
		cin >> N;
		for (int i = 4; i <= N; i++) dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])%DIV;
		cout << dp[N] % DIV<< "\n";
	}
	return 0;
	
}
