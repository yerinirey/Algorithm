#include <iostream>
#include <algorithm>
using namespace std; 
char opt[11][11];
int num[11];
int N;
bool found = false;
// idx번째 숫자부터 1번 숫자까지 역순으로 더할 때 해당하는 operator와 일치하는지
bool check(int idx) { 
    int s = 0;
    for (int i = idx; i >= 1; i--) { // 
        s += num[i];
        if (opt[i][idx] == '+' && s > 0) continue;
        if (opt[i][idx] == '-' && s < 0) continue;
        if (opt[i][idx] == '0' && s == 0) continue;
        return false;
    }
    return true;
}

void dfs(int idx) {
    if (idx == N + 1){ // N번까지 성공함
        for (int i = 1; i <= N; i++) {
            cout << num[i] << " ";
        }
        cout << "\n";
        found = true;
        return;
    }
    for (int i = -10; i <= 10; i++) {
        if (found) break;
        num[idx] = i;
        if (check(idx)) dfs(idx + 1); // 다음 숫자로 넘어가기
    }
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     cin >> N;
    for(int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) cin >> opt[i][j];
    }
    dfs(1);
    return 0;
}