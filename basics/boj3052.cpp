//
// PS on 24. 5. 14, 오전 12:49.
//
#include <bits/stdc++.h>

using namespace std;

int n;
int arr[42];
int cnt;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; i++) {
        cin >> n;
        arr[n % 42] = 1;
    }

    for (int i = 0; i < 42; i++) {
        if(arr[i]) ++cnt;
    }
    cout << cnt;


}