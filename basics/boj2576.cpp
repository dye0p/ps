//
// PS on 24. 5. 2, 오후 3:28.
//
#include <bits/stdc++.h>

using namespace std;

int sum = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tmp = 100;

    for (int i = 0; i < 7; i++) {
        int x;
        cin >> x;

        if (x % 2 != 0) { //홀수라면
            sum += x;
            if (tmp > x) {
                tmp = x;
            }
        }
    }
    if (tmp == 100 && sum == 0) {
        cout << -1;
    }
    else
        cout << sum << '\n' << tmp;
}