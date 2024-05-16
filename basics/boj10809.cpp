//
// 24. 5. 16, 오후 11:48.
//
#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    int arr[26];

    for (int i = 0; i < 26; i++) arr[i] = -1;

    for (int i = 0; i < s.length(); i++) {
        if (arr[s[i] - 97] > -1) continue;
        else if (arr[s[i] - 97] <= -1) arr[s[i] - 97] = i;
    }

    for (int i = 0; i < 26; i++) cout << arr[i] << ' ';

}