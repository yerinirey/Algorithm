#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
vector<int> v[2001];
int visited[2001];
int ans = 0;
int tmp;
void dfs(int n, int d) {
    if (d == 4) {
        ans = 1;
        return;
    }
    for (int i = 0; i < v[n].size(); i++) {
        if (visited[v[n][i]]) continue;
        visited[v[n][i]] = true;
        dfs(v[n][i], d + 1);
        visited[v[n][i]] = false;
    }
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M; cin >> N >> M;
    int a, b;
    while (M--) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        visited[i] = true;
        dfs(i, 0);
        if (ans) {
            cout << 1;
            return 0;
        }
        for (int j = 0; j < N; j++) visited[j] = false;
    }
    cout << 0;
    return 0;
}
