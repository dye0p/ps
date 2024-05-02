//
// PS on 24. 5. 2, 오후 2:21.
//
#include <bits/stdc++.h>

using namespace std;

int a, b, x;
int cnt;
vector<int> num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> x;

    for (int i = 0; i < a; i++) {
        cin >> b; //수열 입력

        if (b < x) {
            num.push_back(b);
            cnt++;
        }
    }

    for (int i = 0; i < cnt; i++) {
        cout << num[i] << ' ';
    }
}