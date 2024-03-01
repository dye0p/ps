//
// PS on 2024/02/23, 7:51 PM.
//
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        a.push_back(i < m ? 0 : 1);
    }

    do {
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                cout << i + 1 << ' ';
            }
        }
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));

}