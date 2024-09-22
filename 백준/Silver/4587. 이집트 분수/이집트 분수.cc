#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std; 

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
ll m, n, tmp, tm, tn, g;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (true) {
        cin >> m >> n;
        if (!m && !n) return 0;
        vector<ll> v;   
        while (m) {
            tmp = n / m;
            if (n % m) tmp++;
            tm = m * tmp - n;
            tn = n * tmp;
            g = gcd(tm, tn);
            tn /= g; tm /= g;
            while (tn >= 1000000) {
                tmp++;
                tm = m * tmp - n;
                tn = n * tmp;
                g = gcd(tm, tn);
                tn /= g; tm /= g; // 반복
            }
            n = tn; m = tm;
            v.push_back(tmp);
        }
        for (auto c : v) {
            cout << c << " ";
        }
        cout << "\n";
    }
}