#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;
int nxt[1000001];// 상위노드 확인

int find_parent(int a) {
	if (nxt[a] == a) return a;
	else return nxt[a] = find_parent(nxt[a]);
}
void uni(int a, int b) {
	int pa = find_parent(a);
	int pb = find_parent(b);
	if (pa == pb) return;
	nxt[pa] = pb;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) nxt[i] = i;
	while (m--) {
		int opt, a, b;
		cin >> opt >> a >> b;
		if (!opt) {
			uni(a, b);
		}
		else {
			int pa = find_parent(a);
			int pb = find_parent(b);
			if (pa == pb) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}