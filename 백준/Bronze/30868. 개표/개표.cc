#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int a;  cin >> a;
        int five = a / 5;
        int one = a % 5;
        while (five--) cout << "++++ ";
        while (one--) cout << "|";
        cout << "\n";
    }
    return 0;
}