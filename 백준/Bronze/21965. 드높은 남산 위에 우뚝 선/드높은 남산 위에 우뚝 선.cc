#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int arr[100001];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;  cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 1; i < N - 1; i++) {
		if (arr[i - 1] == arr[i] || arr[i] == arr[i + 1]) {
			cout << "NO";
			return 0;
		}
		if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}