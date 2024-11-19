#include <iostream>
using namespace std;

int N, K;
int dp[101][100001];
int w[101], v[101]; // 무게, 가치
int main() {
    cin >> N >> K; // 물건 수, 최대무게
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j >= w[i]) dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][K];
    
    return 0;
}