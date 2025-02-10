#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N >> K;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int eaten = 0, days = 0;
	for (int i = 1; i < N; i++) {
		if (v[i] > v[0]) {
			eaten += v[i] - v[0];
			days++;
		}
	}
	
	cout << eaten << ' ' << days;
	return 0;
	

}