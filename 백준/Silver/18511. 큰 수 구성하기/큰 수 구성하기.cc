#include <iostream>
#include <algorithm>
using namespace std;
int ans;
int N, K, *arr;
void solve(int num) {
    if (num > N) return;
    ans = max(ans, num);
    num *= 10;
    for (int i = 0; i < K; i++) {
        solve(num + arr[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     cin >> N >> K;
    arr = new int[K];
    for (int i = 0; i < K; i++) cin >> arr[i];
    sort(arr, arr + K);
    solve(0);
    cout << ans;
    return 0;
}
