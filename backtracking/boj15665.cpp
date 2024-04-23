//
// PS on 24. 4. 23, 오후 3:11.
//
#include <bits/stdc++.h>

using namespace std;
int n, m, x;
vector<int> num;
int arr[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int tmp = 0; //이전의 숫자를 담을 지역변수 설정
    for (int i = 0; i < n; i++) {
        if (tmp != num[i]) {
            arr[k] = num[i];
            tmp = arr[k];
            func(k + 1);
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

    func(0);
}