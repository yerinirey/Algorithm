#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ans;
int N;
char arr[101][101];
vector<pair<int,int>> v;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != '.') v.push_back({ i, j });
        }
    }
    int size = v.size();
    // 기울기 비교
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
                int x1 = v[j].first - v[i].first;
                int y1 = v[j].second - v[i].second;
                int x2 = v[k].first - v[j].first;
                int y2 = v[k].second - v[j].second;
                if (x1 * y2 == x2 * y1) ans++;

            }
        }
    }
    cout << ans;

    return 0;
}
