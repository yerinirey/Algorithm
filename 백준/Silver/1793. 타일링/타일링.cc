#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int N;
string dp[251] = { "1", "1", "3" }; // 0, 1, 2
int maxNum = 2; // 입력이 여러 줄이므로 저장해둬야 함

void solve(int cur, int tar) {
	for (int i = cur; i <= tar; i++) {
		string a = dp[i - 1];
		string b = dp[i - 2];
		string result = "";
		int addNum = 0; // 문자열로 덧셈을 접근해서 올림수를 저장하는 변수
		while (!a.empty() || !b.empty() || addNum) {
			if (a != "") {
				addNum += a.back() - '0';
				a.pop_back();
			}
			if (b != "") {
				addNum += (b.back() - '0') * 2;
				b.pop_back();
			}
			result.push_back(addNum % 10 + '0');
			addNum /= 10;
		}
		reverse(result.begin(), result.end());
		dp[i] = result;
	}
}



int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> N) {
		if (maxNum < N) {
			solve(maxNum, N);
			maxNum = N;
		}
		cout << dp[N] << "\n";
	}
	return 0;
}
