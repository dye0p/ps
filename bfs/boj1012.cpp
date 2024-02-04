//
// BOJ on 2024/01/29, 12:19 AM.
//
#include <bits/stdc++.h>

using namespace std;

int vis[51][51]; //방문 처리
int b[51][51]; //배추 위치
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n, k;

queue<pair<int, int> > q;

void bfs(int i, int j) {
    vis[i][j] = 1; //방문처리
    q.push({i, j});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] >= 1 || b[nx][ny] != 1) continue;

            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t; //Test_Case

    while (t--) {
        cin >> m >> n >> k; //가로, 세로, 위치개수

        //배추 입력
        int b1, b2;
        for (int i = 0; i < k; i++) {
            cin >> b1 >> b2;
            b[b2][b1] = 1; //배추 심기
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] >= 1 && vis[i][j] != 1) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";

        //배열 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = 0;
                vis[i][j] = 0;
            }
        }
    }
    return 0;
}
