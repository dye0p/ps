//
// 24. 5. 14, 오전 1:09.
//
#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
int arr[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
            reverse(arr + a-1, arr + b);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}