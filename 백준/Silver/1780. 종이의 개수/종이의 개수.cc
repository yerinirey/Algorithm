#include <iostream>
#include <algorithm>
using namespace std;
int N, map[2200][2200];
int cnt[3]; // 0: -1, 1: 0, 2: 1;
bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (map[x][y] != map[i][j]) return false;
		}
	}
	return true;
}

void recursive(int x, int y, int size) {
	if (check(x, y, size)) {
		cnt[map[x][y] + 1]++;
		return;
	}
	int nSize = size / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			recursive(x + i * nSize, y + j * nSize, nSize);
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	recursive(0, 0, N);
	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << "\n";
	}
}


/*
N=9			9x9 크기로 나눠짐
만약 종이를 잘라야 한다면 N/3이 한 변의 크기가 됨

*/