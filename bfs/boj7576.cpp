#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[1001][1001]; //토마토
int dist[1001][1001]; //거리
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n) continue; //x가 n의 범위를 벗어나면 제외
            if (ny < 0 || ny >= m) continue; //y가 n의 범위를 벗어나면 제외
            //토마토가 1이 아니거나, 이동한 거리의 좌표값이 0이상이면 제외
            if (dist[nx][ny] >= 0 || board[nx][ny] != 0) continue;
            q.push({nx, ny}); //새로운 좌표를 큐에 삽입
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j]; //입력
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1) { //익은 토마토 발견
                q.push({i, j});
            }
            //0을 입력 받았을때 다른값으로 초기화 해주지않으면 기본 초기값이 0이므로
            // -1(토마토가 없는칸) 과 구별이 불가하기 때문에 안익은 토마토는 -1로 따로 초기화해준다
            if (board[i][j] == 0) {
                dist[i][j] = -1;
            }
        }
    }
    //bfs가 동시에 진행될수가 있음(1이 두개 있는경우)
    //동시에 진행될땐 큐에 삽입할때마다 bfs를 진행하면 동시에 진행할수가 없다
    //bfs를 시작할수있는 좌표(1이 존재하는 좌표)를 모두 스택에 추가한후 하나씩 pop을 해가면서 bfs를 수행한다.
    //1이 존재하는 좌표의 bfs를 순차적으로 진행할 수 있음
    bfs();

    //출력 부분
    //bfs가 끝난 후 안 익은 토마토가 남아있는 경우 -1 출력 후 프로그램 종료
    // ->dist배열에 -1이 있는경우(0을 입력받으면 dist에 -1을 저장하기로 했음)
    int low_dist = 0; //최소일자 변수
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1) { //안익은 토마토가 있다면
                cout << -1;
                return 0;
            } else
                low_dist = max(low_dist, dist[i][j]);
        }
    }
    cout << low_dist;
}

// 값 확인용 출력문
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << dist[i][j] << " ";
//        }
//        cout << '\n';
//    }

/*
 * 토마토 배열
토마토가 1이면 익은토마토
인접한 숫자가 0이면 이동가능
-1이면 이동불가

최소날짜 배열
우선 모두 0으로 초기화
0이 입력되면 -> 이동할 수 있는 좌표
-> -1로 초기화

안되는 조건
dist[nx][ny] 좌표의 값이 -1이면 이동가능
-1이 아니고 0이상이면 이동불가
board[nx][ny] 좌표의 값이 0이 아니면 이동불가 (-1이면 이동불가)

 * */

