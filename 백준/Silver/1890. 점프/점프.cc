#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int N, M;
ll arr[101][101], dp[101][101];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	dp[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int jump = arr[i][j];
			if (i != N && i + jump <= N) { // i == N일 때 jump가 0이므로 값이 두 배가 되어버리는 문제 발생
				dp[i + jump][j] += dp[i][j];
			}
			if (j != N && j + jump <= N) {
				dp[i][j + jump] += dp[i][j];
			}
		}
	}
	cout << dp[N][N];
	return 0;
}
