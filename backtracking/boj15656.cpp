//
// PS on 24. 4. 16, 오전 3:02.
//
#include <bits/stdc++.h>

using namespace std;

int n, m, x;
int arr[10];
vector<int> num;

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        arr[k] = num[i];
        func(k + 1);
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

    func(0);

}