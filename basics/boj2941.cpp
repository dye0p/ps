#include <bits/stdc++.h>

using namespace std;

string s;
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    cnt = s.length();

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '=') {
            if (s[i - 1] == 'c' || s[i - 1] == 's' || s[i - 1] == 'z') cnt--;
            if (s[i - 1] == 'z') {
                if (s[i - 2] == 'd') cnt--;
            }
        }
        if (s[i] == '-') {
            if (s[i - 1] == 'c' || s[i - 1] == 'd') cnt--;
        }
        if (s[i] == 'j') {
            if (s[i - 1] == 'l' || s[i - 1] == 'n') cnt--;
        }
    }
    cout << cnt;
}
