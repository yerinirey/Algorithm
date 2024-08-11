#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;
string S;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	getline(cin, S);
	bool bracket = false; // 꺽쇠 내부 글자이면
	string word = "";
	for (int i = 0; i < S.size(); i++) {
		// 꺽쇠가 열려있다면
		if (bracket) {
			cout << S[i];
			// 닫힌 꺽쇠일 경우
			if (S[i] == '>') {
				bracket = false;
			}
		}
		// 열린 꺽쇠인 경우
		else if (S[i] == '<') {
			if (word != "") {
				reverse(word.begin(), word.end());
				cout << word;
				word = "";
			}
			cout << S[i];
			bracket = true;
			
		}
		else if (S[i] == ' ') {
			reverse(word.begin(), word.end());
			cout << word << ' ';
			word = "";
		}
		else {
			word.push_back(S[i]);
		}
	}
	if (word != "") {
		reverse(word.begin(), word.end());
		cout << word;
	}
	return 0;
}