#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
int N;
int star[5][5] = {
    {0,0,1,0,0},
    {0,0,1,0,0},
    {1,1,1,1,1},
    {0,1,1,1,0},
    {0,1,0,1,0}
};

bool solve(int x, int y, int size) {
    int nx = (x / size) % 5;
    int ny = (y / size) % 5;
    if (size == 1) return star[nx][ny];
    if (star[nx][ny]) {
        return solve(x, y, size / 5);
    }
    return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    if (N == 0) {
        cout << "*";
        return 0;
    }
    int size = pow(5, N);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (solve(i, j, size / 5)) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}
 