#include <bits/stdc++.h>

using namespace std;

string s;
bool check; //false
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if(s[i] > s[s.length() - (i + 1)]) {
            check = false;
            break;
        }
        if (s[i] == s[s.length() - (i + 1)]) {
            check = true;
            continue;
        }
    }
    if(check) cout << 1;
    if(!check) cout << 0;
}