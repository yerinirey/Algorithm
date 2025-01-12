#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, K, c;
vector<pair<int, int>> v;

bool compare(pair<int,int> i, pair<int, int> j) {
	return j.first < i.first;
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		cin >> c;
		v.push_back({ c, i });
	}
	sort(v.begin(), v.end(), compare);

	int cnt = 0;
	int idx = 0;
	int* ans = new int[N];

	while (cnt < N) {
		for (int i = 0; i < v.size(); i++) {
			int curCnt = v[i].first;
			int curNum = v[i].second;
			while (curCnt--) {
				ans[idx] = curNum;
				cnt++;
				idx += 2;
				if (idx >= N) {
					idx = 1;
				}

			}
		}
	}
	if (N > 1 && ans[0] == ans[1]) {
		cout << -1;
		return 0;
	}
	else {
		for (int i = 0; i < N; i++) {
			cout << ans[i] << " ";
		}
	}	

}