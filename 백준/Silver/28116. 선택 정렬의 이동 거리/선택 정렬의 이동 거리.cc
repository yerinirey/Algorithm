#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
int value[500001]; // idx번째에 위치한 수
int pos[500001]; // 수가 위치한 idx 저장
int cnt[500001];
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// 선택정렬 수행 시 1 ~ N 의 수가 얼만큼씩 이동하는지 계산하라
	// 선택정렬 > 2차원 / 시간제한 5초

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> value[i];
		pos[value[i]] = i; 
	}

	for (int i = 0; i < N - 1; i++) {
		int tarNum = i + 1; // 이번에 구할 최솟값
		int j = pos[tarNum]; // tarNum은 j 인덱스에 위치중, 즉 j번째와 i번째 교환이 이루어져야 함
		if (j == i) continue;
		
		int iNum = value[i];

		value[i] = tarNum;
		value[j] = iNum;
		pos[tarNum] = i;
		pos[iNum] = j;
		
		int dist = j - i;
		cnt[tarNum - 1] += dist;
		cnt[iNum - 1] += dist;
	}

	for (int i = 0; i < N; i++) cout << cnt[i] << ' ';

	return 0;
}