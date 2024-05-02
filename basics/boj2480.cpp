//
// PS on 24. 5. 2, 오후 2:47.
//
#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    //모두 같은 눈
    if (a == b && b == c) {
        cout << 10000 + (a * 1000);
    }

    else if (a == b || a == c)
        cout << 1000 + (a * 100);
    else if (b == c)
        cout << 1000 + (b * 100);

    else
        cout << max({a, b, c,}) * 100;
}