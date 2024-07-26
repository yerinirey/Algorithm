#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
#include <vector>
vector<int> v[5001]; // 색깔이 1, 2로 입력됨 -> 0 1에 저장
int N, maxColor, minColor = 5010;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	while (N--) {
		int d, color;
		cin >> d >> color;
		maxColor = max(color, maxColor);
		minColor = min(color, minColor);
		v[color].push_back(d);
	}
	int ans = 0;
	for (int color = minColor; color <= maxColor; color++) {
		// 점이 하나라면 선을 이을 수 없음
		if (v[color].size() == 1) continue;

		// 오름차순 정렬
		sort(v[color].begin(), v[color].end());
		for (int i = 0; i < v[color].size(); i++) {
			// 가장 작은 수일 때
			if (i == 0) {
				ans += v[color][i + 1] - v[color][i];
			}
			// 가장 큰 수일 때
			else if (i == v[color].size() - 1) {
				ans += v[color][i] - v[color][i - 1];
			}
			// 중간에 위치한 수일 때
			else {
				int pre = v[color][i] - v[color][i - 1];
				int nxt = v[color][i + 1] - v[color][i];
				ans += min(pre, nxt);
			}
		}
	}
	cout << ans;
	return 0;
}

// 색깔이 같은 점들 중 가장 가까운 거리의 점과의 거리들 합산