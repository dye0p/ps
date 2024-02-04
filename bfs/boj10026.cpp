//
// BOJ on 2024/01/29, 1:43 PM.
//
#include <bits/stdc++.h>

using namespace std;

string board[101]; //100개줄의 그림이들어갈 수 있음
int vis[101][101]; //가로세로의 길이가 100까지
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

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

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (vis[nx][ny] == 1 || board[nx][ny] != board[x][y]) continue;

            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int area() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 0) {
                bfs(i, j); //bfs시작
                cnt++; //bfs시작되면 ++1
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; //그림의 개수
    for (int i = 0; i < n; i++) { //색상 입력
        cin >> board[i]; //문자열 배열에 한줄씩 입력
    }
    int result1 = area(); // 보통사람의 결과값

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vis[i][j] = 0; //방문여부 초기화
        }
    }

    //한줄씩 문자열의 자릿수에 접근
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'G')
                board[i][j] = 'R';
        }
    }

    int result2 = area();
    cout << result1 << " " << result2;
}