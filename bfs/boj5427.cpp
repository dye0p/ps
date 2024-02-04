//
// BOJ on 2024/02/02, 8:41 PM.
//
#include <bits/stdc++.h>

using namespace std;

int t;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) { //테스트케이스 반복
        int w, h;
        bool possible = true; //탈출 가능 여부
        cin >> w >> h;

        //입력 문제 없음
        string board[1002]; //board배열 초기화
        for (int i = 0; i < h; i++) {
            cin >> board[i];
        }

        //배열 초기화 문제 없음
        //탈출시간 배열 초기화, 배열값이 -1이라면 방문하지 않을것, -1이상이라면 방문했던것
        int dist1[1002][1002] = {0,}; //불 dist
        int dist2[1002][1002] = {0,}; //상근 dist
        //dist1,2배열 -1로 초기화
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dist1[i][j] = -1;
                dist2[i][j] = -1;
            }
        }

        //큐에 시작점 삽입
        queue<pair<int, int> > q1; //불큐 초기화
        queue<pair<int, int> > q2; //상근큐 초기화
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '*') { //불
                    q1.push({i, j}); //불위치 푸시
                    dist1[i][j] = 0;
                }
                if (board[i][j] == '@') { //상근
                    q2.push({i, j}); //상근위치 푸시
                    dist2[i][j] = 0;
                }
            }
        }
        //불 bfs
        while (!q1.empty()) {
            int x, y;
            tie(x, y) = q1.front();
            q1.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                //이동못하는 조건
                //범위를 벗어났을때
                if (nx < 0 || nx >= h) continue;
                if (ny < 0 || ny >= w) continue;
                //이미 방문했거나 벽이 있을때
                if (dist1[nx][ny] != -1 || board[nx][ny] == '#') continue;

                q1.push({nx, ny});
                dist1[nx][ny] = dist1[x][y] + 1;
            }
        }

        //상근 bfs
        while (!q2.empty() && possible) { //탈출 예외처리!
            int x, y;
            tie(x, y) = q2.front();
            q2.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                //nx,ny가 범위를 벗어낫을때 탈출(상근이가 가장자리에 위치할때)
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    possible = false;
                    cout << (dist2[x][y] + 1) << "\n";
                    break;
                }
                //상근이가 이동할 수 없는 경우
                //nx,ny의 불이 더 빠를때, 불이 이미 방문한 경우,
                if (dist1[nx][ny] <= (dist2[x][y] + 1) && dist1[nx][ny] != -1) continue;
                //벽이 있거나, 상근이가 이미 방문 했거나
                if (board[nx][ny] == '#' || dist2[nx][ny] != -1) continue;

                q2.push({nx, ny});
                dist2[nx][ny] = dist2[x][y] + 1;
            }
        }
        if (possible) cout << "IMPOSSIBLE\n";

    } //테스트케이스 끝

}
//입출력 확인용
//        for (int i = 0; i < h; i++) {
//            for (int j = 0; j < w; j++) {
//                cout << board[i][j] << " ";
//            }
//            cout << "\n";
//        }