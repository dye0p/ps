//
// BOJ on 2024/01/31, 9:22 AM.
//
#include <bits/stdc++.h>

using namespace std;

int board[502][502];
int vis[502][502];
int dx[4] = {1, 0, -1, 0}; //(하,우,상,좌) 순
int dy[4] = {0, 1, 0, -1}; //(하,우,상,좌) 순
int n, m, mx; //세로(행), 가로(열), 그림의 넓이
queue<pair<int, int> > q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j]; //그림 좌표 입력
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //bfs가능 상태(그림이면서 방문하지 않은상태)
            if (board[i][j] == 1 && vis[i][j] == 0) {
                q.push({i, j}); //시작점 큐에 삽입
                vis[i][j] = 1; //방문표시
                int ans = 0; //그림의 넓이
                ans++; //그림의 넓이 +1;
                cnt++; //그림의 갯수 +1;

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop(); //큐 제거

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;

                        q.push({nx, ny}); //인접한 새로운 좌표 삽입
                        vis[nx][ny] = 1; //새로운 좌표 방문처리
                        ans++; //그림 넓이 +1;
                    }
                }
                mx = max(mx, ans); //해당 그림(해당 bfs)을 다 탐색했으면 해당 그림의 넓이를 저장
            }
        }
    }

    cout << cnt << "\n" << mx;
}

