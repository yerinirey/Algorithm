#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
#include <stack>
#include <queue>
ll n, k, t;
ll arr[200001];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k >> t;
	stack<long long> low; // 나보다 작은 상어 저장, front: 가장 큰 상어
	queue<long long> high; // 나보다 큰 상어 저장, front: 가장 작은 상어
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++) {
		if (arr[i] < t) low.push(arr[i]);
		else high.push(arr[i]);
	}

	for (int i = 0; i < k; i++) {
		if (low.empty()) break; // 더이상 먹을 상어가 없음
		t += low.top(); // 나보다 작은 상어들 중 가장 큰 상어 먹기
		low.pop();
		while (!high.empty() && t > high.front()) {
			low.push(high.front());
			high.pop();
		}
	}
	cout << t;
	return 0;
}
