#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N;
	cin >> N;
	if (N % 2) cout << "SK";
	else cout << "CY";
	return 0;
}
