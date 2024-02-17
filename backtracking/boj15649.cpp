//
// PS on 2024/02/15, 2:54 PM.
//
#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
bool isused[10]; //기본 false로 초기화

void func(int k) { //k개까지 수를 선택 (k의 범위는 수열 한개의 크기)
    if (k == m) { //m개를 모두 선택
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!isused[i]) { //i가 사용되지 않았으면
            arr[k] = i; //k번째 수를 i로 정함
            isused[i] = 1; //i를 사용했다고 표시
            func(k + 1);
            isused[i] = 0; //한줄의 수열을 다 출력했다면 다시 수열을 구성해야 하니 i를 사용하지 않은걸로 변경
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}