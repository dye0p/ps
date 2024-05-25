#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[101][101];
int b[101][101];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            cin >> a[j][k];
        }
    }
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            cin >> b[j][k];
        }
    }

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            cout << a[j][k] + b[j][k] << ' ';
        }
        cout << '\n';
    }

}
