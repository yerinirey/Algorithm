#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int N, P, M; // 숫자 개수, 가격(0 ~ N - 1), 가진 돈
int arr[10];
int dp[51];
int idxWithZero, idxWithoutZero;
int minWithZero = 51; // 0을 포함하는 가장 싼 가격
int minWithoutZero = 51; // 0을 포함하지 않는 가장 싼 가격

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i && arr[i] <= minWithoutZero) {
			minWithoutZero = arr[i];
			idxWithoutZero = i;
		}
		if (arr[i] <= minWithZero) {
			minWithZero = arr[i];
			idxWithZero = i;
		}
	}

	cin >> M;
	if (M < minWithoutZero) { // 0을 제외한 수들 중 구매할 수 있는 번호가 없음
		cout << 0;
		return 0;
	}
    
	int idx = 0;
	dp[idx] = idxWithoutZero;
	M -= minWithoutZero;
	idx++;
	while (M >= minWithZero) {
		dp[idx] = idxWithZero;
		M -= minWithZero;
		idx++;
	}

	for (int i = 0; i < idx; i++) { // i번째 자리에 대해
		for (int j = N - 1; j > dp[i]; j--) {// 치환해볼 숫자 j를 의미
			if (M - arr[j] + arr[dp[i]] >= 0) {
				M = M - arr[j] + arr[dp[i]];
				dp[i] = j;
				break;
			}
		}
	}
	for (int i = 0; i < idx; i++) cout << dp[i];
	
}