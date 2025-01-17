#include <iostream>
#include <algorithm>
using namespace std;
int arr[300000], dp[300000];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++) {
		dp[i] = 0;
	}

	for (int i = M; i < N; i++) {
		dp[i] = max(dp[i - M] + arr[i], dp[i - 1]);
	}
	cout << dp[N - 1];
}