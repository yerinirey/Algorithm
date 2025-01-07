#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXNUM 1000001
using namespace std;

bool prime[MAXNUM];
int n, m, x;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	for (int i = 2; i < MAXNUM; i++) prime[i] = true;

	for (int i = 2; i <= sqrt(MAXNUM); i++) {
		if (prime[i]) {
			for (int j = 2; i * j < MAXNUM; j++) {
				prime[i * j] = false;
			}
		}
	}
	int n;
	while(true) {
		cin >> n;
		if (!n) return 0;
		int a = 3;
		int b = n - 3;
		while (a <= b) {
			if (!prime[a] || !prime[b]) {
				a += 2; b -= 2;
			}
			else {
				cout << n << " = " << a << " + " << b << '\n';
				break;
			}
		}
		if(a > b) cout << "Goldbach's conjecture is wrong.\n";
	}
}