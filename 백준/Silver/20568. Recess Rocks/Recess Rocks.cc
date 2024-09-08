#include <iostream>
#include <algorithm>
using namespace std;
int ans;
int N, *arr;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> N;
    arr = new int[N];
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    int mx = arr[0];
    for (int i = 1; i < N; i++) {
        if (mx >= arr[i]) ans++;
        else mx = arr[i];
    }
    cout << ans;
    return 0;
}
