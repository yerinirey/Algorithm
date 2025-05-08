#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;
#include <string>
#include <vector>

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int p[3], y[3];
	string s[3]; // p문제수 y입학년도 s성씨

	int case1[3];

	for (int i = 0; i < 3; i++) {
		cin >> p[i] >> y[i] >> s[i];
		case1[i] = y[i] % 100;
	}
	// case 1:  입학년도 % 100 > 오름차순 정렬 + 이어붙임
	sort(case1, case1 + 3);
	string res1 = "";
	for (int i = 0; i < 3; i++) {
		res1 += to_string(case1[i]);
	}
	cout << res1 << '\n';

	// case 2: 성씨 영문표기 > 첫 글자를 BOJ에서 해결한 문제가 많은 사람부터 나열
	vector<pair<int, char>> v;
	for (int i = 0; i < 3; i++) {
		v.push_back({ p[i], s[i][0] });
	}
	sort(v.rbegin(), v.rend() );

	string res2 = "";
	for (int i = 0; i < 3; i++) {
		res2 += v[i].second;
	}
	cout << res2;
	return 0;
}