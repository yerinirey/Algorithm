#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b, c, d;
	while (true) {
		cin >> a >> b;
		if (!a && !b) return 0;
		cout << a / b << " " << a % b << " / " << b << '\n';
	}
}