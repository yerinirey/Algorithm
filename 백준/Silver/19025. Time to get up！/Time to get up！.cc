#include <iostream>
#include <algorithm>

using namespace std; 
char arr[7][21];
const string Nums[10] = {
    "123567","36","13457","13467","2346","12467","124567","136","1234567","123467"
};
const pair<int, int> pairs[7] = { {0,1}, {1,0}, {1,3}, {3,1}, {4,0}, {4,3}, {6,1} };
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T; cin >> T;
    while (T--) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 21; j++) {
                cin >> arr[i][j];
            }
        }
        string ans = "";
        int checkIdxs[4] = { 0, 5, 12, 17 };
        for (auto idx : checkIdxs) {
            string digit = "";
            for (int i = 0; i < 7; i++) { // i+1번째 숫자 확인
                if (arr[pairs[i].first][pairs[i].second + idx] == 'X') digit.push_back((i + 1) + '0');
            }
            for (int i = 0; i < 10; i++) {
                if (digit == Nums[i]) {
                    ans.push_back(i + '0');
                    break;
                }
            }
        }
        cout << ans[0] << ans[1] << ":" << ans[2] << ans[3] << "\n";
    }
    return 0;
}