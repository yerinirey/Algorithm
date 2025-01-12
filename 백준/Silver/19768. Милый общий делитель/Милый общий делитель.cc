#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int a, b, n;

int gcd(int x, int y) {
	while (y != 0) {
		n = x % y;
		x = y;
		y = n;
	}
	return x;
}

vector<int> divisors(int g) {
	vector<int> v;
	for (int i = 1; i <= sqrt(g) + 1; i++) {
		if (!(g % i)) {
			v.push_back(i);
			if (i != g / i) {
				v.push_back(g / i);
			}
		}
	}
	return v;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> a >> b;
	if (a < b) {
		int tmp = b;
		b = a;
		a = tmp;
	}
	int g = gcd(a, b);
	vector<int> v = divisors(g);
	int size = v.size();
	int cnt = 0, num = 0;
	for (int i = 0; i < size; i++) {
		int cur = v[i];
		int sum = 0;
		while (cur > 0) {
			sum += cur % 10;
			cur /= 10;
		}

		if (sum > cnt || (sum == cnt && v[i] > num)) {
			cnt = sum;
			num = v[i];
		}
	}
	cout << num;
}