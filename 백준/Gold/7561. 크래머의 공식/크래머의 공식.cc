#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll B[3];
ll A[3][3];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout << fixed;
	cout.precision(3);
	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> A[i][j];
			}
			cin >> B[i];
		}
		ll dA[4] = {};
		ll tmpA[3][3] = {};
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				tmpA[i][j] = A[i][j];
			}
		}
		for (int i = 0; i < 3; i++) { // i번째에 해당하는 열을 모두 바꿔야 함.
			for (int j = 0; j < 3; j++) { 
				tmpA[j][i] = B[j];
			}
			dA[i] = tmpA[0][0] * (tmpA[1][1] * tmpA[2][2] - tmpA[1][2] * tmpA[2][1]) -
				tmpA[0][1] * (tmpA[1][0] * tmpA[2][2] - tmpA[1][2] * tmpA[2][0]) +
				tmpA[0][2] * (tmpA[1][0] * tmpA[2][1] - tmpA[1][1] * tmpA[2][0]);
			for (int j = 0; j < 3; j++) {
				tmpA[j][i] = A[j][i];
			}
		}
		dA[3] = A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
			A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
			A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
		for (int i = 0; i < 4; i++) {
			cout << dA[i] << ' ';
		}

		
		if (!dA[3]) {
			cout << "\nNo unique solution";
		}
		else {
			cout << "\nUnique solution: ";
			//double X[3] = {};
			for (int i = 0; i < 3; i++) {
				//X[i] = double(dA[i]) / double(dA[3]);
				double x = double(dA[i]) / double(dA[3]);
				if (x > -0.0005 && x < 0.0005) x = 0.000;
				cout << x << ' ';
			}
		}
		cout << "\n\n";
	}
}