#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
int leftT = 210;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> K >> N;
	int a; char b;
	queue<pair<int, char>> q;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		q.push({ a, b });
	}
	int t = q.front().first;
	while (leftT - t > 0) {
		char opt = q.front().second;
		leftT -= t;
		if (opt == 'T') {
			K = K % 8 + 1;
		}
		pair<int, char> tmp = q.front();
		q.pop();
		q.push(tmp);
		t = q.front().first;
	}
	cout << K;
	return 0;
}