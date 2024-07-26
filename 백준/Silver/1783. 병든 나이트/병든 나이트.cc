#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int N, M;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	if (N == 1) cout << 1;
	else if (N == 2) cout << min(4, (M + 1) / 2);
	else {
		if (M <= 6) cout << min(4, M);
		// M이 7 이상일 때
		// M - 4번째 칸까지 지그재그로 채우고
		// 남은 4개의 칸에 대해 한 칸 건너 채우는 식으로 두 곳을 방문 가능 
		else cout << M - 2;
	}
	return 0;
}
