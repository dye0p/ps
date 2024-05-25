#include <bits/stdc++.h>

using namespace std;

int arr[10][10];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tmp = 0;
    int r, c = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (tmp < arr[i][j]) {
                tmp = arr[i][j];
                r = i;
                c = j;
            }
            else if(tmp == arr[i][j]) {
                r = i;
                c = j;
            }
        }
    }

    cout << tmp << '\n' << r + 1 << ' ' << c + 1;
}
