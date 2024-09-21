#include <iostream>
#include <algorithm>
#include <queue>
using namespace std; 
char map[1001][1001];
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M; cin >> N >> M;
        queue<pair<int, int>> q; // 알고 있는 알파벳들의 인덱스 저장
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> map[i][j];
                if (map[i][j] <= 'Z' && map[i][j] >= 'A') q.push({ i, j });
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            // 가로 확인
            int col_s = y, col_e = y;
            while (col_s >= 1 && map[x][col_s] != '#') col_s--;
            col_s++;
            while (col_e <= M && map[x][col_e] != '#') col_e++;
            col_e--;
            if (map[x][col_e + col_s - y] == '.') {
                map[x][col_e + col_s - y] = map[x][y];
                cnt++;
                q.push({ x, col_e + col_s - y });
            }

            // 세로 확인
            int row_s = x, row_e = x;
            while (row_s >= 1 && map[row_s][y] != '#') row_s--;
            row_s++;
            while (row_e <= N && map[row_e][y] != '#') row_e++;
            row_e--;
            if (map[row_e + row_s - x][y] == '.') {
                map[row_e + row_s - x][y] = map[x][y];
                cnt++;
                q.push({ row_e + row_s - x, y });
            }
        }
        cout << "Case #" << t << ": " << cnt << "\n";
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cout << map[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}