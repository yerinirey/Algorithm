#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;
vector<int> v;
int N, A, B, C, D;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	cin >> A >> B; // 도우, 토핑 가격
	cin >> C; // 도우 열량
	for (int i = 0; i < N; i++) {
		cin >> D;
		v.push_back(D);
	}
	sort(v.begin(), v.end());
	
	while (!v.empty()) {
		int cur = C / A;
		int tar = v[v.size() - 1]; // 고려할 토핑
		int nxtAns = (C + tar) / (A + B);
		if (nxtAns >= cur) {
			C += tar;
			A += B;
			v.pop_back();
		}
		else break;
	}
	cout << C / A;
}
