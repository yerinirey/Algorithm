#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
//R L B T RT LT RB LB
string moves[8] = { "R","L","B","T","RT","LT","RB","LB" };
int dx[8] = { 0, 0, 1, -1,-1, -1, 1, 1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string a, b; int t;
	cin >> a >> b >> t;
	pair<int, int> from = { '8' - a[1], a[0] - 'A' };
	pair<int, int> to = { '8' - b[1], b[0] - 'A' };
	while (t--) {
		string opt;
		cin >> opt;
		for (int i = 0; i < 8; i++) {
			if (opt == moves[i]) {
				int nx = from.first + dx[i];
				int ny = from.second + dy[i];
				// 킹이 범위를 벗어나는 경우
				if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
				// 이동한 위치가 돌의 위치인 경우
				if (nx == to.first && ny == to.second) {
					int rx = to.first + dx[i];
					int ry = to.second + dy[i];
					// 돌이 범위를 벗어나는 경우
					if (rx < 0 || ry < 0 || rx >= 8 || ry >= 8) continue;
					to = { rx, ry };
					from = { nx, ny };
				}
				else {
					from = { nx, ny };
				}

			}
		}
	}
	cout << char(from.second + 'A') << 8 -from.first << "\n";
	cout << char(to.second + 'A') << 8 - to.first;
	//0,0 ~ 7x7로 변환
	return 0;
}
