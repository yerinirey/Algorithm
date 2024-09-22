#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define X first
#define Y second
using namespace std;
int dx[4] = { 1, 0, -1, 0 };// 남 서 북 동
int dy[4] = { 0, -1, 0, 1 };
int N, M;
char map[11][11];
int dist[11][11][11][11]; // R.first, R.second, B.first, B.second의 cost;
pair<int, int> red, blue;
int solve() {
    queue<tuple<int, int, int, int>> q;
    q.push({ red.X, red.Y, blue.X, blue.Y });
    dist[red.X][red.Y][blue.X][blue.Y] = 0; // 초기상태
    while (!q.empty()) {
        int rx, ry, bx, by;
        tie(rx, ry, bx, by) = q.front();
        q.pop();
        int cnt = dist[rx][ry][bx][by];
        for (int d = 0; d < 4; d++) {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            while (map[nbx + dx[d]][nby + dy[d]] == '.') {
                nbx += dx[d];
                nby += dy[d];
            }
            if (map[nbx + dx[d]][nby + dy[d]] == 'O') continue; // blue탈출 -> back
            while (map[nrx + dx[d]][nry + dy[d]] == '.') {
                nrx += dx[d];
                nry += dy[d];
            }
            if (map[nrx + dx[d]][nry + dy[d]] == 'O') return cnt + 1; // red탈출

            // 구멍을 찾지 못한 경우
            if ((nrx == nbx) && (nry == nby)) { // 상하좌우 이동으로 인해 겹친 경우
                if (d == 0) rx > bx ? nbx-- : nrx--; // 남쪽 이동
                else if (d == 1) ry < by ? nby++ : nry++; // 서쪽 이동
                else if (d == 2) rx > bx ? nrx++ : nbx++;// 북쪽 이동
                else ry < by ? nry-- : nby--; // 동쪽 이동
            }
            if (dist[nrx][nry][nbx][nby] != -1) continue; // 이미 방문한 경우
            dist[nrx][nry][nbx][nby] = cnt + 1;
            q.push({ nrx, nry, nbx, nby });
        }
    }
    return -1;
}

// Red가 탈출해야 함
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                fill(dist[a][b][c], dist[a][b][c] + 10, -1);
            }
        }
    }

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') red = { i,j };
            if (map[i][j] == 'B') blue = { i,j };
        }
    }
    map[red.first][red.second] = '.';
    map[blue.first][blue.second] = '.';
    cout << solve();
    return 0;
}