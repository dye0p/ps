//
// PS on 2024/02/23, 7:51 PM.
//
#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10]; //길이가 M인 수열을 담을 배열
bool isused[10]; //기본 false로 초기화

void func(int k) { //k의 범위는 m까지
    //base Condition
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int start = 1;
    if(k!=0) {
        start = arr[k-1] + 1;
    }
    for (int i = start; i <= n; i++) {
        if (isused[i] != 1) {
            arr[k] = i; //k번째 위치에 i를 추가
            isused[i] = 1; //해당 숫자 사용완료(중복 방지)
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}