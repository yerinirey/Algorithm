#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
vector <int> v[51]; // idx의 자식 노드들 저장
int root, N, K, leaf;
// K노드 삭제 후 리프 노드의 조건
// 1. 자식이 없을 경우
// 2. 자식이 K뿐이었던 경우


int dfs(int node) {
	if (node == K) return -1;
	// node가 지울 대상이 아니지만 자식이 없다면 리프노드
	if (v[node].size() == 0) {
		leaf++;
		return 0;
	}
	for (int i = 0; i < v[node].size(); i++) {
		int tmp = dfs(v[node][i]);
		// node의 자식이 지우는 대상 K고, node의 자식이 K뿐이라면 node가 리프노드가 된다.
		if (tmp == -1 && v[node].size() == 1) leaf++; 
	}
	return 0;
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;  cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n == -1) root = i;
		else v[n].push_back(i);
	}

	cin >> K;
	dfs(root);
	cout << leaf;
	return 0;
}