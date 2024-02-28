//
// PS on 2024/02/28, 2:30 PM.
//
#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
bool used[10];

void func(int k) {
    if (k == m) { //base Condition
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int start = 1;
    if (k != 0) {
        start = arr[k - 1];
    }
    for (int i = start; i <= n; i++) {//해당 숫자가 사용되지 않았으면
        arr[k] = i;
        func(k + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);

}