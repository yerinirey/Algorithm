#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const long long MOD = 1e9 + 7;  // 모듈러 값

long long power(int base, int exp) {
    long long result = 1;
    long long x = base;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * x) % MOD;
        }
        x = (x * x) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int M, N;
    cin >> M >> N;
    ll x, y, z, j;
    ll ans = 0;
    for (j = 2; j <= N; j++) {
        ll res = 0;    
        for (x = 0; x <= M; x++) {
            for (y = x; y <= M; y++) {
                for (z = y; z <= M; z++) {
                    if (power(x, j) + power(y, j) == power(z, j)) res++;
                    if (power(x, j) + power(y, j) < power(z, j)) break;
                }
            }
        }
        ans += res;
    }
    
    cout << ans;
}