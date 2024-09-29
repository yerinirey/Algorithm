#include <iostream>
#include <algorithm>
using namespace std;
int N;

bool is_digit(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
void dfs(int n, int len) {
    if (len == N) {
        cout << n << '\n';
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (is_digit(n * 10 + i)) dfs(n * 10 + i, len + 1);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int c : { 2, 3, 5, 7 }) {
        dfs(c, 1);
    }
    return 0;
}