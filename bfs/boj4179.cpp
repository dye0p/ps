//
// Created by DongYeop on 2024/01/26.
//
#include <bits/stdc++.h>

using namespace std;

int r, c; //행,열
string board[1001];
int distf[1001][1001]; //불의 dist
int distj[1001][1001]; //지훈의 dist

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

queue<pair<int, int>> qf; //불의 q
queue<pair<int, int>> qj; //지훈의 q


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //입력 문제 없음
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }

    //배열 초기화 문제 없음
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            distf[i][j] = -1; //distf 배열 초기화
            distj[i][j] = -1; //distj 배열 초기화
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'F') { //불이 발견되면
                qf.push({i, j});
                distf[i][j] = 0; //방문처리
            }
            if (board[i][j] == 'J') { //지훈이 발견되면
                qj.push({i, j});
                distj[i][j] = 0; //방문처리
            }
        }
    }

    //불은 좌표에서 1개 이상이 있을수가 있기때문에 스택에 불을 모두 추가하고 bfs를 실행
    //불 bfs 문제 없음
    while (!qf.empty()) {
        int x = qf.front().first;
        int y = qf.front().second;
        qf.pop();

        //인접위치 탐색
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            //이동하지 못하는 조건
            //범위를 벗어난 경우
            if (nx < 0 || nx >= r) continue;
            if (ny < 0 || ny >= c) continue;
            //이미 한번 방문한 곳이거나, 벽이거나
            if (distf[nx][ny] != -1 || board[nx][ny] == '#') continue;

            qf.push({nx, ny});
            distf[nx][ny] = distf[x][y] + 1;
        }
    }

    //지훈 bfs
    while (!qj.empty()) {
        int x = qj.front().first;
        int y = qj.front().second;
        qj.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            //지훈이가 탈출 가능한 경우
            //범위를 넘어선 경우
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
                cout << distj[x][y] + 1;
                return 0;
            }
            //지훈이가 이동 할 수 없는 경우
            //벽이 있거나, dirtj지훈이가 이미 방문한 칸은 제외
            if(board[nx][ny] == '#' || distj[nx][ny] != -1) continue;
            //불의 이동속도보다 지훈이의 이동속도가 더 크다면, 불이 이미 방문을 했다면
            if(distj[x][y] + 1 >= distf[nx][ny] && distf[nx][ny] != -1) continue;

            //지훈이가 이동할 수 있음
            qj.push({nx, ny});
            distj[nx][ny] = distj[x][y] + 1;
        }
    }
    cout << "IMPOSSIBLE";

// 값 확인용 출력문
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < c; j++) {
//            cout << distj[i][j] << " ";
//        }
//        cout << "\n";
//    }
}

