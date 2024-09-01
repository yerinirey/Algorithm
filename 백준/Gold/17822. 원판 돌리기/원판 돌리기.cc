#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
int N, M, T;
int map[51][51];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
void rotate_plate(int cur, int d, int k) {
    int tmp[51] = {};
    // 시계방향
    if (!d) {
        for (int i = 0; i < M; i++) {
            int r = (i + k) % M;
            tmp[r] = map[cur][i];
        }
    }
    else {
        for (int i = 0; i < M; i++) {
            int r = (i + k) % M;
            tmp[i] = map[cur][r];
        }
    }
    for (int i = 0; i < M; i++) map[cur][i] = tmp[i];
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // input
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    while (T--) {
        // 회전 input
        int x, d, k;
        cin >> x >> d >> k;
        // x의 배수 원판 회전
        for (int i = x - 1; i < N; i += x) {
            rotate_plate(i, d, k);
        }

        // 회전이 끝난 후 인접한 숫자가 있는지 확인
        bool found = false;
        bool replace[51][51] = { false, }; // 인접한 숫자들 저장

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int cur = map[i][j];
                if (!cur) continue;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= N) continue; // 인접하지 않는 경우
                    if (ny == -1) ny = M - 1;
                    if (ny == M) ny = 0;
                    if (map[nx][ny] == cur) {
                        found = true;
                        replace[i][j] = true;
                        replace[nx][ny] = true;
                    }
                }

            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (replace[i][j]) map[i][j] = 0;
            }
        }
        // 인접한 수가 없다면 평균과 비교
        if (!found) {
            int sum = 0, nums = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (map[i][j]) {
                        sum += map[i][j];
                        nums++;
                    }
                }
            }
            // 평균보다 크다면 1 빼고, 작다면 1 더하기
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (map[i][j]) {
                        if (map[i][j] * nums > sum) map[i][j] -= 1;
                        else if (map[i][j] * nums < sum) map[i][j] += 1;
                    }
                }
            }
        }
    }
    int s = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            s += map[i][j];
        }
    }
    cout << s;
    return 0;
}