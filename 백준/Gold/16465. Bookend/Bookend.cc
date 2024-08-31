#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int N, M, L; // 책 개수, 책장 너비, 북엔드 너비
int total;
int ans;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> L;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		total += a;
	}
	if (total > M) cout << -1;
	else if (total == M) {
		cout << 0;
	}
	// 공간이 남을 때
	else { 
		if (L > M) cout << -1;
		// 북엔드가 total보다 좁을 때
		else if (total >= L) cout << 1;
		
		else {
			// 북엔드가 total보다 넓을 때 북엔드 반대로 놓기
			if (L + total <= M) cout << 1;
			else cout << -1;
		}
	}
	return 0;
}
