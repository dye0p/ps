//
// PS on 24. 5. 2, 오후 3:13.
//
#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; i++) {

        int num[10];
        int zero = 0;
        int one = 0;

        for (int j = 0; j < 4; j++) {
            cin >> num[j];

            if (num[j] == 0)zero++;
            else if (num[j] == 1)one++;
        }
        if (zero == 1 && one == 3) cout << 'A';
        else if (zero == 2 && one == 2) cout << 'B';
        else if (zero == 3 && one == 1) cout << 'C';
        else if (zero == 4 && one == 0) cout << 'D';
        else if (zero == 0 && one == 4) cout << 'E';

        cout << '\n';
    }

}
