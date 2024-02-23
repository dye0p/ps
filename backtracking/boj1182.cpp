//
// PS on 2024/02/21, 8:50 PM.
//
#include <bits/stdc++.h>

using namespace std;
int n, s;
int arr[30];
int cnt = 0;

void func(int cur, int sum) {
    //base condition
    if (cur == n) { //현재 상태의 위치가 n까지 갔을때
        if (sum == s) { //현재 상태의 위치가 n일때, 합계가 s와 동일하다면
            cnt++; //경우의 수 +1
        }
        return; //함수 종료
    }
    func(cur + 1, sum); //수열의 값을 더하지 않는 상황
    func(cur + 1, sum + arr[cur]); //더하는 상황
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    func(0, 0);
    //공집합인경우 -1 :: 부분집합의크기는 1이상이라고 했기 때문
    if (s == 0) cnt--;
    cout << cnt;
}