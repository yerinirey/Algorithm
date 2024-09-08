#include <iostream>
#include <algorithm>
using namespace std;
const int MAXTIME = 10001;
int T, S, N;
int lesson[MAXTIME][101]; // lesson[i][A]는 i시에 레벨A가 되기 위해 언제 강습이 시작됐는지 저장
int dp[MAXTIME][101]; // 해당 시간, 레벨일 때 탈 수 있는 최대 슬로프
int mx_slope[MAXTIME]; // 해당 시간일 때 탈 수 있는 최대 슬로프 수
int short_slope[101]; // 해당 레벨일 때 탈 수 있는 가장 짧은 슬로프 시간

void solve() {
    for (int i = 0; i < MAXTIME; i++) {
        for (int j = 0; j < 101; j++) dp[i][j] = -1e9;
    }
    dp[0][1] = 0;
    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= 100; j++) {
            dp[i][j] = dp[i - 1][j]; // 아무것도 하지 않고 1시간을 넘긴 경우
            //i-1시에 강습이 끝나서 j레벨이 되었다면
            // 강습을 듣지 않았을 때와 강습을 들었을 때 중 최대치로 갱신
            if (lesson[i - 1][j]) dp[i][j] = max(dp[i][j], mx_slope[lesson[i - 1][j]]);
            // 슬로프를 탈 수 있는 경우,
            // 그 슬로프 시간 이전에 한 번 탄 경우와 현재 상태 중 최대치로 갱신
            if (i - short_slope[j] >= 0) dp[i][j] = max(dp[i][j], dp[i - short_slope[j]][j]+1);
            mx_slope[i] = max(mx_slope[i], dp[i][j]);
        }
    }
    cout << mx_slope[T];
}



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T >> S >> N;
    for (int i = 1; i <= S; i++) { // 스키 강습 저장
        int M, L, A; // 시작시간, 걸리는 시간, 이후레벨
        cin >> M >> L >> A;
        
        lesson[M + L - 1][A] = max(lesson[M + L - 1][A], M);
    }
    // 각 레벨일 때 탈 수 있는 슬로프 중 가장 짧은 시간 저장
    for (int i = 0; i <= 100; i++) short_slope[i] = 1e9;
    for (int i = 1; i <= N; i++) {
        int C, D;
        cin >> C >> D;
        for (int j = C; j <= 100; j++) {
            short_slope[j] = min(short_slope[j], D);
        }
    }
    solve();
    return 0;
}
