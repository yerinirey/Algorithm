#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std; 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int B, N;
    while (true) {
        cin >> B >> N;
        if (!B && !N) return 0;
        int A = pow(B, 1.0 / N);
        if (abs(pow(A, N) - B) > abs(pow(A + 1, N) - B)) A++;
        cout << A << "\n";
    }
}

/* B, N 입력시 B에 가장 가까운 A^N */