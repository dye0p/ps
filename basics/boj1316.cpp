//
// 24. 5. 24, 오후 4:00.
//
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    int cnt = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s;

        bool alphabet[26] = {false,};
        alphabet[s[0] - 97] = true; //s의 첫번째 문자 사용처리

        for (int j = 1; j < s.length(); j++) {
            //그룹단어가 아닌 조건
            if (alphabet[s[j] - 97] && s[j] != s[j - 1]) {
                cnt++;
                break;
            }
            //한번도 안나온 단어
            else if(!alphabet[s[j] - 97]) alphabet[s[j] - 97] = true;
        }
    }
    cout << n-cnt;
}