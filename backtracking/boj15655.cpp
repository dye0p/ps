//
// PS on 2024/03/05, 1:04 PM.
//
#include <bits/stdc++.h>

using namespace std;
int n, m;
int num[10]; //입력 수열
int arr[10]; //출력 수열
bool used[10]; //default = false

void func(int k) { //k는 현재까지 선택한 후
    if (k == m) { //base Condition
        for (int i = 0; i < m; i++) {
            cout << num[arr[i]] << ' ';
        }
        cout << "\n";
        return;
    }
    int start = 0;
    if (k != 0) {
        start = arr[k - 1] + 1;
    }
    for (int i = start; i < n; i++) {
        if (!used[i]) { //사용되지 않음
            arr[k] = i;
            used[i] = 1; //사용표시
            func(k + 1);
            used[i] = 0; //원복
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> num[i];

    sort(num, num + n); //정렬
    func(0);
}