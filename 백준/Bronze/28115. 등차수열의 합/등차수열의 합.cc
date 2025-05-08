#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//1. A가 등차수열인지 검증
	//2. 등차수열이면 어떠한 방법으로든 가능함 > A = B, C = 0

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	if (N == 1) {
		cout << "YES\n" << arr[0] << "\n0";
		return 0;
	}

	int compare = arr[1] - arr[0];

	for (int i = 1; i < N; i++) {
		if (compare != arr[i] - arr[i - 1]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < N; i++) {
		cout << arr[i] << ' ';
	}
	cout << "\n";
	for (int i = 0; i < N; i++) {
		cout << 0 << ' ';
	}
	return 0;
}