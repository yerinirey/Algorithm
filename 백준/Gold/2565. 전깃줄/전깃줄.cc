#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

#include <vector>
vector<pair<int, int>> v;
int maxLen;
int dp[101] = { 1, };
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	// LIS
	for (int i = 0; i < N; i++) {
		int len = 0;
		for (int j = 0; j < i; j++) {
			if(v[j].second < v[i].second)
			len = max(len, dp[j]); // 최장 증가수열 확인
		}
		dp[i] = len + 1; // 자기자신의 길이 포함
	}
	// 도출된 최장 수열은 가장 많이 배치할 수 있는 전선 -> 뺀 값이 결과값
	int ans = 0;
	for (int i = 0; i < N; i++) ans = max(ans, dp[i]);
	cout << N - ans;
	return 0;
}
