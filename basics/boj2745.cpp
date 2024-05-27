#include <bits/stdc++.h>

using namespace std;

string s;
int b, sum, cnt; //합계

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> b;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] >= '0' && s[i] <= '9')
            sum += (s[i] - 48) * pow(b, cnt);
        else
            sum += (s[i] - 65 + 10) * pow(b, cnt);

        cnt++;
    }
    cout << sum;
}