//
// PS on 2024/02/13, 11:49 AM.
//
#include <bits/stdc++.h>

using namespace std;

int n;
int board[2200][2200];
int cnt[3]; // 종이의 개수 (-1, 0, 1) 카운트

//모두 같은 숫자인지 판단
bool check(int x, int y, int n) {
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (board[x][y] != board[i][j]) //모든숫자가 같지않다면
                return false;
        }
    }
    return true; //모두 같다면 true
}

void solve(int x, int y, int z) {
    if (check(x, y, z)) { //모두 같은숫자 라면
        cnt[board[x][y] + 1]++;
        return;
    }

    //숫자가 다른경우
    int n = z / 3;

    //행열의 길이가 3인 종이로 쪼갬 -> 재귀호출
    //하나로 뭉쳐져 있는것을 9개로 조각냈기 때문에
    //3x3행렬이 3행 3열에 각 행렬마다 존재한다.
    //각 종이의 첫번째 인자(제일 왼쪽)를 기준으로 비교한다.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            solve(x + i * n, y + j * n, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    solve(0, 0, n);

    for (int i = 0; i < 3; i++) {
        cout << cnt[i] << "\n";
    }
}