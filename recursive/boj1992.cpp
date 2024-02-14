//
// PS on 2024/02/14, 11:19 AM.
//
#include <bits/stdc++.h>

using namespace std;

int n;
int tree[70][70];

void solve(int x, int y, int n) {
    //base condition
    if (n == 1) {
        cout << tree[x][y];
        return;
    }

    bool one = true;
    bool zero = true;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (tree[i][j] == 1) {
                zero = false;
            } else {
                one = false;
            }
        }
    }
    if (zero) cout << 0;
    else if (one) cout << 1;
    else { //0과 1이 섞여있는경우
        cout << "(";
        solve(x, y, n / 2); //왼쪽 위
        solve(x, y + n / 2, n / 2); //오른쪽 위
        solve(x + n / 2, y, n / 2); //왼쪽 아래
        solve(x + n / 2, y + n / 2, n / 2); //왼쪽 아래
        cout << ")";
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            tree[i][j] = str[j] - '0';
        }
    }
    solve(0, 0, n); //시작점 0,0
}

