#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int v, n;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> v >> n; // 동전 개수, 만들어야 할 금액

    vector<int> coins(v);
    for (int i = 0; i < v; i++) cin >> coins[i];
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < v; i++) {
        for (int j = coins[i]; j <= n; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    cout << dp[n];

}