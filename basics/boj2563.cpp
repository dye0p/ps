#include <bits/stdc++.h>

using namespace std;

int n, x, y, cnt;
int board[102][102];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--) {

        cin >> x >> y;

        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                board[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if(board[i][j] == 1) cnt++;
        }
    }

    cout << cnt;
}
