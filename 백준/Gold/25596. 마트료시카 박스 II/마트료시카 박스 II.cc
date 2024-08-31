#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
queue<int> q[2002];
int N, M, K;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		int C; cin >> C;
		while (C--) {
			int n; cin >> n;
			q[i].push(n);
		}
	}
	int added = 0; // 추가된 박스
	for (int i = 1; i <= N && added <= K; i++) {
		// 최상단 트리에서부터 최대한 박스를 추가하면서 확인
		while (true) {
			if (q[i].size() <= M) break;
			// 서브박스가 M개 이상이어서 추가해야 되는 상황
			// 박스를 더이상 추가할 수 없다면
			if (added + 1 > K) {
				cout << 0; return 0;
			}
			added++;
			for (int k = 0; k < M; k++) {
				q[N + added].push(q[i].front());
				q[i].pop();
			}
			q[i].push(N + added);
		}
	}
	cout << 1<<"\n"<< added << "\n";
	for (int i = 1; i <= N + added; i++) {
		cout << q[i].size() << ' ';
		while (!q[i].empty()) {
			cout << q[i].front() << ' ';
			q[i].pop();
		}
		cout << '\n';
	}

	return 0;
}
