//
// PS on 2024/02/20, 7:54 PM.
//
#include <bits/stdc++.h>

using namespace std;

int n;
int cnt = 0;
bool isused1[30]; // | 의 갯수는 15개
bool isused2[30]; // / 대각선의 갯수는 29개
bool isused3[30]; // \ 대각선의 갯수는 29개

void func(int cur) {//cur번째 row에 말을 배칠할 예정
    if (cur == n) { //행의 끝까지 도달했다면
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) { //(cur, i)에 퀸을 놓을 예정
        //cur은 x축 i는 y축이라고 생각하자
        if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1]) {
            //이미 Q가 놓아져 있다면
            continue;
        }
        //놓아져있지 않다는건 놓을수 있다는 것
        //Q를 놓았다는 의미로 true로 변경
        isused1[i] = 1;
        isused2[cur + i] = 1;
        isused3[cur - i + n - 1] = 1;
        func(cur + 1); //다음 행 시작

        //재귀가 종료되면 원복
        isused1[i] = 0;
        isused2[cur + i] = 0;
        isused3[cur - i + n - 1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);
    cout << cnt;
}