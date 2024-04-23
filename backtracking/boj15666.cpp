//
// PS on 24. 4. 23, 오후 3:32.
//
#include <bits/stdc++.h>

using namespace std;
int n, m, x;
vector<int> num;
int arr[10];

void func(int k, int st) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int tmp = 0; //중복 수열 체크 변수
    for (int i = st; i < n; i++) {
        if (tmp != num[i]) {
            arr[k] = num[i];
            tmp = arr[k];
            func(k + 1, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x;
        num.push_back(x);
    }
    sort(num.begin(), num.end());
    //정렬 확인

    func(0, 0 );
}