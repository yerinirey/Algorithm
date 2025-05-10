#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N;
string input;
int dp[21];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	cin >> input;

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 20; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	// 연속된 long들 찾기
	vector<int> v; // long의 인덱스 저장, idx1 + 4 == idx2라면 연속되었을 것임.

	while (1) {
		int idx = input.find("long");
		if (idx != string::npos) {
			v.push_back(idx);
			input.replace(idx, 4, "XXXX");
		}
		else break;
	}
	int res = 1;

	int size = v.size();
	int i = 0;

	while (i < size) {
		int cnt = 1;
		while (i + 1 < size && v[i] + 4 == v[i + 1]) {
			cnt++;
			i++;
		}
		res *= dp[cnt];
		i++;
	}

	cout << res;

	return 0;
}
