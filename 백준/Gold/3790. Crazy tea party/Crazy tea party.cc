#include <iostream>
#include <algorithm>
using namespace std; 
int T, N;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        // N명을 절반으로 나눠서 반씩 뒤집기
        int a = N / 2;
        int b = N - N / 2;
        cout << a * (a - 1) / 2 + b * (b - 1) / 2 << "\n";
    }
    return 0;
}