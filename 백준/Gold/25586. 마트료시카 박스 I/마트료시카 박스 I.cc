#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
int N, M, K;
bool visited[1001];
bool isChild[1001];
vector<int> v[1001];
vector<pair<int, int>> depth; // 깊이, 노드번호 저장

void bfs(int root) {
    queue<pair<int, int>> q;
    q.push({ 0, root });
    visited[root] = true;
    while (!q.empty()) {
        int d = q.front().first;
        int n = q.front().second;
        q.pop();
        depth.push_back({ d, n });
        for (int i = 0; i < v[n].size(); i++) {
            int nxt = v[n][i];
            if (visited[nxt]) continue;
            visited[nxt] = true;
            q.push({ d + 1, nxt });
        }
    }
}
int find_root() {
    for (int i = 1; i <= N; i++) if (!isChild[i]) return i;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N >> M >> K;
    
    for (int i = 1; i <= N; i++) {
        int n; cin >> n;
        while (n--) {
            int a; cin >> a;
            v[i].push_back(a);
            isChild[a] = true;
        }
    }
    int root = find_root();
    bfs(root);

    // for (auto c : depth) cout << c.first << ' ' << c.second << "\n";

    for (int i = 1; i <= N; i++) v[i].clear();
    for (int i = 0; i < depth.size() - 1; i++) {
        auto cur = depth[i];
        auto nxt = depth[i + 1];
        v[cur.second].push_back(nxt.second);
    }
    
    cout << "1\n0\n";
    for (int i = 1; i <= N; i++) {
        cout << v[i].size() << " ";
        for (auto c : v[i]) cout << c << " ";
        cout << "\n";
    }
    return 0;
}