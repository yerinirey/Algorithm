#include <iostream>

using namespace std;
int lcs[1001][1001];
string a, b;
int main() {
    cin >> a >> b;
    int len_a = a.size();
    int len_b = b.size();

    for (int i = 1; i <= len_a; i++) {
        for (int j = 1; j <= len_b; j++) {
            if (a[i - 1] == b[j - 1]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    cout << lcs[len_a][len_b];
    return 0;
}
