#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) arr.push_back(i);
    }
    sort(arr.begin(), arr.end());

    if(arr.size() < k) cout << 0;
    else
        cout << arr[k-1];
}