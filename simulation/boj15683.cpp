//
// PS on 24. 5. 1, 오후 8:08.
//
#include <bits/stdc++.h>

using namespace std;

int n, m;
int ret = 100;
int board[8][8];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int, int>> cctv;

void check(int x, int y, int dir) { //cctv의 x,y좌표, 현재방향(dir)
    dir %= 4;

    while (1) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        //벽을 만나거나  범위를 벗어난경우
        x = nx;
        y = ny;

        if (nx >= n || ny >= m || nx < 0 || ny < 0) return;
        if (board[nx][ny] == 6) return;
        //cctv를 만나면 그냥 통과
        if (board[nx][ny] != 0) continue;

        //감시 가능한 경우
        board[nx][ny] = 7;

    }
}

void solve(int pos) { //pos = 현재 선택된 카메라
    //cctv갯수와 현재 pos가 같다면 감시완료한것
    if (pos == cctv.size()) {
        //사각지대를 카운트하는 로직
        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) ++sum;
            }
        }
        ret = min(ret, sum);
        return;
    }

    //여기서부턴 감시를 해야함
    //감시 로직
    int x = cctv[pos].first; //현재 카메라의 x좌표
    int y = cctv[pos].second; //현재 카메라의 y좌표

    int backup[8][8]; //백업 배열

    for (int dir = 0; dir < 4; dir++) { //4방향 회전가능
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                backup[i][j] = board[i][j]; //백업
            }
        }
        if (board[x][y] == 1) { //1번 카메라 = 오른쪽
            check(x, y, dir + 2);
        } else if (board[x][y] == 2) { //2번 카메라 = 왼쪽,오른쪽
            check(x, y, dir);
            check(x, y, dir + 2);
        } else if (board[x][y] == 3) { //3번 카메라 = 위쪽,오른쪽
            check(x, y, dir + 1);
            check(x, y, dir + 2);
        } else if (board[x][y] == 4) { //4번 카메라 = 왼쪽,위쪽,오른쪽
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
        } else if (board[x][y] == 5) { //5번 카메라 = 왼쪽,위쪽,오른쪽,아래쪽
            check(x, y, dir);
            check(x, y, dir + 1);
            check(x, y, dir + 2);
            check(x, y, dir + 3);
        }

        solve(pos + 1); //다음 카메라를 검사하기 위해서 재귀호출

        //백업 원복
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = backup[i][j]; //백업
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            //cctv가 입력되면
            if (board[i][j] >= 1 && board[i][j] <= 5) {
                cctv.push_back({i, j});
            }
        }
    }

    solve(0);
    cout << ret;

}
