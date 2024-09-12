#include <iostream>
#include <map>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    map<int, int> m;
    cin >> N;
    while (N--) {
        int g, r;
        cin >> g >> r;
        m.insert({ r, g });
    }
    cout << m.size();
    return 0;
}
