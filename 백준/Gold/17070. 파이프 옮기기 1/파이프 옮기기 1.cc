#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int N;
int dx[3] = { 0,1,1 };
int dy[3] = { 1, 0, 1 };
int map[17][17];
int ans;

// 좌표 및 놓여진 방향(0:가로 1:세로 2:대각선)
void solve(int cx, int cy, int dir) {
	if (cx == N-1 && cy == N-1) {
		ans++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if ((dir == 0 && i == 1) || (dir == 1 && i == 0)) continue;
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if (map[nx][ny]) continue;
		if (i== 2) {
			if (map[cx + dx[0]][cy + dy[0]] || map[cx + dx[1]][cy + dy[1]]) continue;
		}
		solve(nx, ny, i);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	solve(0, 1, 0);
	cout << ans;
}