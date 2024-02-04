#include <bits/stdc++.h>

using namespace std;

int n, m;
int dis[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<string> arr(n);

    // 입력 문제 없음
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        arr[i] = s;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    dis[0][0] = 1;
    //
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n) continue;
            if(ny < 0 || ny >= m) continue;
            if(dis[nx][ny] != 0) continue;
            if(arr[nx][ny] == '0') continue;

            q.push({nx, ny});
            dis[nx][ny] = dis[x][y] + 1;
        }
    }
    cout << dis[n-1][m-1];

    return 0;
}