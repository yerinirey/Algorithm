#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int N, M, K;
string row[51];
int ans = 0;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
			cin >> row[i];
	}
	cin >> K;
	for (int i = 0; i < N; i++) {
		// 같은 상태의 행의 개수를 찾는다.
		string cur = row[i];
		int cnt = 0; // 해당 행의 0 개수
		for (int j = 0; j < M; j++) if (cur[j] == '0')cnt++; 
		// 눌러야 하는 횟수보다 0이 많거나 누르는 횟수가 어긋나면 불가능
		if (cnt > K || cnt % 2 != K % 2) continue;
		int sameRows = 0;
		for (int j = 0; j < N; j++) if (cur == row[j]) sameRows++;
		ans = max(ans, sameRows);
	}
	
	cout << ans;
	return 0;
}