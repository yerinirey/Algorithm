#include <iostream>
#include <algorithm>
using namespace std; 
int a, b, c, d;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> a >> b >> c;
    if (c % 2) d = a ^ b;
    else d = a;
    cout << d;
    return 0;
}