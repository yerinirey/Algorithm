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
		int a1 = stoi(S.substr(0, len1));
		if (S[len1] == '0') continue;
		for (int len2 = len1; len2 <= strlen / 2; len2++) {
			if (len1 + len2 >= strlen || len2 > 9) break;
			int a2 = stoi(S.substr(len1, len2));
			int d = a2 - a1;
			if (d <= 0) continue;

			bool possible = true;
			int cur = a2;
			int curidx = len1 + len2;
			vector<int> tmpV = { a1, a2 };

			while (curidx < strlen) {
				int nxt_a = cur + d;
				string nxt_a_s = to_string(nxt_a);
				if (S.find(nxt_a_s, curidx) != curidx) break;
				curidx += nxt_a_s.size();
				cur = nxt_a;
				tmpV.push_back(cur);
			}
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
