#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
string map[51];
int N, M;
int dist[51][51]; // 초기 dist가 1이므로 정답은 1을 빼줘야 함
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int mxt = -1;
queue<pair<int, int>> q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (map[nx][ny] != 'L' || dist[nx][ny]) continue;
			dist[nx][ny] = dist[x][y] + 1;
			mxt = max(dist[nx][ny] - 1, mxt);
			q.push({ nx, ny });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		// L이 육지
		cin >> map[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'L') {
				dist[i][j] = 1;
				q.push({ i, j });
				bfs();
				// visited초기화
				for (int a = 0; a < N; a++) {
					for (int b = 0; b < M; b++) {
						dist[a][b] = 0;
					}
				}
			}
		}
	}
	cout << mxt;
	return 0;
}