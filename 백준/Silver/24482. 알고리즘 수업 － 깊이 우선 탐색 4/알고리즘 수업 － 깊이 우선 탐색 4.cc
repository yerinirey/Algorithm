#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
vector<int> v[100001];
int N, M, R;
int visited[100001];

bool comp(int a, int b) {
	return a > b;
}


void dfs(int cur) {
	for (int i = 0; i < v[cur].size(); i++) {
		int node = v[cur][i];
		if (visited[node] == -1) {
			visited[node] = visited[cur] + 1;
			dfs(node);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end(), comp); // 내림차순 정렬
		visited[i] = -1;
	}
	visited[R] = 0; // 시작 정점의 깊이
	dfs(R);
	for (int i = 1; i <= N; i++) {
		cout << visited[i] << '\n';
	}
	return 0;
}
