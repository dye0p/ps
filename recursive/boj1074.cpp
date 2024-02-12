//
// PS on 2024/02/06, 11:00 AM.
//
#include <bits/stdc++.h>

using namespace std;

int func(int n, int r, int c) {
    if (n == 0) return 0; //base condition

    int half = 1 << (n - 1);

    if (r < half && c < half) return func(n - 1, r, c); //1사분면
    if (r < half && c >= half) return half * half + func(n - 1, r, c - half); //2사분면
    if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);//3사분면
    //4사분면
    return (2 * half * half) + (half * half) + func(n - 1, r - half, c - half);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
}