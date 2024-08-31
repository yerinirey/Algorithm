#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
vector<int> v;
int arr[200001];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N;  cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	v.push_back(arr[0]);
	for (int i = 1; i < N; i++) {
		auto idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
		if (idx < v.size()) v[idx] = arr[i];
		else v.push_back(arr[i]);
	}
	cout << N - v.size();
	return 0;
}
