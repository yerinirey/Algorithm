#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
double b, c, a1, a2;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> b >> c >> a1 >> a2;
	cout.precision(9);
	cout << (b + sqrt(b * b + 4 * c)) / 2;
}
