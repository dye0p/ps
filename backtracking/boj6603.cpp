//
// PS on 24. 4. 24, 오후 3:16.
//
#include <bits/stdc++.h>

using namespace std;

int k;
int num[14]; //입력배열 6<k<13
int arr[10]; //출력배열 최대6

void func(int len, int cur) {
    if (len == 6) { //수열의 길이가 6이 되면
        for (int i = 0; i < 6; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = cur; i < k; i++) {
        arr[len] = num[i];
        func(len + 1, i + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //입력
    while (1) {
        cin >> k;
        if (k == 0) break;

        for (int i = 0; i < k; i++) {
            cin >> num[i];
        }
        func(0, 0);
        cout << '\n';
    }
}