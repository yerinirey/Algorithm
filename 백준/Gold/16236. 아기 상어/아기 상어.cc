#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define ll long long
using namespace std;
int N;
pair<int, int> s;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
int map[21][21];
bool visited[21][21];
int total = 0; // 총 걸린 시간
int eatcnt = 0; // 총 먹은 마리수
int cursize = 2;

bool bfs() {
	// pq에 이동 가능한 모든 좌표 집어넣기
	priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
	pq.push({ 0, s.first, s.second }); // 좌표 및 가중치
	visited[s.first][s.second] = true;

	while (!pq.empty()) {
		int d, x, y;
		tie(d,x, y) = pq.top();
		pq.pop();
		// 우선순위 큐 내에서 가장 거리가 가깝고 조건에 만족하는 물고기
		if (map[x][y] > 0 && map[x][y] < cursize) {
			eatcnt++;
			map[x][y] = 0;
			total += d;
			s = { x, y };
			if (eatcnt == cursize) {
				cursize++; eatcnt = 0;
			}
			return true;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] > cursize) continue;
			visited[nx][ny] = true;
			pq.push({ d + 1, nx, ny });
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				s = { i, j };
				map[i][j] = 0; // 시작 위치 비워주기
			}
		}
	}
	while (true) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
			}
		}
		if (!bfs()) break;
	}
	cout << total;
	return 0;
}