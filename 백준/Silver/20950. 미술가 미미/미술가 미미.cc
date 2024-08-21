#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
int N;
int arr[31][3];
int R, G, B;
int ans = 1e9;

void dfs(int idx, int cnt, int rr, int gg, int bb) {
	if (cnt > 1) {
		int tmpR = rr / cnt;
		int tmpG =  gg / cnt;
		int tmpB = bb / cnt;
		int tmp = abs(tmpR - R) + abs(tmpG - G) + abs(tmpB - B);
		ans = min(ans, tmp);
	}
	if (cnt == 7 || idx == N) return;
	dfs(idx + 1, cnt + 1, rr + arr[idx][0], gg + arr[idx][1], bb + arr[idx][2]);
	dfs(idx + 1, cnt, rr, gg, bb);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	cin >> R >> G >> B;
	dfs(0, 0, 0, 0, 0);
	cout << ans;
	return 0;
}
