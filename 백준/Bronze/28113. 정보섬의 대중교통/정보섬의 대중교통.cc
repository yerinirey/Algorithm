#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, A, B;
	cin >> N >> A >> B;
	// N: 숭입~승강장 걸어가기	A: 버스		B: 열차
	int res;
	if (N <= B) {
		res = A - B; // 양수면 열차
		if (res > 0) cout << "Subway";
		else if (res == 0) cout << "Anything";
		else cout << "Bus";
	}
	else cout << "Bus";
	return 0;
}