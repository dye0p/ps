//
// PS on 2024/03/04, 8:17 PM.
//
#include <bits/stdc++.h>

using namespace std;

int n, m;
int num[10];
int arr[10];
bool used[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            arr[k] = num[i];
            used[i] = 1;
            func(k + 1);
            used[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n); //정렬
    func(0);
}