#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

#include <queue>
int map[1001][1001];
int x;
int dx[] = { 1, -1, 0,0 };
int dy[] = { 0,0,1,-1 };
int n, m, t;
void bfs(int i, int j) {
	map[i][j] = -1;
	queue<pair<int, int>> q;
	q.push({ i, j });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
			if (!map[nx][ny] || map[nx][ny] == -1) continue;
			map[nx][ny] = -1;
			q.push({ nx, ny });

		}
	}

}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> x;
				map[i][j] += x;
			}
			map[i][j] /= 3;
		}
	}
	cin >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] >= t) map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	// visited -> -1로 처리
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] && map[i][j] != -1) { // 화면이고 방문하지 않았다면
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
