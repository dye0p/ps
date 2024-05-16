#include <bits/stdc++.h>

using namespace std;

string s;
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, s); //공백 포함 문자열 입력받기

    if (s.empty()) {
        cout << "0";
        return 0;
    }

    for (int i = 0; i < s.length(); i++) if (s[i] == ' ') cnt++;

    if (s[0] == ' ') cnt--;
    if (s[s.length() - 1] == ' ') cnt--;

    cout << cnt + 1;
}