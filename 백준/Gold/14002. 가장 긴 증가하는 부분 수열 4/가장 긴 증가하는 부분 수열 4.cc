#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int a[1001];
int dp[1001];
int len;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			// 업데이트 해야되고, 수열이 오름차순일 때
			if (dp[i] <= dp[j] && a[j] < a[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		len = max(len, dp[i]);
	}
	cout << len << "\n";
	vector<int> ans;
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == len) {
			ans.push_back(a[i]);
			len--;
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
	return 0;
}
