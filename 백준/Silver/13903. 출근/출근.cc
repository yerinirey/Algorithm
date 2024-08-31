#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define ll long long
using namespace std;

int map[1001][1001];
bool vis[1001][1001];
int dx[11], dy[11];
int R, C, dir;
int ans = 1e9;
queue<tuple<int, int, int>> q;

void bfs() {
	while (!q.empty()) {
		int x, y, d;
		tie(x, y, d) = q.front();
		q.pop();
		if (x == R) {
			ans = min(ans, d);
		}
		for (int i = 0; i < dir; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > R || ny > C) continue;
			if (vis[nx][ny] || !map[nx][ny]) continue;
			vis[nx][ny] = true;
			q.push({ nx,ny,d + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}
	}
	cin >> dir;
	for (int i = 0; i < dir; i++) {
		cin >> dx[i] >> dy[i];
	}
	for (int i = 1; i <= C; i++) {
		if (map[1][i]) {
			vis[1][i] = true;
			q.push({ 1, i, 0 });
		}
	}
	bfs();
	if (ans == 1e9) ans = -1;
	cout << ans;
	return 0;
}
