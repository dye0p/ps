//
// PS on 24. 4. 19, 오전 10:24.
//
#include <bits/stdc++.h>

using namespace std;
int n, m, x;
vector<int> num;
int arr[10];

void func(int k, int st) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = st; i < n; i++) {
        arr[k] = num[i];
        func(k + 1, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x;
        num.push_back(x);
    }

    sort(num.begin(), num.end());

    func(0, 0);
}