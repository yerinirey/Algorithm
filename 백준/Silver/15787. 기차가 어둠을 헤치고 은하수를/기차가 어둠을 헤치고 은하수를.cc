#include <iostream>
#include <vector>
using namespace std; 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M;
    cin >> N >> M;
    int* train = new int[N + 1]();
    while (M--) {
        int a, b, c;
        cin >> a >> b;
        if (a <= 2) cin >> c;

        if (a == 1) {
            train[b] |= (1 << c);
        }
        else if (a == 2) {
            train[b] &= ~(1 << c);
        }
        else if (a == 3) {
            train[b] <<= 1;
            train[b] &= ((1 << 21) - 1);
        }
        else {
            train[b] >>= 1;
            train[b] &= ~1;
        }
    }
    int* used = new int[1 << 21]();
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (used[train[i]]) continue;
        ans++;
        used[train[i]] = 1;
    }
    cout << ans;

    delete[] used;
    delete[] train;
    return 0;
}