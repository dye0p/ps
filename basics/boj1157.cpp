#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    int num[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
        num[s[i] - 65]++;
    }

    int max = 0;
    int index = -1;
    for (int i = 0; i < 26; i++) {
        if (num[i] > max) {
            max = num[i];
            index = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (i == index) continue;
        if (num[i] == max) {
            cout << "?";
            return 0;
        }
    }

    cout << (char)(index + 65);
}