#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll a, b, c, d, u;
    cin >> a >> b >> c >> d >> u;
    ll cnt = 0;
    if (a <= u) {
        cnt = 1 + ((u - a) / b); // a와 나머지 개수 더하기
    }

    if (d == 1 && c <= u) { // 공비가 1일 때는 c만 고려하면 된다.
        if (a == c) {}// 중복
        else if (a < c && (c - a) % b == 0) {} // c가 공차수열로 나타내진다면 중복
        else cnt++;
    }
    else { // 공비가 2 이상일 경우
        for (;c <= u;) {
            if (a <= c && (c - a) % b == 0) {} // 현재의 c가 공차수열로 나타내진다면 중복
            else cnt++;
            c *= d;
        }
    }
    cout << cnt;
}