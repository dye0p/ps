//
// 24. 5. 29, 오후 2:57.
//
#include <bits/stdc++.h>

using namespace std;

string board[4];
int k;

//선택한 톱니바퀴(n)와 회전 방향(r)을 받아서 회전시키는 함수
void rot(int n, int r) {
    //회전함수에서 해야할 것
    int idx = n; //회전 시킬 톱니바퀴
    int dir[4] = {}; //회전 방향 초기화
    dir[idx] = r; //톱니바퀴의 회전 방향 설정

    //맞닿은 극 비교
    //맞닿은 극이 같다면 회전 x
    //맞닿은 극이 다르다면 옆 톱니바퀴가 반대로 회전 해야함
    while (idx > 0 && board[idx][6] != board[idx - 1][2]) {
        dir[idx - 1] = -dir[idx];
        idx--;
    }

    idx = n;
    while (idx < 3 && board[idx][2] != board[idx + 1][6]) {
        dir[idx + 1] = -dir[idx];
        idx++;
    }
    //회전
    for (int i = 0; i < 4; i++) {
        if (dir[i] == 1) { //반시계 방향
            rotate(board[i].begin(), board[i].begin() + 7, board[i].end());
        } else if (dir[i] == -1) {
            rotate(board[i].begin(), board[i].begin() + 1, board[i].end());
        }
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //톱니바퀴 설정
    for (int i = 0; i < 4; i++) {
        cin >> board[i];  //톱니바퀴 1~4
    }
    //회전 횟수 입력
    cin >> k;

    //회전 횟수만큼 반복
    while (k--) {
        int n, r;
        //회전 시킬 톱니바퀴와 어느방향으로 회전할지 입력
        cin >> n >> r;

        //해당 톱니바퀴를 회전
        rot(n - 1, r);
    }

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (board[i][0] == '1') {
            if (i == 0) ans += 1;
            else if (i == 1) ans += 2;
            else if (i == 2) ans += 4;
            else if (i == 3) ans += 8;
        }
    }
    cout << ans;
}