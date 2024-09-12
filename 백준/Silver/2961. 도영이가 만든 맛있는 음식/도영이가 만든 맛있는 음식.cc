#include <iostream>
#include <vector>
using namespace std; 
vector<pair<int,int>> v;
int ans = 1e9;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, b;
        cin >> s >> b;
        v.push_back({ s, b });
    }
    for (int i = 1; i < (1 << N); i++) {
        int sour = 1, bitter = 0;
        for (int j = 0; j < N; j++) {
            int mask = 1 << j;
            if (i & mask) {
                sour *= v[j].first;
                bitter += v[j].second;
            }
        }
        ans = min(ans, abs(sour - bitter));
    }
    cout << ans;
    return 0;
}