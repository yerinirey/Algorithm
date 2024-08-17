#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define ll long long
using namespace std;
string S;
int ans = 1e9;
void find_arr() {
	int strlen = S.size();
	for (int len1 = 1; len1 <= strlen / 3; len1++) {
		
		if (len1 > strlen || len1 > 9) break;
		int a1 = stoi(S.substr(0, len1)); // 0인덱스부터 len1길이만큼 잘라냄
		//cout << "a1: " << a1 << "\n";
		if (S[len1] == '0') continue; // a2항 첫 글자가 '0'이면 불가능한 경우의 수열임
		// len2: a2의 길이
		for (int len2 = len1; len2 <= strlen / 2; len2++) {
			if (len1 + len2 >= strlen || len2 > 9) break;
			int a2 = stoi(S.substr(len1, len2));
			//cout << "a2: " << a2 << "\n";
			int d = a2 - a1; // 공차
			if (d <= 0) continue;

			bool possible = true;
			int cur = a2; // 지금까지 구한 마지막 항
			int curidx = len1 + len2; // a2끝자리 인덱스
			vector<int> tmpV = { a1, a2 };

			while (curidx < strlen) {
				int nxt_a = cur + d; // 다음항의 크기
				string nxt_a_s = to_string(nxt_a);
				//cout << "nxt_a_s:" << nxt_a_s << "\n";
				//cout << S[curidx] << "\n";
				if (S.find(nxt_a_s, curidx) != curidx) break;
				curidx += nxt_a_s.size();
				cur = nxt_a;
				tmpV.push_back(cur);
			}
			// 남은 문자열(left) 추가
			if (curidx < strlen) {
				string left = S.substr(curidx);
				if (S.substr(curidx)[0] == '0') {
					left = to_string(tmpV.back()) + left;
					tmpV.pop_back();
				}
				if (left.size() > 9) continue;
				tmpV.push_back(stoi(left));
			}
			while (tmpV.size() >= 3) {
				//for (auto c : tmpV) {
				//	cout << c << " ";
				//}
				//cout << "\n\n";
				int size = tmpV.size();
				ll a_last = tmpV[size - 1];
				ll div = tmpV[size - 2];
				int f = a_last / div;
				if (a_last < 1e9 && f >= 2 && f * div == a_last) ans = min(ans, f);
				if(tmpV.size() >= 2) for (int i = 0; i < 2; i++) tmpV.pop_back();
				string a_new = to_string(div) + to_string(a_last);
				if (a_new.size() > 9) break;
				tmpV.push_back(stoi(a_new));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> S;
	find_arr();
	if (ans == 1e9) ans = 0;
	cout << ans;
}

/*
	1. 첫 항의 길이를 1부터 늘려가면서 체크하기(항의 자릿수는 str / 3을 넘을 수 없음)
	1-1. 두 번째 항의 길이를 첫 항의 길이부터 늘려가면서 체크하기
		 공차가 양의 정수이기 때문에 첫 항보다 작아질 수 없기 때문
	2. 2번째 항까지 체크를 하고, 공차를 확인한 후 가능한 수열인지 확인
*/