#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        cin >> t;

        if (t == -1) break;

        vector<int> arr;
        int sum=0;

        for (int i = 1; i < t; i++) {
            if(t % i == 0) {
                arr.push_back(i);
                sum += i;
            }
            else continue;
        }

        if (sum != t) {
            cout << t << " is NOT perfect." << '\n';
        }
        else {
            cout << t << " = ";
            for (int i = 0; i < arr.size() -1 ; i++) {
                cout << arr[i] << " + ";
            }
            cout << arr[arr.size() - 1] << '\n';
        }
    }
}

