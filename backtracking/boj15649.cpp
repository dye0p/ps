//
// PS on 2024/02/15, 2:54 PM.
//
#include <bits/stdc++.h>

using namespace std;
int n, m;
int arr[10];
bool checked[10]; //기본 false

void func(int k) {
    //수열의 길이가 M이 되었다면 출력
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }


    //수열 구하기
    for (int i = 1; i <= n; i++) { // 1~n까지 반복
        if (!checked[i]) { //참이라면(i에 해당하는 checked인덱스 값이 false라면)
            checked[i] = true; // true로 변경하는것은 사용한다는 의미
            arr[k] = i; //arr의 수열에 i 추가
            func(k + 1); //다음 반복
            checked[i] = false;
        }
    }
} //func 함수는 자신을 호출한 함수로 다시 돌아간다

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; // n, m 입력 받기

    func(0);
}